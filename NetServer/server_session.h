#include <iostream>
#include <boost/asio.hpp>
#include <memory>
using namespace std;
using namespace boost;

/*
 *@brief 管理scoket & IO事件
*/
class Session:public std::enable_shared_from_this<Session>{
public:
    Session(asio::io_context& ioc);
    ~Session();
    asio::ip::tcp::socket& getSocket();
    void start();
    void handle_receive(const boost::system::error_code& error);
    void handle_send(const boost::system::error_code& error);
private:
    asio::ip::tcp::socket _socket;
    char* _bufferReceive;
    char* _bufferSend;
    enum{ Msg_Length = 0xFF };
};