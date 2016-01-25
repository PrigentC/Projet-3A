#include "../HandlerH/NavDataHandler.h"

namespace handler {
	NavDataHandler::NavDataHandler() {
	}

	void NavDataHandler::run() {
		std::cout << "Navdata handler started and working" << std::endl;
		
		WakeUp();
	}

	void NavDataHandler::receive() {
		std::cout << "Navdata handler listening to Drone" << std::endl;

		ReceiveNavData();
	}

	void NavDataHandler::WakeUp() {
		NavDataConnection nav;

		std::cout << "Sending wakeup on navData" << std::endl;
		nav.wakeUp();
		std::cin.ignore();
	}

	void NavDataHandler::ReceiveNavData() {
		NavDataConnection nav;

		std::cout << "Listening to answer on navData" << std::endl;
		nav.recvDTGram();

		std::cout << "Answer on navData control" << std::endl;
		std::cout << nav.RecvBuff << std::endl;

		std::cout << std::endl;
	}
}