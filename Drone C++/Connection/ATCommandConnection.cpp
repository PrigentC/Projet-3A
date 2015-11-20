#include "../ConnectionH/ATCommandConnection.h"

AtCommandConnection::AtCommandConnection() {
	SendToAddr.sin_port = htons(5556);
	SendToAddr.sin_addr.s_addr = inet_addr("192.168.1.1");

	RecvFromAddr.sin_port = htons(5556);
	RecvFromAddr.sin_addr.s_addr = inet_addr("192.168.1.2");
	
	addr = "192.168.1.1";
	port = 5556;
}

AtCommandConnection::~AtCommandConnection() {
	closesocket(ConnectSocket);
	WSACleanup();
}
