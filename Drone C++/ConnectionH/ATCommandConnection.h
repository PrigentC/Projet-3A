#ifndef ATCOMMANDCONNECTION_H
#define ATCOMMANDCONNECTION_H

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include "UDPConnection.h"

class AtCommandConnection : public UDPConnection {

public:
	AtCommandConnection();
	~AtCommandConnection();

};

#endif
