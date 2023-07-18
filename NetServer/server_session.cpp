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
    _msgNodeReceive = make_shared<MsgNode>(Msg_Length);
    _msgNodeSend = make_shared<MsgNode>(Msg_Length);
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
        _msgNodeReceive->msgClear();
        _socket.async_receive(asio::buffer(_msgNodeReceive->getMsg(),_msgNodeReceive->getMaxLen()),
        std::bind(&Session::handle_receive,shared_from_this(),placeholders::_1));  
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
 *@brief 处理读事件
*/
void Session::handle_receive(const boost::system::error_code& error){
    if(error) return;
    try{
        cout<<"Msg:"<<_msgNodeReceive->getMsg()<<endl;
        _msgNodeSend->msgCopy(_msgNodeReceive);
        _socket.async_send(asio::buffer(_msgNodeSend->getMsg(),_msgNodeSend->getMaxLen()),
        bind(&Session::handle_send,shared_from_this(),placeholders::_1));
    }catch(const std::exception& e){
        std::cerr<<e.what()<<'\n';
    }
}

/*
 *@brief 处理写事件
*/
void Session::handle_send(const boost::system::error_code& error){
    if(error) return;
    start();  //循环执行读取事件
}