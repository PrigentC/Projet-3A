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

	void NavDataConnection::wakeUp() {
		std::cout << "Wakeup data control" << std::endl;
		char wakeup[] = { 0x01, 0x00, 0x00, 0x00 };
		std::cout << wakeup << std::endl;

		std::cout << "Sending wakeup on navData" << std::endl;
		SendBuff.putBytes(wakeup, 4);
		std::cout << SendBuff << std::endl;
		std::cout << SendBuff.farray() << std::endl;

		sendDTGram();
	}
}


