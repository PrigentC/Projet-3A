#include "../HandlerH/DroneHandler.h"

namespace handler {
	DroneHandler::DroneHandler() {}

	void DroneHandler::run() {
		NavDataHandler *navData;
		ATCommandHandler *atc;
		try {
			std::cout << "Drone handler started and working" << std::endl;

			std::async(std::launch::async, &navData->run);
			std::async(std::launch::async, &atc->run);
			std::async(std::launch::async, &navData->receive);
		}
		catch (std::exception e) {
			e.what();
		}
	}
}