#include <iostream>
#include <boost/asio.hpp>
using namespace std;
using namespace boost;
#include "server.h"
int main(){
    asio::io_context ioc;
    Server s(ioc,6666);
    ioc.run();
}