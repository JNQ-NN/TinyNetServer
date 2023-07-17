#include "server_session.h"

Session::Session(asio::io_context& ioc):_socket(ioc){
    _bufferReceive = new char[Msg_Length];
    _bufferSend = new char[Msg_Length];
}

Session::~Session(){
    if(_bufferReceive!=nullptr){
        delete _bufferReceive;
        _bufferReceive = nullptr;
    }
     if(_bufferSend!=nullptr){
        delete _bufferSend;
        _bufferSend = nullptr;
    }
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
        memset(_bufferReceive,' ',Msg_Length);
        _socket.async_receive(asio::buffer(_bufferReceive,Msg_Length),
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
        cout<<"Msg:"<<_bufferReceive<<endl;
        memset(_bufferSend,' ',Msg_Length);
        memcpy(_bufferSend,_bufferReceive,Msg_Length);
        _socket.async_send(asio::buffer(_bufferSend,Msg_Length),
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