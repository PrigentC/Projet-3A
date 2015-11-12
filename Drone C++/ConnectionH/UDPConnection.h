#ifndef UDPCONNECTION_H
#define UDPCONNECTION_H

#include "SocketConnection.h"

class UDPConnection : public SocketConnection {

public :
	UDPConnection();

	int createUDPSocket();
	int bindUDPSocket();
	int sendDTGram();
	int recvDTGram();

protected :
	sockaddr_in Addr;

};

#endif

