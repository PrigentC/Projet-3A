#include "../ConnectionH/ClientConnection.h"

ClientConnection::ClientConnection()
{
}

ClientConnection::~ClientConnection()
{
}

void ClientConnection::Initialize()
{
	WSAStartup(0x202, &data);

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = 0;
}

void ClientConnection::CreateClientSocket()
{
	int iResult = getaddrinfo(adresse.c_str(), port.c_str(), &hints, &result);
	//std::cout << iResult;

	// Attempt to connect to the first address returned by
	// the call to getaddrinfo
	ptr = result;

	// Create a SOCKET for connecting to server
	ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
		ptr->ai_protocol);
}

void ClientConnection::ConnectServer()
{
	// Connect to server.
	int iResult = connect(ConnectSocket, ptr->ai_addr, ptr->ai_addrlen);
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
		std::cout << "Unable to connect to server!" << std::endl;
		WSACleanup();
	}

	std::cout << "Able to connect to the Drone !\n" << std::endl;
}

void ClientConnection::NavdataConnection()
{
	Initialize();
	
	hints.ai_protocol = IPPROTO_UDP;

	port = "5554";

	CreateClientSocket();
	ConnectServer();
}

void ClientConnection::ATCommandsConnection()
{
	Initialize();

	hints.ai_protocol = IPPROTO_UDP;

	port = "5556";

	CreateClientSocket();
	ConnectServer();
}

void ClientConnection::VideoConnection()
{
	Initialize();

	hints.ai_protocol = IPPROTO_UDP;

	port = "5555";

	CreateClientSocket();
	ConnectServer();
}


void ClientConnection::ControlPortConnection()
{
	Initialize();

	hints.ai_protocol = IPPROTO_TCP;

	port = "5559";

	CreateClientSocket();
	ConnectServer();
}

void ClientConnection::TestClientConnection() {
	Initialize();

	hints.ai_protocol = IPPROTO_UDP;

	port = "7777";

	CreateClientSocket();
	ConnectServer();
}
