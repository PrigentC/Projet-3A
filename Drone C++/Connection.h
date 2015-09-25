#ifndef CONNECTION_H
#define CONNECTION_H

#include "STDEXCPT.h"

#include <iostream>
#include <string>
#include <winsock2.h>
#include <WS2tcpip.h>

class Connection {
public :
	/* Constructor and destructor */
	Connection();
	~Connection();
	
	/* Methods */
	void NavdataConnection();
	void ATCommandsConnection();
	void VideoConnection();
	void ControlPortConnection();

private :
	/* Members */
	const std::string adresse = "192.168.1.1";
	std::string port;

	WSADATA data;

	struct addrinfo	*result = NULL, *ptr = NULL, hints;

	SOCKET ConnectSocket = INVALID_SOCKET;

	/* Methods */
	void Initialize();
	void CreateSocket();
	void ConnectServer();
};

#endif
