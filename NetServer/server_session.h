#include <iostream>
#include <boost/asio.hpp>
#include <memory>
#include <thread>
#include <queue>
using namespace std;
using namespace boost;

class MsgNode{
public:
    MsgNode(int msgMaxLen);
    MsgNode(const char* msg,int msgMaxLen);
    ~MsgNode();
    char* getMsg();
    void msgCopy(std::shared_ptr<MsgNode> sp);
    void msgClear();
    int getMaxLen();
private:
    char* _msg;  //维护msg内容 & msg地址
    int _msgMaxLen; 
    int _msgCurLen;
};

/*
 *@brief 管理scoket & IO事件
*/
class Session:public std::enable_shared_from_this<Session>{
public:
    Session(asio::io_context& ioc);
    ~Session();
    asio::ip::tcp::socket& getSocket();
    void start();
    void send(const char* msg,int msgMaxLen);    //双工异步发送接口
    void handle_recv(const boost::system::error_code& error);
    void handle_send(const boost::system::error_code& error);
private:
    asio::ip::tcp::socket _socket;
    std::shared_ptr<MsgNode> _msgNodeRecv;  
    queue<std::shared_ptr<MsgNode>> _msgSendQueue;   //消息发送队列
    mutex _mxSend;
    enum{ Msg_Length = 0xFF };
};