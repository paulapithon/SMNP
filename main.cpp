#include <iostream>
#include "Socket/ServerSocket.h"
#include "Socket/ClientSocket.h"

int server() {
    ServerSocket s("127.0.0.1",8080);
    s.acceptSocket();
    printf("%s\n",s.getMessage().c_str());
    s.sendMessage("Hi from the server");
    return 0;
}
int client() {
    ClientSocket  s("127.0.0.1",8080);

    s.sendMessage("Hello, from the client");
    printf("%s\n",s.getMessage().c_str());
    return 0;
}
int main1() {
#ifdef Client
    return client();
#else
    return server();
#endif
}