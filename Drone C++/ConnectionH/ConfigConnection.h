#ifndef CONFIGCONNECTION_H
#define CONFIGCONNECTION_H

#include "TCPConnection.h"

namespace connection {
	class ConfigConnection : public TCPConnection {

	public:
		ConfigConnection();
		~ConfigConnection();

	};
}

#endif
