#ifndef CLIENTCONNECTION_H
#define CLIENTCONNECTION_H

#include "STDEXCPT.h"

#include <iostream>
#include <string>
#include <winsock2.h>
#include <WS2tcpip.h>

class ClientConnection {
public :
	SOCKET ConnectSocket = INVALID_SOCKET;

	/* Constructor and destructor */
	ClientConnection();
	~ClientConnection();
	
	/* Methods */
	void NavdataConnection();
	void ATCommandsConnection();
	void VideoConnection();
	void ControlPortConnection();

	void TestClientConnection();

private :
	/* Members */
	const std::string adresse = "10.78.0.16";
	std::string port;

	WSADATA data;

	struct addrinfo	*result = NULL, *ptr = NULL, hints;

	/* Methods */
	void Initialize();
	void CreateClientSocket();
	void ConnectServer();
};

#endif
