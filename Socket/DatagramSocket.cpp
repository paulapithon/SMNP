//
// Created by Pichau on 08/11/2018.
//

#include "DatagramSocket.h"
#include <cstring>
#include <errno.h>
#include <netdb.h>
#include <arpa/inet.h>

DatagramSocket::DatagramSocket(const std::string& ip,int port,bool server):Socket(ip,port ,SOCK_DGRAM)
{
   // if(server)
    {
        struct hostent* hostentp;
        hostentp = gethostbyname(this->ip_.c_str());
        memcpy(&(this->cliaddr.sin_addr.s_addr), hostentp->h_addr_list[0],sizeof(struct in_addr));
        this->cliaddr.sin_family = AF_INET;
        this->cliaddr.sin_port = htons(port);
        initialize();
    }
}
void DatagramSocket::initialize() {

    if(this->handler)
    {
        struct hostent* hostentp;

        hostentp = gethostbyname(this->ip_.c_str());
        memcpy(&address.sin_addr.s_addr, hostentp->h_name,sizeof(struct in_addr));
        address.sin_family = AF_INET;
        address.sin_port = htons(this->port_);
    }
}

const std::string DatagramSocket::getMessage()
{
    len = 0;
    int n;
    char buffer[500];

    fd_set set;
    struct timeval timeout;
    FD_ZERO(&set); /* clear the set */
    FD_SET(this->handler, &set); /* add our file descriptor to the set */
    timeout.tv_sec = 120;
    timeout.tv_usec = 0;
    int rv;
    do {
        printf("Hey\n");
        rv = select(this->handler, &set, NULL, NULL, &timeout);
        printf("Hey\n");
        if (rv <= 0) {
            break;
        } else {
            n = recv(this->handler, buffer, 500,
                         MSG_WAITALL);
            printf("server received %d bytes\n", n);
        }
    }while(n < 0);
    if(n >= 0)
    {
        buffer[n] = '\0';
        this->buffer = std::string(buffer);

    }
    else
    {
        printf("Time up!\n");
       this->buffer.clear();
    }
    return this->buffer;
}

void DatagramSocket::sendMessage(const std::string& message)
{
    int num_sent;
    const char* str =  message.c_str();
    num_sent = sendto(this->handler, /* socket */
                      str , /* buffer to send */
                      strlen(str), /* number of bytes to send */
                      0, /* flags=0: bare−bones use case*/
                      (const struct sockaddr*)&cliaddr, /* the destination */
                      sizeof(cliaddr)); /* size of the destination struct */
}
