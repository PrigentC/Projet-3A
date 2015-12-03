#ifndef NAVDATAHANDLER_H
#define NAVDATAHANDLER_H

#include <thread>
#include <future>

namespace handler {
	class NavDataHandler {
	public:
		static void run();

	private :
		static void WakeUp();
	};
}

#endif;
