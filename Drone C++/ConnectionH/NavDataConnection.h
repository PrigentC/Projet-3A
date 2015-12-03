#ifndef NAVDATACONNECTION_H
#define NAVDATACONNECTION_H

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include "UDPConnection.h"

namespace connection {
	class NavDataConnection : public UDPConnection {

	public:
		NavDataConnection();
		~NavDataConnection();

	};

}



#endif