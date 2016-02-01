#include "../HandlerH/DroneHandler.h"

namespace handler {
	DroneHandler::DroneHandler() {}

	void DroneHandler::run() {
		int i = 0;
		try {
			std::cout << "Drone handler started and working" << std::endl;

			std::thread navRun(&navData->run);
			std::thread atcRun(&atc->run);
			navRun.join();
			atcRun.join();
		}
		catch (std::exception e) {
			e.what();
		}
	}
}