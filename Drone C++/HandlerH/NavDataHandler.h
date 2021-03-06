#ifndef NAVDATAHANDLER_H
#define NAVDATAHANDLER_H

#include "../ConnectionH/Frame.h"
#include "../ConnectionH/NavDataConnection.h"

#include <thread>
#include <future>

using namespace connection;

namespace handler {
	class NavDataHandler {
	public:
		NavDataHandler();
		static void run();
		virtual ~NavDataHandler() {};

	private :		
		static void wakeUp();
		static void receive();

	};
}

#endif;
