//
// Created by calazans on 04/11/18.
//

#ifndef UNTITLED1_SOCKET_H
#define UNTITLED1_SOCKET_H

#include <string>
#include <netinet/in.h>

class Socket {
protected:
    int handler;
    int opt;
    const std::string ip_;
    const short port_;
    struct sockaddr_in address;
public:
    Socket(const std::string& ip,const short port);
    const std::string getMessage(int socket);
    void sendMessage(const std::string& message,int socket);
};


#endif //UNTITLED1_SOCKET_H
