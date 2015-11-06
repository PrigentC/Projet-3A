#include "../ConnectionH/UDPConnection.h"
#include "..\ConnectionH\TCPConnection.h"

UDPConnection::UDPConnection() {
	RecvAddr.sin_family = AF_INET;
	RecvAddr.sin_port = htons(0);
	RecvAddr.sin_addr.s_addr = inet_addr("10.78.0.16");
}

int UDPConnection::sendDTGram() {
	iResult = sendto(ConnectSocket,
		SendBuff.farray(), SendBuff.position(), 0, (SOCKADDR *)& RecvAddr, sizeof(RecvAddr));
	if (iResult == SOCKET_ERROR) {
		wprintf(L"sendto failed with error: %d\n", WSAGetLastError());
		closesocket(ConnectSocket);
		WSACleanup();
		return 1;
	}
}
