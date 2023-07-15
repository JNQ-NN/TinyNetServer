file(GLOB ALL_SOURCE *.cpp *.c)
file(GLOB ALL_HEAD *.hpp *.h)
add_executable(NetClient ${ALL_SOURCE} ${ALL_HEAD})
                
if(CMAKE_HOST_SYSTEM MATCHES "Linux")
    target_link_libraries(NetClient Threads::Threads)
elseif(CMAKE_HOST_SYSTEM MATCHES "Windows")
    if(MINGW) 
        target_link_libraries(NetClient ws2_32 mswsock)
    endif() 
endif() 

