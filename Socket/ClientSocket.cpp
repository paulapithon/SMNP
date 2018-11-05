//
// Created by calazans on 04/11/18.
//

#include <cstring>
#include "ClientSocket.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <libsnmp.h>


void ClientSocket::initialize() {

    if(this->handler)
    {
        struct sockaddr_in serv_addr;
        memset(&serv_addr, '0', sizeof(serv_addr));

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(this->port_);
        if(inet_pton(AF_INET, this->ip_.c_str(), &serv_addr.sin_addr)<=0){
            printf("\nInvalid address/ Address not supported \n"); };

        if (connect(this->handler, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
            printf("erro na conecção");
        };
    }
}

const std::string ClientSocket::getMessage()
{
    return Socket::getMessage(this->handler);
}

void ClientSocket::sendMessage(const std::string& message)
{
    Socket::sendMessage(message,this->handler);
}
