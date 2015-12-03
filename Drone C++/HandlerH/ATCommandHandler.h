#ifndef ATCOMMANDHANDLER_H
#define ATCOMMANDHANDLER_H

#include <thread>
#include <future>

namespace handler {
	class ATCommandHandler {
	public:
		static void run();

	private :
		static void takeOff();
		static void land();
	};
}

#endif;
