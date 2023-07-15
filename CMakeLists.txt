cmake_minimum_required(VERSION 3.0.0)
project(AsioServer VERSION 0.1.0 LANGUAGES C CXX)

#外部库
if(CMAKE_HOST_SYSTEM MATCHES "Linux")        #linux
    message("current platform Linux")
    find_package(Boost 1.82.0 REQUIRED)  
    #pthread库
    find_package(Threads REQUIRED)
    set(THREADS_PREFER_PTHREAD_FLAG ON)
elseif(CMAKE_HOST_SYSTEM MATCHES "Windows")  #windows
    message("current platform Windows")
    cmake_policy(SET CMP0074 NEW)
    message($ENV{BOOST_ROOT})  #静态库路径 通过系统环境变量配置
    set(BOOST_LIBRARY_DIRS $ENV{BOOST_ROOT}\\lib)
    message(${BOOST_LIBRARY_DIRS})
    find_package(Boost 1.82 REQUIRED)
    link_directories(${Boost_LIBRARY_DIRS})
    include_directories(include  ${Boost_INCLUDE_DIRS} ${catkin_INCLUDE_DIRS})
endif()

#可执行文件
add_executable(TinyNetServer main.cpp)
add_subdirectory(NetServer)
add_subdirectory(NetClient)


if(CMAKE_HOST_SYSTEM MATCHES "Linux")
    target_link_libraries(TinyNetServer Threads::Threads)
        #Threads解决Linux系统pthread的兼容性问题
elseif(CMAKE_HOST_SYSTEM MATCHES "Windows")
    if(MINGW)
        target_link_libraries(TinyNetServer ws2_32 mswsock)
        # ws2_32 解决Boost在posix的兼容性问题
        # mswsock 解决asio套接字的兼容性问题
    endif()
endif()