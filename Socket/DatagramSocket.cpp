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
    int bytesreceived;
    unsigned short readbuffer[2];
	struct sockaddr_in recvfromaddress;
	int size = sizeof(struct sockaddr);;
	//memset((void*) &address, 0, addr_len);
    do {
		
		//addr_len = sizeof(address);
        printf("sent %d bytes to %s\n",48,inet_ntoa(cliaddr.sin_addr));
        bytesreceived = recvfrom(this->handler, readbuffer, sizeof(readbuffer), 0, (struct sockaddr *) &recvfromaddress, &size);
         if(bytesreceived != sizeof(unsigned short) || size != sizeof(struct sockaddr) || readbuffer[0] != (unsigned short) this->cliaddr.sin_port || recvfromaddress.sin_family != this->cliaddr.sin_family || recvfromaddress.sin_port != this->cliaddr.sin_port)
		
		printf("server received %d %s bytes\n", bytesreceived,buffer);
    }while(bytesreceived > 0);
	if (bytesreceived ==0){
		 printf("Oh dear, something went wrong with read()! %s\n", strerror(errno));
       this->buffer.clear();
	}
    else if(bytesreceived > 0)
    {
        this->buffer = std::string(buffer);
    }
    else
    {
	  printf("Oh dear, something went wrong with read()! %s\n", strerror(errno));
       this->buffer.clear();
    }
    return this->buffer;
}

void DatagramSocket::sendMessage(const char* message, int len)
{
    int num_sent = sendto(this->handler, /* socket */
                      message , /* buffer to send */
                      len, /* number of bytes to send */
                      0, /* flags=0: bare−bones use case*/
                      (const struct sockaddr*)&cliaddr, /* the destination */
                      sizeof(cliaddr)); /* size of the destination struct */
					  printf("%d = %d\n",num_sent,len);
					  
}
