// Drone C++.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"

#include "STDEXCPT.h"
#include "Connection.h"

#include <thread>

#include <winsock2.h>
#include <WS2tcpip.h>

#include <iostream>


void f1(int n)
{
	for (int i = 0; i < 5; ++i) {
		std::cout << "Thread 1 executing\n";
		++n;
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}

void f2(int& n)
{
	for (int i = 0; i < 5; ++i) {
		std::cout << "Thread 2 executing\n";
		++n;
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}

void testThread() {
	int n = 0;
	//std::thread t1; // t1 is not a thread
	std::thread t2(f1, n + 1); // pass by value
	std::thread t3(f2, std::ref(n)); // pass by reference
	std::thread t4(std::move(t3)); // t4 is now running f2(). t3 is no longer a thread

	t2.join();
	t4.join();

	std::cout << "Final value of n is " << n << '\n';
}

int testConnection() {
	WSADATA data;
	WSAStartup(0x202, &data);

	struct addrinfo *result = NULL,
		*ptr = NULL,
		hints;

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = 0;
	hints.ai_protocol = IPPROTO_UDP;

	std::string adresse("192.168.1.1");
	std::string port("5554");

	//(L)PCSTR = (Long) Pointer Constant String
	int iResult = getaddrinfo(adresse.c_str(), port.c_str(), &hints, &result);
	std::cout << iResult <<std::endl;

	// Attempt to connect to the first address returned by
	// the call to getaddrinfo
	ptr = result;

	SOCKET ConnectSocket = INVALID_SOCKET;

	// Create a SOCKET for connecting to server
	ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
		ptr->ai_protocol);

	// Connect to server.
	iResult = connect(ConnectSocket, ptr->ai_addr, ptr->ai_addrlen);
	if (iResult == SOCKET_ERROR) {
		closesocket(ConnectSocket);
		ConnectSocket = INVALID_SOCKET;
	}

	// Should really try the next address returned by getaddrinfo
	// if the connect call failed
	// But for this simple example we just free the resources
	// returned by getaddrinfo and print an error message

	freeaddrinfo(result);

	if (ConnectSocket == INVALID_SOCKET) {
		printf("Unable to connect to server!\n");
		WSACleanup();
		return 1;
	}

	printf("Able to connect to the Drone thingy !\n");
	return 0;

}

int main()
{
	//testThread();
	//testConnexion();

	Connection co;
	co.ATCommandsConnection();

	char trame[12];
	trame[0] = 0x41;
	trame[1] = 0x54;
	trame[2] = 0x2a;
	trame[3] = 0x46;
	trame[4] = 0x54;
	trame[5] = 0x52;
	trame[6] = 0x49;
	trame[7] = 0x4D;
	trame[8] = 0x3D;
	trame[9] = 0x031;
	trame[10] = 0x2C;
	trame[11] = 0xA;

	int recvbuflen = 12;

	char recvbuf[12];


	int iResult;

	// Send an initial buffer
	iResult = send(co.ConnectSocket, trame, (int)strlen(trame), 0);
	if (iResult == SOCKET_ERROR) {
		printf("send failed: %d\n", WSAGetLastError());
		closesocket(co.ConnectSocket);
		WSACleanup();
		return 1;
	}

	printf("Bytes Sent: %ld\n", iResult);

	// shutdown the connection for sending since no more data will be sent
	// the client can still use the ConnectSocket for receiving data
	iResult = shutdown(co.ConnectSocket, SD_SEND);
	if (iResult == SOCKET_ERROR) {
		printf("shutdown failed: %d\n", WSAGetLastError());
		closesocket(co.ConnectSocket);
		WSACleanup();
		return 1;
	}

	do {
		iResult = recv(co.ConnectSocket, recvbuf, recvbuflen, 0);
		std::cout << iResult;
		if (iResult > 0)
			printf("Bytes received: %d\n", iResult);
		else if (iResult == 0)
			printf("Connection closed\n");
		else
			printf("recv failed: %d\n", WSAGetLastError());
	} while (iResult > 0);


}

