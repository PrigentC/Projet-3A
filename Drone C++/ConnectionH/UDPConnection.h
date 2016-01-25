#ifndef UDPCONNECTION_H
#define UDPCONNECTION_H

#include "SocketConnection.h"

namespace connection {
	class UDPConnection : public SocketConnection {

	public:
		UDPConnection();

		int createUDPSocket();
		int connectUDPServer();
		int sendDTGram();
		int recvDTGram();

	protected:
		sockaddr_in SendToAddr;

	};
}


#endif

