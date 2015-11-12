#include "..\ConnectionH\VideoConnection.h"

VideoConnection::VideoConnection() {
	Addr.sin_port = htons(5555);
	Addr.sin_addr.s_addr = inet_addr("192.168.1.1");

	addr = "192.168.1.1";
	port = "5555";
}

VideoConnection::~VideoConnection() {}
