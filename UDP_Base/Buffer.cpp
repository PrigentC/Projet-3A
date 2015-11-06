//
//  Buffer.cpp
//  osc
//
//  Created by Jean-Marc Perronne on 05/04/11.
//  Copyright 2011 ENSISA. All rights reserved.
//
#include "stdafx.h"

#include <stdexcept>
#include "Buffer.h"

namespace jmp
{
    Buffer::Buffer(int capacity, int limit, int position, int mark):
    _capacity(capacity), _limit(limit), _position(position), _mark(mark)
    {
    }
    
    int Buffer::capacity() const
    {
        return _capacity;
    }

    Buffer& Buffer::clear()
    {
        _limit = _capacity;
        _position = 0;
        _mark = -1;
        return *this;
    }

    Buffer& Buffer::flip()
    {
        _limit = _position;
        _position = 0;
        _mark = -1;
        return *this;
    }
    
    bool Buffer::hasRemaining() const
    {
        return _limit - _position > 0;
    }

    int Buffer::limit() const
    {
        return _limit;
    }
    
    Buffer& Buffer::limit(int newLimit)
    {
        if ((newLimit < 0) || (newLimit > _capacity)) 
            throw  std::invalid_argument("newLimit");
        
        _limit = newLimit;
        if (_position > _limit) _position = _limit;
        if (_mark > _limit) _mark = -1;
        return *this;
    }

    Buffer& Buffer::mark()
    {
        _mark = _position;
        return *this;
    }

    int Buffer::position() const
    {
        return _position;
    }
    
    Buffer& Buffer::position(int newPosition)
    {
        if ((newPosition < 0) || (newPosition > _limit))
            throw  std::invalid_argument("newPosition");
       
        _position = newPosition;
        if (_mark > _position) _mark = -1;
        return *this;
    }
    
    int Buffer::remaining() const
    {
        return _limit - _position;
    }
    
    Buffer& Buffer::reset()
    {
        _position = _mark;
        return *this;
    }
    
    Buffer& Buffer::rewind()
    {
        _position = 0;
        _mark = -1;        
        return *this;
    }
    
    std::ostream& Buffer::printOn(std::ostream& os) const
    {
        return os <<"ByteBuffer[pos="<<_position<<" lim="<<_limit<<" cap="<<_capacity<<']';
    }

}