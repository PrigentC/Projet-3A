#include "../HandlerH/DroneHandler.h"

namespace handler {
	DroneHandler::DroneHandler() {}

	void DroneHandler::run() {
		NavDataHandler *navData;
		ATCommandHandler *atc;
		try {
			std::cout << "ca marche" << std::endl;

			std::async(std::launch::async, &navData->run);
			std::async(std::launch::async, &atc->run);
		}
		catch (std::exception e) {
			e.what();
		}
	}
}