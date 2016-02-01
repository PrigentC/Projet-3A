#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include "../ConnectionH/UDPConnection.h"

namespace connection {
	UDPConnection::UDPConnection() {
		SendToAddr.sin_family = AF_INET;
		SendToAddr.sin_port = htons(port);
		SendToAddr.sin_addr.s_addr = inet_addr(addr);

		createUDPSocket();
	}

	int UDPConnection::createUDPSocket() {
		ConnectSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
		if (ConnectSocket == INVALID_SOCKET) {
			wprintf(L"socket failed with error: %ld\n", WSAGetLastError());
			WSACleanup();
			return 1;
		}

		DWORD x = 2000;
		//bool x;
		setsockopt(ConnectSocket, SOL_SOCKET, SO_RCVTIMEO, (char*)&x, sizeof(DWORD));

		/*u_long iMode = 0;

		iResult = ioctlsocket(ConnectSocket, FIONBIO, &iMode);
		if (iResult != NO_ERROR) {
			printf("ioctlsocket failed with error: %d\n", WSAGetLastError());
			return 1;
		}*/

		return 0;
	}

	int UDPConnection::connectUDPServer() {
		iResult = connect(ConnectSocket, (SOCKADDR *)& SendToAddr, sizeof(SendToAddr));
		if (iResult == SOCKET_ERROR) {
			wprintf(L"connect function failed with error: %ld\n", WSAGetLastError());
			iResult = closesocket(ConnectSocket);
			if (iResult == SOCKET_ERROR)
				wprintf(L"closesocket function failed with error: %ld\n", WSAGetLastError());
			WSACleanup();
			return 1;
		}
		return 0;
	}

	int UDPConnection::sendDTGram() {
		iResult = send(ConnectSocket, SendBuff.farray(), SendBuff.position(), 0);
		if (iResult == SOCKET_ERROR) {
			wprintf(L"sendto failed with error: %d\n", WSAGetLastError());
			closesocket(ConnectSocket);
			WSACleanup();
			return 1;
		}
		return 0;
	}

	int UDPConnection::recvDTGram() {
		char tmp[292];

		iResult = recv(ConnectSocket, tmp, 292, 0);

		tmp[iResult - 1] = '\0';
		if (iResult == SOCKET_ERROR) {
			wprintf(L"recv failed with error %d\n", WSAGetLastError());
			return 1;
		}

		RecvBuff.putBytes(tmp, 292);

		for (unsigned i = 0 ; i < 292 ; i++) {
			wprintf(L"%c", tmp[i]);
		}

		return 0;
	}

}

