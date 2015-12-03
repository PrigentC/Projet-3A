#ifndef NAVDATAHANDLER_H
#define NAVDATAHANDLER_H

#include <thread>
#include <future>

namespace handler {
	class NavDataHandler {
	public:
		static void run();

		static void sendWakeUp();
	};
}

#endif;
