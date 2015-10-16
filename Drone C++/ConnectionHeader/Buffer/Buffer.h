//
//  Buffer.h
//  osc
//
//  Created by Jean-Marc Perronne on 05/04/11.
//  Copyright 2011 ENSISA. All rights reserved.
//

#ifndef BUFFER_H
#define BUFFER_H

#include "Printable.h"
namespace jmp
{
    class Buffer : public Printable
    {
    public:
        Buffer(int capacity, int limit, int position, int mark);
        virtual ~Buffer() {};
        
        virtual int capacity() const;
        virtual Buffer& clear();
        virtual Buffer& flip();
        virtual bool hasRemaining()const;
        virtual int limit() const;
        virtual Buffer& limit(int newLimit);
        virtual Buffer& mark();
        virtual int position() const;
        virtual Buffer& position(int newPosition);
        virtual int remaining() const;
        virtual Buffer& reset();
        virtual Buffer& rewind();

		virtual std::ostream& printOn(std::ostream&) const;

    protected:
        const size_t _capacity;
        size_t _limit;
        size_t _position;
        size_t _mark;
    };
}
#endif