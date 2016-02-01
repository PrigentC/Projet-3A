#ifndef ATCOMMANDCONNECTION_H
#define ATCOMMANDCONNECTION_H

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include "UDPConnection.h"
#include "Frame.h"

namespace connection {
	class AtCommandConnection : public UDPConnection {
	private :
		Frame frame;

	public:
		AtCommandConnection();
		~AtCommandConnection();

		void navdataDemoMode();

		void takeOff();
		void land();
		void watchDog();
		void fTrim();

	};
}

#endif
