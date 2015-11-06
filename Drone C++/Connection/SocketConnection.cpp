#include "SocketConnection.h"

SocketConnection::SocketConnection()
{
	Initialize();
}

SocketConnection::~SocketConnection() {
	closesocket(ConnectSocket);
	WSACleanup();
}

int SocketConnection::Initialize() {
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed with error: %d\n", iResult);
		return 1;
	}
}
