#ifndef SOCKETCONNECTION_H
#define SOCKETCONNECTION_H

#include "STDEXCPT.h"

#include "../DroneConstants.h"
#include "../BufferH/ByteBuffer.h"

#include <iostream>
#include <string>
#include <winsock2.h>
#include <WS2tcpip.h>

class SocketConnection {
public :
	SocketConnection();
	~SocketConnection();

	ByteBuffer SendBuff;
	ByteBuffer RecvBuff;
	int iResult;

protected:
	WSADATA wsaData;
	SOCKET ConnectSocket = INVALID_SOCKET;
	std::string addr;
	std::string port;

private :
	int Initialize();

};

#endif