#include <iostream>
#include <boost/asio.hpp>
using namespace std;
using namespace boost;
#include "session.h"

class Server{
public:
    Server(asio::io_context& ioc,int port);
    void start_accept();
    void handle_accept(const boost::system::error_code& error,std::shared_ptr<Session> session);
private:
    asio::io_context& _ioc;
    asio::ip::tcp::acceptor _acceptor;
};