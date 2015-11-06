/*
 *  Printable.cpp
 *  osc
 *
 *  Created by Jean-Marc Perronne on 14/10/10.
 *  Copyright 2010 ENSISA. All rights reserved.
 *
 */
#include "stdafx.h"

#include "Printable.h"

namespace jmp
{
	
	std::ostream& operator << (std::ostream& os, Printable& p)
	{
		return p.printOn(os);
	}
}