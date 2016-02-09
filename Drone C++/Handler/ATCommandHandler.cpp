#include "../HandlerH/ATCommandHandler.h"

namespace handler {
	AtCommandConnection atc;

	ATCommandHandler::ATCommandHandler() {}

	void ATCommandHandler::run() {
		std::cout << std::endl << "AtCommand handler started and working" << std::endl;

		navDataDemoMode();
		fTrim();
		takeOff();
		//watchdog();
		move();
		land();
	}

	void ATCommandHandler::navDataDemoMode() {
		std::cout << "Sending NavDataDemoMode on ATCommands" << std::endl;
		atc.navdataDemoMode();
		std::cin.ignore();
	}

	void ATCommandHandler::takeOff() {
		std::cout << "Sending TakeOff on ATCommands" << std::endl;
		atc.takeOff();
		std::cin.ignore();
	}

	void ATCommandHandler::watchdog() {
		std::cout << "Sending WatchDog on ATCommands" << std::endl;
		atc.watchDog();
		std::cin.ignore();
	}

	void ATCommandHandler::land() {
		std::cout << "Sending Land on ATCommands" << std::endl;
		atc.land();
		std::cin.ignore();
	}

	void ATCommandHandler::fTrim() {
		std::cout << "Sending fTrim on ATCommands" << std::endl;
		atc.fTrim();
		std::cin.ignore();
	}

	void ATCommandHandler::move() {
		FlightInput fi;

		int i = 0;

		/*while (i < 10) {
			atc.move(-0.4, 0, 0, 0);
			i++;
		}*/

		while (i < 300) {
			fi.listen();

			std::cout << "Sending move on ATCommands" << std::endl;
			atc.move(fi.pitch, fi.roll, fi.yaw, fi.throttle);

			i++;
		}


		land();

		std::cin.ignore();

	}
}