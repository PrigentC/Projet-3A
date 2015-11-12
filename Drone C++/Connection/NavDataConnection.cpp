#include "../ConnectionH/NavDataConnection.h"

NavDataConnection::NavDataConnection() {
	Addr.sin_port = htons(5554);
	Addr.sin_addr.s_addr = inet_addr("192.168.1.1");

	addr = "192.168.1.1";
	port = "5554";
}

NavDataConnection::~NavDataConnection() {}
