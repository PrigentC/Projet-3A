#ifndef UDPCONNECTION_H
#define UDPCONNECTION_H

#include "SocketConnection.h"

class UDPConnection : public SocketConnection {

public :
	UDPConnection();

private :
	sockaddr_in RecvAddr;

	int sendDTGram();

};

#endif

