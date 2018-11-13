/* 
 * udpserver.c - A simple UDP echo server 
 * usage: udpserver <port>
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

/*
 * error - wrapper for perror
 */
void error(char *msg)
{
	perror(msg);
	exit(1);
}

int main(int argc, char **argv)
{
	int sockfd;		/* socket */
	int portno;		/* port to listen on */
	int clientlen;		/* byte size of client's address */
	struct sockaddr_in serveraddr;	/* server's addr */
	struct sockaddr_in clientaddr;	/* client addr */
	struct hostent *hostp;	/* client host info */
	char *buf;		/* message buf */
	char *hostaddrp;	/* dotted decimal host addr string */
	int optval;		/* flag value for setsockopt */
	int n;			/* message byte size */

	
	portno = atoi("161");

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd < 0)
		error("ERROR opening socket");

	optval = 1;
	setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR,
		   (const void *)&optval, sizeof(int));

	bzero((char *)&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons((unsigned short)portno);

	if (bind(sockfd, (struct sockaddr *)&serveraddr,
		 sizeof(serveraddr)) < 0)
		error("ERROR on binding");

	memset(&clientaddr,0,sizeof(clientaddr));
	clientaddr.sin_family = AF_INET;
	clientlen = sizeof(clientaddr);
	while (1) {
		buf = malloc(BUFSIZE);
		n = recvfrom(sockfd, buf, BUFSIZE, 0,
			     (struct sockaddr *)&clientaddr, &clientlen);
		if (n < 0)
			error("ERROR in recvfrom");
		/* 
		 * gethostbyaddr: determine who sent the datagram
		 */
		hostp = gethostbyaddr((const char *)&clientaddr.sin_addr.s_addr,
				      sizeof(clientaddr.sin_addr.s_addr),
				      AF_INET);
		//if (hostp == NULL)
		//	error("ERROR on gethostbyaddr");

		hostaddrp = inet_ntoa(clientaddr.sin_addr);
		if (hostaddrp == NULL)
			error("ERROR on inet_ntoa\n");
		printf("server received %d bytes\n %s\n", n, buf);
		for(int i = 0;i < n; i++){
			printf("%x ", buf[i]);
			
		}
		printf(" \n ");
		/* 
		 * sendto: echo the input back to the client 
		 */
		 
		 const char c[] = {'0', '\x81', '\xad', '\x02', '\x01', '0', '\x04', '\x06', 'p', 'u', 'b', 'l', 'i', 'c', 'H', 'a', 'r', 'd', 'w', 'a', 'r', 'e', ':', ' ', 'I', 'n', 't', 'e', 'l', '6', '4', ' ', 'F', 'a', 'm', 'i', 'l', 'y', ' ', '6', ' ', 'M', 'o', 'd', 'e', 'l', ' ', '1', '5', '8', ' ', 'S', 't', 'e', 'p', 'p', 'i', 'n', 'g', ' ', '1', '0', ' ', 'A', 'T', '/', 'A', 'T', ' ', 'C', 'O', 'M', 'P', 'A', 'T', 'I', 'B', 'L', 'E', ' ', '-', ' ', 'S', 'o', 'f', 't', 'w', 'a', 'r', 'e', ':', ' ', 'W', 'i', 'n', 'd', 'o', 'w', 's', ' ', 'V', 'e', 'r', 's', 'i', 'o', 'n', ' ', '6', '.', '3', ' ', '(', 'B', 'u', 'i', 'l', 'd', ' ', '1', '7', '1', '3', '4', ' ', 'M', 'u', 'l', 't', 'i', 'p', 'r', 'o', 'c', 'e', 's', 's', 'o', 'r', ' ', 'F', 'r', 'e', 'e', ')' };
		 
		 std::string s(c);
		 printf("s.size() %d %s\n",s.size(),c);
		n = sendto(sockfd, c, s.size(), 0,
			   (struct sockaddr *)&clientaddr, clientlen);
		if (n < 0)
			error("ERROR in sendto");
		free(buf);
	}
}