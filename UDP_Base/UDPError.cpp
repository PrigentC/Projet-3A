//
//  UDPError.cpp
//  osc
//
//  Created by perronne on 15/04/11.
//  Copyright 2011 ENSISA. All rights reserved.
//
#include "stdafx.h"

#include "UDPError.h"

namespace stream
{
    UDPError::UDPError(const std::string& what):
    runtime_error(what)
    {
    }
}