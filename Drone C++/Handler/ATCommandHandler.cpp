#include "../HandlerH/ATCommandHandler.h"

namespace handler {
	ATCommandHandler::ATCommandHandler() {}

	void ATCommandHandler::run() {
		std::cout << "AtCommand handler started and working" << std::endl;

		navDataDemoMode();
		/*fTrim();
		takeOff();
		watchdog();
		land();*/
	}

	void ATCommandHandler::navDataDemoMode() {
		AtCommandConnection atc;

		std::cout << "Sending NavDataDemoMode on ATCommands" << std::endl;
		atc.navdataDemoMode();
		std::cin.ignore();
	}

	void ATCommandHandler::takeOff() {
		AtCommandConnection atc;
		
		std::cout << "Sending TakeOff on ATCommands" << std::endl;
		atc.takeOff();
		std::cin.ignore();
	}

	void ATCommandHandler::watchdog() {
		AtCommandConnection atc;
		
		std::cout << "Sending WatchDog on ATCommands" << std::endl;
		atc.watchDog();
		std::cin.ignore();
	}

	void ATCommandHandler::land() {
		AtCommandConnection atc;

		std::cout << "Sending Land on ATCommands" << std::endl;
		atc.land();
		std::cin.ignore();
	}

	void ATCommandHandler::fTrim() {
		AtCommandConnection atc;

		std::cout << "Sending fTrim on ATCommands" << std::endl;
		atc.fTrim();
		std::cin.ignore();
	}
}