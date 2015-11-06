#ifndef CONFIGCONNECTION_H
#define CONFIGCONNECTION_H

#include "TCPConnection.h"

class ConfigConnection : public TCPConnection {

public:
	ConfigConnection();
	~ConfigConnection();

};

#endif
