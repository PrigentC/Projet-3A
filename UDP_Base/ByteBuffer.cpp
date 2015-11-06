//
//  ByteBuffer.cpp
//  osc
//
//  Created by Jean-Marc Perronne on 05/04/11.
//  Copyright 2011 ENSISA. All rights reserved.
//

#include "stdafx.h"

#include "ByteBuffer.h"
#include <stdexcept>

#include <winsock2.h>
#include <WS2tcpip.h>

namespace jmp
{
    
    
#ifndef htonll
#ifdef __BIG_ENDIAN__
#define htonll(x)   (x)
#define ntohll(x)   (x)
#else
#define htonll(x)   ((((uint64_t)htonl(x)) << 32) + htonl(x >> 32))
#define ntohll(x)   ((((uint64_t)ntohl(x)) << 32) + ntohl(x >> 32))
#endif
#endif

    ByteBuffer::ByteBuffer(size_t capacity):
    Buffer(capacity, capacity, 0,-1), _bytes(new char[capacity])
    {
    }
    
    ByteBuffer::~ByteBuffer()
    {
        delete [] _bytes;
    }
    
    void ByteBuffer::putBytes(const char* bytes, size_t length)
    {
        checkCapacity(length);
        for(size_t i=0; i<length; i++)
            _bytes[_position++] = bytes[i];   
        _limit = _position;
    }
    
    void ByteBuffer::putByte(char v)
    {
        putBytes(reinterpret_cast<const char*>(&v), 1);
    }

    void ByteBuffer::putInt16(int16_t v)
    {
        v = htons(v); //host2net
        putBytes(reinterpret_cast<const char*>(&v), 2);
    }

    void ByteBuffer::putInt32(int32_t v)
    {
        v = htonl(v); //host2net
        putBytes(reinterpret_cast<const char*>(&v), 4);
    }
    
    void ByteBuffer::putInt64(int64_t v)
    {
        v = htonll(v); //host2net
        putBytes(reinterpret_cast<const char*>(&v), 8);
    }

    void ByteBuffer::putFloat32(float v)
    {
        //putBytes(reinterpret_cast<const char*>(&v), 4);
        putInt32(*reinterpret_cast<const int32_t*>(&v));
    }

    void ByteBuffer::putString(const std::string& s)
    {
        putBytes(s.c_str(), s.size());
    }

    void ByteBuffer::getBytes(char *bytes, size_t length)
    {
        checkBytesAvailable(length);
        for(size_t i=0; i<length; i++)
            bytes[i] = _bytes[_position++];
    }

    char ByteBuffer::getByte()
    {
        char b;
        getBytes(reinterpret_cast<char*>(&b), 1);
        return b;
    }

    int16_t ByteBuffer::getInt16()
    {
        short v;
        getBytes(reinterpret_cast<char*>(&v), 2);
        return ntohs(v); //net2host
    }

    int32_t ByteBuffer::getInt32()
    {
        long v;
        getBytes(reinterpret_cast<char*>(&v), 4);
        return ntohl(v); //net2host
    }
    
    int64_t ByteBuffer::getInt64()
    {
        long long v;
        getBytes(reinterpret_cast<char*>(&v), 8);
        return ntohll(v); //net2host
    }
    
    float ByteBuffer::getFloat32()
    {
        int32_t v = getInt32();
        return *reinterpret_cast<float*>(&v);
    }

    std::string ByteBuffer::getString(size_t len)
    {
		char* c = new char[len + 1];
		getBytes(c, len);
		c[len + 1] = '\0';
		std::string s = c;
		delete c;
		return s;
    }

    char* ByteBuffer::array()
    {
        return _bytes;
    }
    
    void ByteBuffer::checkBytesAvailable(size_t sz) const
    {
        if (_position+sz > _limit)
            throw std::out_of_range("no enough bytes available");
    }

    void ByteBuffer::checkCapacity(size_t sz) const
    {
        if (_position+sz > _capacity)
            throw std::out_of_range("out of capacity");
    }
}