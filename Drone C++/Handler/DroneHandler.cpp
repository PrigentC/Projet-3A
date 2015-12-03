#include "../HandlerH/DroneHandler.h"
#include "../HandlerH/NavDataHandler.h"
#include "../HandlerH/ATCommandHandler.h"

namespace handler {
	void DroneHandler::run() {
		NavDataHandler::run();
		ATCommandHandler::run();
	}
}