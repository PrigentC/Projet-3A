#include "../BufferH/Buffer.h"

#include <string>
#include <iostream>
#include <ostream>

Buffer::Buffer(size_t _capa, size_t _lim, size_t _pos) :
	capacity(_capa), limit(_lim), pos(_pos) {}

size_t Buffer::remaining() {
	return limit - pos;
}

size_t Buffer::position() {
	return pos;
}

std::ostream& Buffer::printOn(std::ostream& out) {
	out << "[pos=" << pos << " lim=" << limit << " cap=" << capacity << "]";
	return out;
}

std::ostream& operator << (std::ostream& out, const Buffer& b) {
	out << "[pos=" << b.pos << " lim=" << b.limit << " cap=" << b.capacity << "]";
	return out;
}