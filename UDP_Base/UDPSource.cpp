//
//  UDPSource.cpp
//  osc
//
//  Created by perronne on 15/04/11.
//  Copyright 2011 ENSISA. All rights reserved.
//

#include "stdafx.h"

#include <errno.h>

#include "UDPSource.h"
#include "UDPError.h"

namespace stream
{
    const int UDPSource::BUFFER_SIZE = 1000;
    const time_t UDPSource::TIMEOUT = 10000; //10ms

    UDPSource::UDPSource(short port):
    Source(BUFFER_SIZE)
    {
        setupSocket(port);
    }
    
    void UDPSource::setupSocket(short port)
    {
        serverAddress.sin_family = AF_INET; 
        serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
        serverAddress.sin_port = htons(port);
        
        listenSocket = socket(AF_INET, SOCK_DGRAM, 0);
        if (listenSocket < 0)
            throw UDPError("cannot create socket");
        
        if(bind(listenSocket, (struct sockaddr *) &serverAddress,sizeof(serverAddress)) < 0) 
            throw UDPError("cannot bind socket");
        
        struct timeval tv;
		tv.tv_sec   = 0; 
		tv.tv_usec  = TIMEOUT; 
		setsockopt( listenSocket, SOL_SOCKET, SO_RCVTIMEO, (const char *)&tv, sizeof(tv));
    }

    jmp::ByteBuffer& UDPSource::receive()
    {
        struct sockaddr_in clientAddress;
        socklen_t clientAddressLength = sizeof(clientAddress);
        
        buffer.clear();
        int received = recvfrom(listenSocket, buffer.array(), BUFFER_SIZE, 0, (struct sockaddr *) &clientAddress, &clientAddressLength);
        if ( received < 0)
        {
            if (errno != EAGAIN) throw UDPError("I/O Problem");
            else received = 0;
        }
       
        buffer.position(0);
        buffer.limit(received);
        return buffer;
    }
    
    void UDPSource::close() const
    {
        closesocket(listenSocket);
    }

}
