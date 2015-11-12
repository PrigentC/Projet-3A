#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include "../ConnectionH/UDPConnection.h"

UDPConnection::UDPConnection() {
	Addr.sin_family = AF_INET;
	Addr.sin_port = htons((u_short) port.c_str());
	Addr.sin_addr.s_addr = inet_addr(addr.c_str());

	createUDPSocket();
}

int UDPConnection::createUDPSocket() {
	ConnectSocket = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (ConnectSocket == INVALID_SOCKET) {
		wprintf(L"socket failed with error: %ld\n", WSAGetLastError());
		WSACleanup();
		return 1;
	}
}

int UDPConnection::bindUDPSocket() {
	iResult = bind(ConnectSocket, (SOCKADDR *) &Addr, sizeof(Addr));
	if (iResult != 0) {
		wprintf(L"bind failed with error %d\n", WSAGetLastError());
		return 1;
	}
	return 0;
}

int UDPConnection::sendDTGram() {
	bindUDPSocket();
	
	iResult = sendto(ConnectSocket,
		SendBuff.farray(), SendBuff.position(), 0, (SOCKADDR*) &Addr, sizeof(Addr));
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
		RecvBuff.farray(), 2048, 0, (SOCKADDR*) &Addr, (int*) sizeof(&Addr));
	if (iResult == SOCKET_ERROR) {
		wprintf(L"recvfrom failed with error %d\n", WSAGetLastError());
	}
	return 0;
}
