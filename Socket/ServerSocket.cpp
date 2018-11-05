//
// Created by calazans on 04/11/18.
//

#include "ServerSocket.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

#define MESSAGE_SIZE 1024

ServerSocket::ServerSocket(const std::string& ip,int port):Socket(ip,port)
{
    initialize();
   if( listen(this->handler, 3) < 0)
       printf("listening\n");
}
void ServerSocket::initialize() {

    if(this->handler)
    {

        address.sin_addr.s_addr = INADDR_ANY;

        address.sin_family = AF_INET;
        address.sin_port = htons(this->port_);

        if(setsockopt(this->handler, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
            printf("setsockopt\n");
        };

        if(bind(this->handler, (struct sockaddr*)&address,sizeof(address)) <0){
            printf("bind failed\n");
        };
    }
}

void ServerSocket::acceptSocket()
{
    socklen_t size = sizeof(this->address);

    if((this->acceptedSocket = accept(this->handler,
                                  (struct sockaddr *)&this->address,
                                  &size))<=0){
        printf("deu boste\n");
    };
}

const std::string ServerSocket::getMessage()
{
    return Socket::getMessage(this->acceptedSocket);
}

void ServerSocket::sendMessage(const std::string& message)
{
    Socket::sendMessage(message,this->acceptedSocket);
}
