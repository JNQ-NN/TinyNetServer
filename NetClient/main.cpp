#include <iostream>
#include <boost/asio.hpp>
using namespace std;
using namespace boost;
#include "client.h"
int main(){
    asio::io_context ioc;
    Client client(ioc,"111.231.12.131",6666);
    ioc.run();

}