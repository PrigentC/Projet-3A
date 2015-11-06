//
//  UDPSource.h
//  osc
//
//  Created by perronne on 15/04/11.
//  Copyright 2011 ENSISA. All rights reserved.
//

#ifndef UDPSOURCE_H
#define UDPSOURCE_H

//#include <netdb.h>

#include <winsock2.h>
#include <WS2tcpip.h>

#include "ByteBuffer.h"
#include "Source.h"


namespace stream
{
    class UDPSource : public Source
    {
    public:
        UDPSource(short port);
        virtual ~UDPSource() {};
        
        virtual jmp::ByteBuffer& receive();
        virtual void close() const ;
        
    private:
        virtual void setupSocket(short port);

    private:
        struct sockaddr_in serverAddress;
        int listenSocket;
        
        static const int BUFFER_SIZE;
        static const time_t TIMEOUT;

    };
}

#endif