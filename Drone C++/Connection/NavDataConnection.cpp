#include "../ConnectionH/NavDataConnection.h"

namespace connection {
	NavDataConnection::NavDataConnection() {
		SendToAddr.sin_port = htons(5554);
		SendToAddr.sin_addr.s_addr = inet_addr("192.168.1.1");

		RecvFromAddr.sin_port = htons(5554);
		RecvFromAddr.sin_addr.s_addr = inet_addr("192.168.1.2");

		addr = "192.168.1.1";
		port = 5554;
	}

	NavDataConnection::~NavDataConnection() {
		closesocket(ConnectSocket);
		WSACleanup();
	}
}


