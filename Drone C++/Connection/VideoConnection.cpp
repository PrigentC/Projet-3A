#include "..\ConnectionH\VideoConnection.h"

VideoConnection::VideoConnection() {
	SendToAddr.sin_port = htons(5555);
	SendToAddr.sin_addr.s_addr = inet_addr("192.168.1.1");

	RecvFromAddr.sin_port = htons(5555);
	RecvFromAddr.sin_addr.s_addr = inet_addr("192.168.1.1");

	addr = "192.168.1.1";
	port = 5555;
}

VideoConnection::~VideoConnection() {
	closesocket(ConnectSocket);
	WSACleanup();
}
