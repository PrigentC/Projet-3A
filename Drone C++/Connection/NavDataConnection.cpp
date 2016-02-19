#include "../ConnectionH/NavDataConnection.h"

namespace connection {
	NavDataConnection::NavDataConnection() {
		addr = "192.168.1.1";
		port = 5554;

		SendToAddr.sin_port = htons(port);
		SendToAddr.sin_addr.s_addr = inet_addr(addr);

		connectUDPServer();
	}

	NavDataConnection::~NavDataConnection() {
		closesocket(ConnectSocket);
		WSACleanup();
	}

	void NavDataConnection::wakeUp() {
		char wakeup[] = { 0x01, 0x00, 0x00, 0x00 };
		SendBuff.putBytes(wakeup, 4);
		sendDTGram();

		/*std::cout << "Wakeup data control" << std::endl;
		char wakeup[] = { 0x01, 0x00, 0x00, 0x00 };
		std::cout << wakeup << std::endl;

		std::cout << "Sending wakeup on navData" << std::endl;
		SendBuff.putBytes(wakeup, 4);
		std::cout << SendBuff << std::endl;
		std::cout << SendBuff.farray() << std::endl;

		sendDTGram();*/
	}

	void NavDataConnection::receive() {
		recvDTGram();
	}
}


