#ifndef SOCKETCONNECTION_H
#define SOCKETCONNECTION_H

#include "STDEXCPT.h"

#include "../DroneConstants.h"
#include "../BufferH/ByteBuffer.h"
#include "AbstractSocket.h"

#include <iostream>
#include <string>
#include <winsock2.h>
#include <WS2tcpip.h>

using namespace buffer;

namespace connection {
	class SocketConnection : public AbstractSocket {
	public:
		SocketConnection();
		~SocketConnection();

		ByteBuffer SendBuff;
		ByteBuffer RecvBuff;
		int iResult;

	protected:
		WSADATA wsaData;
		SOCKET ConnectSocket = INVALID_SOCKET;
		char* addr = "127.0.0.1";
		u_short port = 7777;

	private:
		int Initialize();

	};
}

#endif