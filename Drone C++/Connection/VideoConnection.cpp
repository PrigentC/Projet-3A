#include "..\ConnectionH\VideoConnection.h"

namespace connection {
	VideoConnection::VideoConnection() {
		addr = "192.168.1.1";
		port = 5555;
		
		SendToAddr.sin_port = htons(port);
		SendToAddr.sin_addr.s_addr = inet_addr(addr);

		connectUDPServer();
	}

	VideoConnection::~VideoConnection() {
		closesocket(ConnectSocket);
		WSACleanup();
	}
}


