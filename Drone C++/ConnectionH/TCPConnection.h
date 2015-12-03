#ifndef TCPCONNECTION_H
#define TCPCONNECTION_H

#include "SocketConnection.h"

namespace connection {
	class TCPConnection : public SocketConnection {

	public:
		TCPConnection();

	private:
		struct addrinfo *result = NULL,
			*ptr = NULL,
			hints;


		int createTCPSocket();
		int connectTCPServer();
		int sendSockStream();
		int recvSockStream();

	};
}

#endif
