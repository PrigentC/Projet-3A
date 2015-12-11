#ifndef DRONEHANDLER_H
#define DRONEHANDLER_H

#include "../HandlerH/NavDataHandler.h"
#include "../HandlerH/ATCommandHandler.h"

#include <thread>
#include <future>

namespace handler {
	class DroneHandler {
	public :
		DroneHandler();
		static void run();
		virtual ~DroneHandler() {};

	};
}

#endif;