//
//  ByteBuffer.h
//  osc
//
//  Created by Jean-Marc Perronne on 05/04/11.
//  Copyright 2011 ENSISA. All rights reserved.
//

#ifndef BYTEBUFFER_H
#define BYTEBUFFER_H

#include "Buffer.h"

namespace jmp
{
    class ByteBuffer: public Buffer
    {
    public:
        ByteBuffer(size_t capacity);
        virtual ~ByteBuffer();
        
        virtual void putBytes(const char* bytes, size_t length);
        virtual void putByte(char v);
        virtual void putInt16(int16_t v);
        virtual void putInt32(int32_t v);
        virtual void putInt64(int64_t v);
        virtual void putFloat32(float v);

        virtual void putString(const std::string& v);

        virtual void getBytes(char* bytes, size_t length);
        virtual char getByte();
        virtual int16_t getInt16();
        virtual int32_t getInt32();
        virtual int64_t getInt64();
        virtual float getFloat32();
        virtual std::string getString(size_t len);

        virtual char* array();
        
    protected:
        virtual void checkCapacity(size_t sz) const;
        virtual void checkBytesAvailable(size_t sz) const;

    private:
        char* _bytes;
    };
}

#endif