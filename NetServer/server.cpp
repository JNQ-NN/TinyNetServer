#include "server.h"

Server::Server(asio::io_context& ioc,int port):_ioc(ioc),
_acceptor(ioc,asio::ip::tcp::endpoint(asio::ip::tcp::v4(),port)){
    cout<<"Server Start."<<endl;
    cout<<"local host:"<<endl;
    cout<<"address:"<<_acceptor.local_endpoint().address()<<endl;
    cout<<"port:"<<_acceptor.local_endpoint().port()<<endl;
    start_accept();
}

/*
 *@brief accept
*/
void Server::start_accept(){
    try{
        std::shared_ptr<Session> session = make_shared<Session>(_ioc);
        _acceptor.async_accept(session->getSocket(),std::bind(&Server::handle_accept,this,placeholders::_1,session));
    }catch(std::exception& e){
        cerr<<e.what()<<'\n';
    }
}

/*
 *@brief 异步accept回调函数
*/
void Server::handle_accept(const boost::system::error_code& error,std::shared_ptr<Session> session){
    if(error) return;
    cout<<"remote host:"<<endl;
    cout<<"address:"<<session->getSocket().remote_endpoint().address()<<endl;
    session->start();
    start_accept(); //循环accept
}