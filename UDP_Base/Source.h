//
//  Source.h
//  osc
//
//  Created by Jean-Marc Perronne on 30/03/11.
//  Copyright 2011 ENSISA. All rights reserved.
//

#ifndef SOURCE_H
#define SOURCE_H

#include "ByteBuffer.h"

namespace stream
{
    class Source
    {
    public:
        Source(size_t length);
        virtual ~Source() {};
        
        virtual jmp::ByteBuffer& receive();
    
    protected:
        jmp::ByteBuffer buffer;
    };
}
#endif