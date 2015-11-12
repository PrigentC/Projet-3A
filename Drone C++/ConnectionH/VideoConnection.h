#ifndef VIDEOCONNECTION_H
#define VIDEOCONNECTION_H

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include "UDPConnection.h"

class VideoConnection : public UDPConnection {

public:
	VideoConnection();
	~VideoConnection();

};

#endif
