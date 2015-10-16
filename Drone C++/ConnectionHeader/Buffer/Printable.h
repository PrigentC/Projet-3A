/*
 *  Printable.h
 *  osc
 *
 *  Created by Jean-Marc Perronne on 14/10/10.
 *  Copyright 2010 ENSISA. All rights reserved.
 *
 */

#ifndef PRINTABLE_H
#define PRINTABLE_H

#include <iostream>

namespace jmp
{
	
	class Printable
	{
	public:
        virtual ~Printable() {};
        
		virtual std::ostream& printOn(std::ostream&) const = 0;
		
		friend std::ostream& operator << (std::ostream&, Printable&);
	};
}
#endif