#include "Socket.h"
Socket::Socket()
{
	type=SOCK_STREAM;
	socketdc = socket(AF_INET, SOCK_DGRAM, 0);
}
Socket::Socket(char t, bool ipv6){
	if(t=='s'){
		type=SOCK_STREAM;
	}
	if(t=='d'){
		type=SOCK_DGRAM;
	}
	if(ipv6){
		domain=AF_INET6;
	}else{
		domain=AF_INET;
	}
	socketdc = socket(domain, type, 0);
	if(socketdc==-1)
		perror("\nOcurrio un error al crear el socket.\n");
}
int Socket::Connect(char * host, char *service){
	int st;
	struct addrinfo hints, *result, *rp;
	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_UNSPEC;	/* Allow IPv4 or IPv6 */
	hints.ai_socktype = SOCK_DGRAM; /* Datagram socket */
	hints.ai_flags = 0;
	hints.ai_protocol = 0;
	if((st = getaddrinfo(host, service, &hints, &result))<0){
		perror("\nError con getaddrinfo(...).\n");
	}
	for ( rp = result; rp; rp = rp->ai_next ) {
	   
		st = connect( socketdc, rp->ai_addr, rp->ai_addrlen );
		if(st<0)
			perror("\nError con connect(...).\n");
		if ( 0 == st )
			break;
	}
	freeaddrinfo( result );
	if(st==-1)
		perror("\nOcurrio un error al conectar el socket.\n");
	return st;
}
int Socket::Connect(char * host, int Port){
	struct sockaddr_in host_addr;
	host_addr.sin_family = AF_INET;
	inet_aton( host,  &host_addr.sin_addr );
	host_addr.sin_port = htons( Port );
	int result=connect(socketdc, (sockaddr *) & host_addr,sizeof( host_addr ));
	if(result==-1)
		perror("\nOcurrio un error al conectar el socket.\n");
	return result;
}
int Socket::Read(char * text, int len){
	int result=read(socketdc,text,len);
	if(result==-1)
		perror("\nOcurrio un error al hacer la lectura.\n");

	return result;
}
int Socket::Write(char * text, int len){
	int result=write(socketdc,text,len);
	if(result==-1)
		perror("\nOcurrio un error al escribir el mensaje.\n");
	return result;
}
int Socket::Shutdown(int type){
	int result=shutdown(socketdc,type);
	if(result==-1)
		perror("\nOcurrio un error cerrar el socket.\n");
	return result;
}
int Socket::Close(){
	int result=close(socketdc);
	if(result==-1)
		perror("\nOcurrio un error al conectar el socket.\n");
	return result;
}
int Socket::Listen(int Queue){
	int result=listen(socketdc,Queue);
	if(result==-1)
		perror("\nOcurrio un error al escuchar solicitudes.\n");
	return result;
}
int Socket::Bind(int Port){
	port=Port;
	struct sockaddr_in server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl( INADDR_ANY );
	server_addr.sin_port = htons(port);
	int result=bind( socketdc, (sockaddr *) & server_addr, sizeof( server_addr ));
	if(result==-1)
		perror("\nOcurrio un error con bind(...).\n");
	return result;
}
Socket* Socket::Accept(){
	struct sockaddr clientaddress;
	Socket* socket= new Socket();
	socklen_t len=sizeof( clientaddress );
	socket->socketdc= accept(socketdc, &clientaddress, &len);
	if(socket->socketdc==-1)
		perror("\nOcurrio un error al conectar el socket.\n");
	return socket;
}
Socket::~Socket(){
}
