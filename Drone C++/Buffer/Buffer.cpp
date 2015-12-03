#include "../BufferH/Buffer.h"

#include <string>
#include <iostream>
#include <ostream>

namespace buffer {
	Buffer::Buffer(size_t _capa, size_t _lim, size_t _pos) :
		capacity(_capa), lim(_lim), pos(_pos) {}

	size_t Buffer::remaining() {
		return lim - pos;
	}

	size_t Buffer::position() {
		return pos;
	}

	size_t Buffer::limit() {
		return lim;
	}

	std::ostream& Buffer::printOn(std::ostream& out) {
		out << "[pos=" << pos << " lim=" << lim << " cap=" << capacity << "]";
		return out;
	}

	std::ostream& operator << (std::ostream& out, const Buffer& b) {
		out << "[pos=" << b.pos << " lim=" << b.lim << " cap=" << b.capacity << "]";
		return out;
	}
}

