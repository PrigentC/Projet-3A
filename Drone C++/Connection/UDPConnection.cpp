#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include "../ConnectionH/UDPConnection.h"

UDPConnection::UDPConnection() {
	Addr.sin_family = AF_INET;
	Addr.sin_port = htons((u_short) port.c_str());
	Addr.sin_addr.s_addr = inet_addr(addr.c_str());
}

int UDPConnection::sendDTGram() {
	iResult = sendto(ConnectSocket,
		SendBuff.farray(), SendBuff.position(), 0, (SOCKADDR *)& Addr, sizeof(Addr));
	if (iResult == SOCKET_ERROR) {
		wprintf(L"sendto failed with error: %d\n", WSAGetLastError());
		closesocket(ConnectSocket);
		WSACleanup();
		return 1;
	}
	return 0;
}

int UDPConnection::recvDTGram() {
	iResult = recvfrom(ConnectSocket,
		RecvBuff.farray(), 1024, 0, (SOCKADDR *)& Addr, (int *)sizeof(Addr));
	if (iResult == SOCKET_ERROR) {
		wprintf(L"recvfrom failed with error %d\n", WSAGetLastError());
	}
	return 0;
}
