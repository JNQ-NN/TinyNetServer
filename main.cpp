#include <iostream>
#include <unistd.h>
#include <sys/utsname.h>
int main()
{
    struct utsname unameData;
    if (uname(&unameData) != 0) {
        std::cerr << "Failed to get system information." << std::endl;
        return 1;
    }
    
    std::cout << "Current C++ Standard: " << __cplusplus << std::endl;
    std::cout << "Operating system: " << unameData.sysname << std::endl;
    std::cout << "Node name: " << unameData.nodename << std::endl;
    std::cout << "Release: " << unameData.release << std::endl;
    std::cout << "Version: " << unameData.version << std::endl;
    std::cout << "Machine: " << unameData.machine << std::endl;
    std::cout<<"中文"<<std::endl;

    return 0;
}