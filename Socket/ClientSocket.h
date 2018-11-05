//
// Created by calazans on 04/11/18.
//

#ifndef UNTITLED1_CLIENTSOCKET_H
#define UNTITLED1_CLIENTSOCKET_H


#include <string>
#include "Socket.h"

class ClientSocket : public Socket {
private:
    void initialize();
public:
    ClientSocket(const std::string& ip, short port):Socket(ip,port) {
        initialize();
    }

    const std::string getMessage();
    void sendMessage(const std::string& message);

};


#endif //UNTITLED1_CLIENTSOCKET_H
