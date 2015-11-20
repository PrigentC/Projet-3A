#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include "../ConnectionH/UDPConnection.h"

UDPConnection::UDPConnection() {
	SendToAddr.sin_family = AF_INET;
	SendToAddr.sin_port = htons(port);
	SendToAddr.sin_addr.s_addr = inet_addr(addr);

	RecvFromAddr.sin_family = AF_INET;
	RecvFromAddr.sin_port = htons(port);
	RecvFromAddr.sin_addr.s_addr = inet_addr(addr);

	createUDPSocket();
}

int UDPConnection::createUDPSocket() {	
	ConnectSocket = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (ConnectSocket == INVALID_SOCKET) {
		wprintf(L"socket failed with error: %ld\n", WSAGetLastError());
		WSACleanup();
		return 1;
	}

	bool x;
	setsockopt(ConnectSocket, SOL_SOCKET, SO_REUSEADDR, (char*)&x, sizeof(BOOL));

	u_long iMode = 1;

	iResult = ioctlsocket(ConnectSocket, FIONBIO, &iMode);
	if (iResult != NO_ERROR) {
		printf("ioctlsocket failed with error: %d\n", WSAGetLastError());
		return 1;
	}

	return 0;
}

int UDPConnection::sendDTGram() {
	iResult = sendto(ConnectSocket, SendBuff.farray(), SendBuff.position(), 0, (struct sockaddr *) &SendToAddr, sizeof SendToAddr);
	if (iResult == SOCKET_ERROR) {
		wprintf(L"sendto failed with error: %d\n", WSAGetLastError());
		closesocket(ConnectSocket);
		WSACleanup();
		return 1;
	}
	return 0;
}

int UDPConnection::recvDTGram() {
	iResult = recvfrom(ConnectSocket, RecvBuff.farray(), RecvBuff.remaining(), 0, NULL, NULL);
	if (iResult == SOCKET_ERROR) {
		wprintf(L"recvfrom failed with error %d\n", WSAGetLastError());
		return 1;
	}
	return 0;
}
