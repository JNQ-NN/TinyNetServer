#include <iostream>
#include <boost/asio.hpp>
using namespace std;
using namespace boost;

class Session{
public:
    Session(asio::io_context& ioc,asio::ip::tcp::endpoint);
    ~Session();
    void start();
    void handle_send();
    void handle_receive();
private:
    asio::ip::tcp::socket _socket;
    enum{ Msg_Length = 0xFF };
};