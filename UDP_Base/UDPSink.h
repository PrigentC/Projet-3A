//
//  UDPSink.h
//  osc
//
//  Created by Jean-Marc Perronne on 14/04/11.
//  Copyright 2011 ENSISA. All rights reserved.
//

#ifndef UDPSINK_H
#define UDPSINK_H

#define _WINSOCK_DEPRECATED_NO_WARNINGS

//#include <netdb.h>
#include <winsock2.h>
#include <WS2tcpip.h>
#include <string>

#include "Sink.h"
#include "ByteBuffer.h"

namespace stream
{
    class UDPSink: public Sink
    {

    public:
        UDPSink(const std::string& targetHost, short targetPort);
         
        virtual void sendPacket(jmp::ByteBuffer& packet) const;
        virtual void close() const ;

		SOCKET connectSocket = INVALID_SOCKET;
   
    private:
        virtual void setupAddress(const std::string& _targetHost, short _targetPort);
        virtual void setupSocket();
        
    private:
        /*struct sockaddr_in serverAddress;
        struct hostent *hostInfo;
        int socketDescriptor;*/

		WSADATA data;

		struct addrinfo	*result = NULL, *ptr = NULL, hints;
    };
}

#endif