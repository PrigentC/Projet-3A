//
//  Sink.h
//  osc
//
//  Created by Jean-Marc Perronne on 30/03/11.
//  Copyright 2011 ENSISA. All rights reserved.
//

#ifndef SINK_H
#define SINK_H

#include "../jmp/ByteBuffer.h"

namespace stream
{
    class Sink
    {
    public:
        virtual ~Sink() {};
        
        virtual void  send(jmp::ByteBuffer& buffer) const = 0;
    };
}
#endif