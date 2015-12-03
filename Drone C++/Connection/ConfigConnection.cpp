#include "../ConnectionH/ConfigConnection.h"

namespace connection {
	ConfigConnection::ConfigConnection() {
		addr = "192.168.1.1";
		port = 5559;
	}

	ConfigConnection::~ConfigConnection() {
		closesocket(ConnectSocket);
		WSACleanup();
	}
}