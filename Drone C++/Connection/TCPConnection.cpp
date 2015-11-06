#include "..\ConnectionH\TCPConnection.h"

TCPConnection::TCPConnection() {
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_DGRAM;
	hints.ai_protocol = IPPROTO_UDP;
}

int TCPConnection::createTCPSocket() {
	iResult = getaddrinfo(addr.c_str(), (u_short)port.c_str(), &hints, &result);
	if (iResult != 0) {
		printf("getaddrinfo failed with error: %d\n", iResult);
		WSACleanup();
		return 1;
	}

	ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
		ptr->ai_protocol);
	if (ConnectSocket == INVALID_SOCKET) {
		printf("socket failed with error: %ld\n", WSAGetLastError());
		WSACleanup();
		return 1;
	}
	return 0;
}

int TCPConnection::connectTCPServer() {
	iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
	if (iResult == SOCKET_ERROR) {
		closesocket(ConnectSocket);
		ConnectSocket = INVALID_SOCKET;
	}
	return 0;
}

int TCPConnection::sendSockStream() {
	iResult = send(ConnectSocket, SendBuff.farray(), SendBuff.position(), 0);
	if (iResult == SOCKET_ERROR) {
		printf("send failed with error: %d\n", WSAGetLastError());
		closesocket(ConnectSocket);
		WSACleanup();
		return 1;
	}
}

int TCPConnection::recvSockStream() {
	do {

		iResult = recv(ConnectSocket, RecvBuff.farray(), 1024, 0);
		if (iResult > 0) {
			printf("Bytes received: %d\n", iResult);
			return 0;
		} else if (iResult == 0) {
			printf("Connection closed\n");
			return 0;
		} else {
			printf("recv failed with error: %d\n", WSAGetLastError());
			return 1;
		}
	} while (iResult > 0);
}
