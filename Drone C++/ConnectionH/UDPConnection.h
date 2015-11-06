#ifndef UDPCONNECTION_H
#define UDPCONNECTION_H

#include "SocketConnection.h"

class UDPConnection : public SocketConnection {

public :
	UDPConnection();

private :
	sockaddr_in Addr;

	int sendDTGram();
	int recvDTGram();

};

#endif

