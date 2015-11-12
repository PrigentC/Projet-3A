// Drone C++.cpp�: d�finit le point d'entr�e pour l'application console.
//

#include "STDEXCPT.h"
#include "ConnectionH\ClientConnection.h"
#include "ConnectionH\AtCommandConnection.h"
#include "ConnectionH\NavDataConnection.h"


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

	printf("Able to connect to the Drone !\n");
	return 0;

}

int testBoot() {

	ClientConnection atc;
	ClientConnection nav;

	atc.ATCommandsConnection();
	nav.NavdataConnection();

	int recvbuflen = 124;

	char recvbuf[124];

	u_long iMode = 1;

	//int iResult = ioctlsocket(co.ConnectSocket, FIONBIO, &iMode);
	int iResult;

	std::cout << "Sending wakeup on navData" << std::endl;
	char wakeup[] = { 0x01, 0x00, 0x00, 0x00 };
	std::cout << wakeup << std::endl;
	// Send an initial buffer
	iResult = send(nav.ConnectSocket, wakeup, (int)strlen(wakeup), 0);
	if (iResult == SOCKET_ERROR) {
		printf("send failed: %d\n", WSAGetLastError());
		closesocket(nav.ConnectSocket);
		WSACleanup();
		return 1;
	}

	printf("Bytes Sent: %ld\n", iResult);

	int header = 0;

	std::cout << "Listening to answer on navData" << std::endl;
	do {
		iResult = recv(nav.ConnectSocket, recvbuf, recvbuflen, 0);
		std::cout << recvbuf << std::endl;

		if (iResult == header) {
			printf("Connection closed\n");
			break;
		} else if (iResult > 0) {
			printf("Bytes received: %d\n", iResult);
			header = 24;
		} else
			printf("recv failed: %d\n", WSAGetLastError());
	} while (iResult > 0);

	std::cout << std::endl;


	std::cout << "Sending Navdata_demo on ATCommands" << std::endl;
	char trame1[] = "AT*CONFIG=1,\"general:navdata_demo\",\"TRUE\"\r";
	std::cout << trame1 << std::endl;
	// Send an initial buffer
	iResult = send(atc.ConnectSocket, trame1, (int)strlen(trame1), 0);
	if (iResult == SOCKET_ERROR) {
		printf("send failed: %d\n", WSAGetLastError());
		closesocket(atc.ConnectSocket);
		WSACleanup();
		return 1;
	}

	printf("Bytes Sent: %ld\n", iResult);

	header = 0;

	std::cout << "Listening to answer on navData" << std::endl;
	do {
		iResult = recv(nav.ConnectSocket, recvbuf, recvbuflen, 0);
		std::cout << recvbuf << std::endl;

		if (iResult == header) {
			printf("Connection closed\n");
			break;
		} else if (iResult > 0) {
			printf("Bytes received: %d\n", iResult);
			header = iResult;
		} else
			printf("recv failed: %d\n", WSAGetLastError());
	} while (iResult > 0);

	std::cout << std::endl;


	/*do {

	iResult = recv(co.ConnectSocket, recvbuf, recvbuflen, 0);
	if (iResult > 0)
	printf("Bytes received: %d\n", iResult);
	else if (iResult == 0)
	printf("Connection closed\n");
	else
	printf("recv failed: %d\n", WSAGetLastError());
	} while (iResult > 0);*/


	std::cout << "Sending CTRL on ATCommands" << std::endl;
	char trame2[] = "AT*CTRL=2,5,\r";
	std::cout << trame2 << std::endl;
	// Send an initial buffer
	iResult = send(atc.ConnectSocket, trame2, (int)strlen(trame2), 0);
	if (iResult == SOCKET_ERROR) {
		printf("send failed: %d\n", WSAGetLastError());
		closesocket(atc.ConnectSocket);
		WSACleanup();
		return 1;
	}

	printf("Bytes Sent: %ld\n", iResult);

	// shutdown the connection for sending since no more data will be sent
	// the client can still use the ConnectSocket for receiving data
	iResult = shutdown(nav.ConnectSocket, SD_SEND);
	if (iResult == SOCKET_ERROR) {
		printf("shutdown failed: %d\n", WSAGetLastError());
		closesocket(nav.ConnectSocket);
		WSACleanup();
		return 1;
	}

	header = 0;

	std::cout << "Listening to answer on navData" << std::endl;
	do {
		iResult = recv(atc.ConnectSocket, recvbuf, recvbuflen, 0);
		std::cout << recvbuf << std::endl;

		if (iResult == header) {
			printf("Connection closed\n");
			break;
		} else if (iResult > 0) {
			printf("Bytes received: %d\n", iResult);
			header = 24;
		} else
			printf("recv failed: %d\n", WSAGetLastError());
	} while (iResult > 0);

	std::cout << std::endl;

	/*
	do {

	iResult = recv(co.ConnectSocket, recvbuf, recvbuflen, 0);
	if (iResult > 0)
	printf("Bytes received: %d\n", iResult);
	else if (iResult == 0)
	printf("Connection closed\n");
	else
	printf("recv failed: %d\n", WSAGetLastError());
	} while (iResult > 0);*/
}

int main()
{
	//testThread();
	//testConnexion();
	//testBoot();
	
	
	AtCommandConnection atc;
	NavDataConnection nav;

	std::cout << "Wakeup data control" << std::endl;
	char wakeup[] = { 0x01, 0x00, 0x00, 0x00 };
	std::cout << wakeup << std::endl;

	nav.SendBuff.getBytes(wakeup, 4);

	std::cout << "Sending wakeup on navData" << std::endl;
	nav.sendDTGram();

	std::cout << "Listening to answer on navData" << std::endl;
	nav.recvDTGram();

	std::cout << "Answer on navData control" << std::endl;
	std::cout << nav.RecvBuff << std::endl;

	std::cout << std::endl;


	std::cout << "Navdata_demo data control" << std::endl;
	char trame1[] = "AT*CONFIG=1,\"general:navdata_demo\",\"TRUE\"\r";
	std::cout << trame1 << std::endl;

	atc.SendBuff.getBytes(trame1, 43);

	std::cout << "Sending Navdata_demo on ATCommands" << std::endl;
	atc.sendDTGram();

	std::cout << "Listening to answer on navData" << std::endl;
	atc.recvDTGram();

	std::cout << "Answer on ATCommands control" << std::endl;
	std::cout << atc.RecvBuff << std::endl;

	std::cout << std::endl;
}

