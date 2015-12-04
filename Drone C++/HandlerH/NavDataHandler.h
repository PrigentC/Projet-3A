#ifndef NAVDATAHANDLER_H
#define NAVDATAHANDLER_H

#include "../ConnectionH/Frame.h"
#include "../ConnectionH/NavDataConnection.h"

#include <thread>
#include <future>

namespace handler {
	class NavDataHandler {
	public:
		void run();

	private :
		connection::NavDataConnection navData;
		connection::Frame frame;
		
		void WakeUp();
	};
}

#endif;
