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
    char readbuffer[300];
	struct sockaddr_in recvfromaddress;
	int size = sizeof(struct sockaddr);;
    bytesreceived = recvfrom(this->handler, readbuffer, sizeof(readbuffer), 0, (struct sockaddr *) &recvfromaddress,(socklen_t *) &size);
	
	if (bytesreceived ==0){
       this->buffer.clear();
	}
    else if(bytesreceived > 0)
    {
		this->buffer = "";
		bool result = false;
		for(int i = 0;i< bytesreceived;i++){
			if(result && readbuffer[i] != 0x00){
				this->buffer.push_back(readbuffer[i]);
			}
			result |= 0xffffff83 == readbuffer[i];	
		}
    }
    else
    {
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
					  
}
