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

int testConnexion() {
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
	std::cout << iResult;

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
}

