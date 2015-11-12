#include "../ConnectionH/ATCommandConnection.h"

AtCommandConnection::AtCommandConnection() {
	Addr.sin_port = htons(5556);
	Addr.sin_addr.s_addr = inet_addr("192.168.1.1");
	
	addr = "192.168.1.1";
	port = "5556";
}

AtCommandConnection::~AtCommandConnection() {}
