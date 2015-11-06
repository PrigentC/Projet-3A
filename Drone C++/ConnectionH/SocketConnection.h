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

protected:
	WSADATA wsaData;
	SOCKET ConnectSocket = INVALID_SOCKET;
	ByteBuffer SendBuff;
	ByteBuffer RecvBuff;
	std::string addr;
	std::string port;
	int iResult;

private :
	int Initialize();

};

#endif