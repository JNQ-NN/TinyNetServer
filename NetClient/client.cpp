#include "client.h"

Client::Client(asio::io_context& ioc,string ip_address,int port):_ioc(ioc){
    auto endport = asio::ip::tcp::endpoint(asio::ip::address::from_string(ip_address),port);
    cout<<"Client Start."<<endl;
    cout<<"host:"<<endl;
    cout<<"address:"<<endport.address()<<endl;
    cout<<"port:"<<endport.port()<<endl;
    std::shared_ptr<Session> session = make_shared<Session>(_ioc,endport);
    session->start();
}


