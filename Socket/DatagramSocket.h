//
// Created by Pichau on 08/11/2018.
//

#ifndef CLIENT_DATAGRAMSOCKET_H
#define CLIENT_DATAGRAMSOCKET_H

#include <string>
#include "Socket.h"

class DatagramSocket : Socket {
private:
    std::string buffer;
    struct sockaddr_in cliaddr;
    unsigned int len;
    int acceptedSocket;
    void initialize();
public:
    DatagramSocket(const std::string& ip,int port);

    const std::string getMessage();
    void sendMessage(const std::string& message);

};


#endif //CLIENT_DATAGRAMSOCKET_H