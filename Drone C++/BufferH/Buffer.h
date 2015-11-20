#ifndef BUFFER_H
#define BUFFER_H

#include <iostream>

class Buffer {

	public :
		Buffer(size_t capacity, size_t limit, size_t pos);

		virtual size_t remaining();
		virtual size_t position();	//En gros, méthode set
		virtual size_t limit();

		friend std::ostream& operator << (std::ostream&, const Buffer&);
		virtual std::ostream& printOn(std::ostream&);

	protected :
		size_t capacity;
		size_t lim;
		size_t pos;
};

#endif