//
//  Source.cpp
//  osc
//
//  Created by perronne on 18/04/11.
//  Copyright 2011 ENSISA. All rights reserved.
//

#include "Source.h"

namespace stream
{
    Source::Source(size_t length):
    buffer(length)
    {
    }
    
    jmp::ByteBuffer& Source::receive()
    {
        return buffer;
    }
}