#ifndef NAVDATACONNECTION_H
#define NAVDATACONNECTION_H

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include "UDPConnection.h"
#include "Frame.h"

namespace connection {
	class NavDataConnection : public UDPConnection {

	private :
		Frame f;

	public:
		NavDataConnection();
		~NavDataConnection();

		void Wakeup();

	};

}

#endif