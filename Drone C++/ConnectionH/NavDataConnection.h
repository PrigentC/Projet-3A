#ifndef NAVDATACONNECTION_H
#define NAVDATACONNECTION_H

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include "UDPConnection.h"
#include "Frame.h"

namespace connection {
	class NavDataConnection : public UDPConnection {

	private :
		Frame frame;

	public:
		NavDataConnection();
		~NavDataConnection();

		void wakeUp();

	};

}

#endif