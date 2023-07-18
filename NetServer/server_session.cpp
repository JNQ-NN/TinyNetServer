#include "server_session.h"

MsgNode::MsgNode(int msgMaxLen):_msgMaxLen(msgMaxLen){
    _msg = new char[_msgMaxLen];
    memset(_msg,' ',_msgMaxLen);
}

MsgNode::MsgNode(const char* msg,int msgMaxLen):_msgMaxLen(msgMaxLen){
    _msg = new char[_msgMaxLen];
    memcpy(_msg,msg,_msgMaxLen);
}

MsgNode::~MsgNode(){
    delete[] _msg;
}

char* MsgNode::getMsg(){
    return _msg;
}

void MsgNode::msgCopy(std::shared_ptr<MsgNode> sp){
    memcpy(_msg,sp->_msg,_msgMaxLen);
}

void MsgNode::msgClear(){
    memset(_msg,' ',_msgMaxLen);
}

int MsgNode::getMaxLen(){
    return _msgMaxLen;
}

Session::Session(asio::io_context& ioc):_socket(ioc){
    _msgNodeRecv = make_shared<MsgNode>(Msg_Length);
    //_msgNodeSend = make_shared<MsgNode>(Msg_Length);
}

Session::~Session(){
    _socket.close();
}

asio::ip::tcp::socket& Session::getSocket(){
    return _socket;
}

/*
 *@brief 处理IO事件
*/
void Session::start(){
    try{
        _msgNodeRecv->msgClear();
        _socket.async_receive(asio::buffer(_msgNodeRecv->getMsg(),_msgNodeRecv->getMaxLen()),
        std::bind(&Session::handle_recv,shared_from_this(),placeholders::_1));  
        /*问题：error_code:system 125 - Operation Cancelled
            对于指针指针维护的类，在调用this时，应该继承std::enable_shared_from_this<>类
            通过函数shared_from_this()获得智能指针的this
            使用普通this，会使socket失效，从而造成Operation Cancelled
        */
    }catch(const std::exception& e){
        std::cerr<<e.what()<<'\n';
    }
}

/*
 *@brief //双工异步发送接口
*/
void Session::send(const char* msg,int msgMaxLen){
    std::lock_guard<mutex> lg(_mxSend);
    _msgSendQueue.push(make_shared<MsgNode>(msg,msgMaxLen));
    if(_msgSendQueue.size()==1){
        _socket.async_send(asio::buffer(_msgSendQueue.front()->getMsg(),_msgSendQueue.front()->getMaxLen()),
        std::bind(&Session::handle_send,shared_from_this(),placeholders::_1));
    }else{
        return;
    }
}

/*
 *@brief 处理读事件
*/
void Session::handle_recv(const boost::system::error_code& error){
    if(error) return;
    try{
        cout<<"Msg:"<<_msgNodeRecv->getMsg()<<endl;
        send(_msgNodeRecv->getMsg(),_msgNodeRecv->getMaxLen());
        _msgNodeRecv->msgClear();
        _socket.async_receive(asio::buffer(_msgNodeRecv->getMsg(),_msgNodeRecv->getMaxLen()),
        std::bind(&Session::handle_recv,shared_from_this(),placeholders::_1));  
    }catch(const std::exception& e){
        std::cerr<<e.what()<<'\n';
    }
}

/*
 *@brief 处理写事件
*/
void Session::handle_send(const boost::system::error_code& error){
    if(error) return;
    try{
        std::lock_guard<mutex> lg(_mxSend);
        _msgSendQueue.pop();
        if(!_msgSendQueue.empty()){
            _socket.async_send(asio::buffer(_msgSendQueue.front()->getMsg(),_msgSendQueue.front()->getMaxLen()),
            std::bind(&Session::handle_send,shared_from_this(),placeholders::_1));
        }
    }catch(const std::exception& e){
        std::cerr<<e.what()<<'\n';
    }
}