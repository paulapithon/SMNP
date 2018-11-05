//
// Created by calazans on 04/11/18.
//

#ifndef UNTITLED1_SERVERSOCKET_H
#define UNTITLED1_SERVERSOCKET_H


#include <string>
#include "Socket.h"

class ServerSocket : public Socket {
private:
    int acceptedSocket;
    void initialize();
public:
    ServerSocket(const std::string& ip,int port);
    void acceptSocket();

    const std::string getMessage();
    void sendMessage(const std::string& message);

};


#endif //UNTITLED1_SERVERSOCKET_H
