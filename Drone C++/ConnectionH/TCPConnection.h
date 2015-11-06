#ifndef TCPCONNECTION_H
#define TCPCONNECTION_H

#include "SocketConnection.h"

class TCPConnection : public SocketConnection {

public:
	TCPConnection();

private:
	struct addrinfo *result = NULL,
		*ptr = NULL,
		hints;

	int sendSockStream();

};

#endif
