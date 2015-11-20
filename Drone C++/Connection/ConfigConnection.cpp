#include "../ConnectionH/ConfigConnection.h"

ConfigConnection::ConfigConnection() {
	addr = "192.168.1.1";
	port = 5559;
}

ConfigConnection::~ConfigConnection() {
	closesocket(ConnectSocket);
	WSACleanup();
}
