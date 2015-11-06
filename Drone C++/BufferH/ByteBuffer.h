#ifndef BYTEBUFFER_H
#define BYTEBUFFER_H

#include "../BufferH/Buffer.h"

#include <string>
#include <iostream>
#include <stdint.h>

class ByteBuffer : public Buffer {

public:
	ByteBuffer();
	ByteBuffer(size_t);
	virtual ~ByteBuffer();

	virtual void putBytes(const char*, size_t);
	virtual void putByte(char);
	virtual void putString(std::string);
	virtual void putInt16(int16_t);
	virtual void putInt32(int32_t);
	virtual void putInt64(int64_t);
	virtual void putFloat32(int32_t);

	virtual void flip();
	virtual void clear();
	virtual char* farray();

	virtual void getBytes(char * c, size_t);
	virtual char getByte();
	virtual std::string getString(size_t);
	virtual int16_t getInt16();
	virtual int32_t getInt32();
	virtual int64_t getInt64();
	virtual int32_t getFloat32();

private:
	char* array;
};

#endif