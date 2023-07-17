#include "client_session.h"

Session::Session(asio::io_context& ioc,asio::ip::tcp::endpoint endpoint):_socket(ioc){
    _socket.connect(endpoint);
    start();
}

Session::~Session(){
    _socket.close();
}

/*
 *@brief 处理IO事件
*/
void Session::start(){
    handle_send();
    handle_receive();
}

void Session::handle_send(){
    char* buff = new char[Msg_Length];
    memset(buff,' ',Msg_Length);
    cin.get(buff,Msg_Length);
    _socket.send(asio::buffer(buff,Msg_Length));
    delete[] buff;
}

void Session::handle_receive(){
    char* buff = new char[Msg_Length];
    memset(buff,' ',Msg_Length);
    _socket.receive(asio::buffer(buff,Msg_Length));
    cout<<buff<<endl;
    delete[] buff;
}