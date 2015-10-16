//
//  UDPSink.h
//  osc
//
//  Created by Jean-Marc Perronne on 14/04/11.
//  Copyright 2011 ENSISA. All rights reserved.
//

#ifndef UDPSINK_H
#define UDPSINK_H

#include <netdb.h>
#include<string>

#include "Sink.h"
#include "../jmp/ByteBuffer.h"

namespace stream
{
    class UDPSink: public Sink
    {
    public:
        UDPSink(const std::string& targetHost, short targetPort);
         
        virtual void send(jmp::ByteBuffer& packet) const;
        virtual void close() const ;
   
    private:
        virtual void setupAddress(const std::string& _targetHost, short _targetPort);
        virtual void setupSocket();
        
    private:
        struct sockaddr_in serverAddress;
        struct hostent *hostInfo;
        int socketDescriptor;
    };
    
    
    
    
}

#endif