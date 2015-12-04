#ifndef DRONEHANDLER_H
#define DRONEHANDLER_H

#include <thread>
#include <future>

namespace handler {
	class DroneHandler {
	public :
		static void run();

	private :
		NavDataHandler navData;
		ATCommandHandler atc;

	};
}

#endif;