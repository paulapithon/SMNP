//
// Created by Pichau on 08/11/2018.
//

#include "DatagramSocket.h"
#include <cstring>
#include <errno.h>

DatagramSocket::DatagramSocket(const std::string& ip,int port):Socket(ip,port ,SOCK_DGRAM)
{
}
void DatagramSocket::initialize() {

    if(this->handler)
    {
        address.sin_addr.s_addr = INADDR_ANY;

        address.sin_family = AF_INET;
        address.sin_port = htons(this->port_);

        if(bind(this->handler, (struct sockaddr*)&address,sizeof(address)) <0){
            printf("bind failed\n");
        };
    }
}

const std::string DatagramSocket::getMessage()
{
    len = 0;
    int n;
    char buffer[500];
    memset(&(this->cliaddr), 0, sizeof(this->cliaddr));


    fd_set set;
    struct timeval timeout;
    FD_ZERO(&set); /* clear the set */
    FD_SET(this->handler, &set); /* add our file descriptor to the set */
    timeout.tv_sec = 120;
    timeout.tv_usec = 0;
    int rv;
    do {
        rv = select(this->handler, &set, NULL, NULL, &timeout);
        printf("%d\n",rv);
        if (rv >= 0) {
            break;
        } else {
            n = recvfrom(this->handler, buffer, 500,
                         MSG_WAITALL, (struct sockaddr *) &(this->cliaddr),
                         &len);
        }
        printf("%d\n",n);
    }while(n < 0);
    if(n >= 0)
    {
        buffer[n] = '\0';
        this->buffer = std::string(buffer);

    }
    else
    {
       this->buffer.clear();
    }
    return this->buffer;
}

void DatagramSocket::sendMessage(const std::string& message)
{
    printf("%d, %s12\n",this->handler,message.c_str());
    sendto(this->handler, message.c_str(), message.length(),
           MSG_CONFIRM, (const struct sockaddr *) &(this->cliaddr),
           len);
}
