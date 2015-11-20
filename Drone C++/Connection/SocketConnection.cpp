#include "../ConnectionH/SocketConnection.h"

SocketConnection::SocketConnection()
{
	Initialize();
}

SocketConnection::~SocketConnection() {}

int SocketConnection::Initialize() {
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed with error: %d\n", iResult);
		return 1;
	}
	return 0;
}
