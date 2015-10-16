//
//  UDPError.h
//  osc
//
//  Created by perronne on 15/04/11.
//  Copyright 2011 ENSISA. All rights reserved.
//


#ifndef UDPERROR_H
#define UDPERROR_H

#include <stdexcept>

namespace stream
{
    class UDPError : public std::runtime_error
    {
    public:
        UDPError(const std::string& what);
    };
}


#endif