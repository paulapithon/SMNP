//
// Created by calazans on 04/11/18.
//

#include "Socket.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MESSAGE_SIZE 1024

Socket::Socket(const std::string& ip, const short port):ip_(ip),port_(port) {
    this->handler = socket(AF_INET, SOCK_STREAM, 0);
}

const std::string Socket::getMessage(int socket)
{
    char buffer[MESSAGE_SIZE] = "";
    read( socket , buffer, MESSAGE_SIZE);
    std::string rValue(buffer);
    return rValue;
}

void Socket::sendMessage(const std::string& message,int socket)
{
    send(socket , message.c_str(), message.size() , 0 );
}
