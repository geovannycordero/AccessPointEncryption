#ifndef SOCKET_H
#define SOCKET_H

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
class Socket
{
	private:
		int socketdc;
		int domain;
		int type;
		int connection;
		int port;

	public:
		Socket();
		Socket(char t, bool ipv6);
		int Connect(char * host, char *service);
		int Connect(char * host, int Port);
		int Read(char * text, int len);
		int Write(char * text, int len);
		int Shutdown(int type);
		int Close();
		int Listen(int Queue);
		int Bind(int Port);
		Socket* Accept();
		~Socket();
};

#endif
