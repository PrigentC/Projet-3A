// UDP_Base.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"

#include "UDPSink.h"
#include "UDPSource.h"


int main()
{
	stream::UDPSource USource(10500);
	stream::UDPSink USink("10.59.200.185", 10500);

	jmp::ByteBuffer bb(20);
	bb.getBytes("Hello", 6);

	//USink.send(bb);
	std::cout << USource.receive() << std::endl;

	return 0;
}

