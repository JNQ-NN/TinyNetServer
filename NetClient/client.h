#include <iostream>
#include <boost/asio.hpp>
using namespace std;
using namespace boost;
#include "client_session.h"

class Client{
public:
    Client(asio::io_context& ioc,string ip_address,int port);
private:
    asio::io_context& _ioc;
};