#include "../HandlerH/NavDataHandler.h"

namespace handler {
	NavDataHandler::NavDataHandler() {
	}

	void NavDataHandler::run() {
		std::cout << "Navdata handler started and working";
		WakeUp();
	}

	void NavDataHandler::receive() {
		std::cout << "Navdata handler listening to Drone" << std::endl;

//		ReceiveNavData();
	}

	void NavDataHandler::WakeUp() {
		NavDataConnection nav;

		std::cout << std::endl << "Sending wakeup on navData";
		nav.wakeUp();
		std::cin.ignore();

		// FORCES THREAD TO YIELD FOR NAVDATA DEMO MODE !
		std::this_thread::yield;

		std::cout << std::endl << "Listening to answer on navData" << std::endl;
		nav.recvDTGram();
		std::cout << std::endl;

		std::cout << "Answer on navData control" << std::endl;
		std::cout << nav.RecvBuff << std::endl;

	}
}