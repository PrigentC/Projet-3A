#include "../BufferH/ByteBuffer.h"

#include <string>
#include <iostream>

ByteBuffer::ByteBuffer() : Buffer(1024, 1024, 0), array(new char[2048])
{}

ByteBuffer::ByteBuffer(size_t size) : Buffer(size, size, 0), array(new char[size]) 
{}

ByteBuffer::~ByteBuffer() {
	delete[] array;
}


//Fonctions put
void ByteBuffer::putBytes(const char* c, size_t size) {
	if (this->pos + size > this->lim) {
		throw std::out_of_range("");
	} else {
		for (unsigned int i = 0; i < size; i++) {
			array[pos++] = c[i];
			lim = pos;
		}
	}
}

void ByteBuffer::putByte(char b) {
	const char* c = reinterpret_cast<const char*> (&b);
	putBytes(c, 1);
}

void ByteBuffer::putString(std::string s) {
	const char* c = s.c_str();
	putBytes(c, s.size());
}

void ByteBuffer::putInt16(int16_t i16) {
	const char* c = reinterpret_cast<const char*> (&i16);
	putBytes(c, 2);
}

void ByteBuffer::putInt32(int32_t i32) {
	const char* c = reinterpret_cast<const char*> (&i32);
	putBytes(c, 4);
}

void ByteBuffer::putInt64(int64_t i64) {
	const char* c = reinterpret_cast<const char*> (&i64);
	putBytes(c, 8);
}

void ByteBuffer::putFloat32(int32_t i32) {
	const char* c = reinterpret_cast<const char*> (&i32);
	putBytes(c, 4);
}


void ByteBuffer::flip() {
	this->pos = 0;
}

void ByteBuffer::clear() {
	delete[] array;
}

char* ByteBuffer::farray() {
	return array;
}

//Fonctions get
const void ByteBuffer::getBytes(char* c, size_t size) {
	if (this->pos + size > this->lim) {
		throw std::out_of_range("");
	} else {
		for (size_t i = 0; i < size; i++) {
			c[i] = array[++pos];
		}
	}

}


char ByteBuffer::getByte() {
	char c;
	getBytes(reinterpret_cast<char *>(&c), 1);
	return c;
}


std::string ByteBuffer::getString(size_t size) {
	char* c = new char[size + 1];
	getBytes(c, size);
	c[size + 1] = '\0';
	std::string s = c;
	delete c;
	return s;
}

int16_t ByteBuffer::getInt16() {
	int16_t i16;
	getBytes(reinterpret_cast<char *>(&i16), 2);
	return i16;
}

int32_t ByteBuffer::getInt32() {
	int32_t i32;
	getBytes(reinterpret_cast<char *>(&i32), 4);
	return i32;
}

int64_t ByteBuffer::getInt64() {
	int64_t i64;
	getBytes(reinterpret_cast<char *>(&i64), 8);
	return i64;
}

int32_t ByteBuffer::getFloat32() {
	int32_t i32;
	getBytes(reinterpret_cast<char *>(&i32), 4);
	return i32;
}
