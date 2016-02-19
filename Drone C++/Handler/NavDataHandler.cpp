#include "../HandlerH/NavDataHandler.h"

namespace handler {
	NavDataConnection nav;

	NavDataHandler::NavDataHandler() {
	}

	void NavDataHandler::run() {
		std::cout << "Navdata handler started and working";
		wakeUp();
		std::this_thread::yield;
		receive();
	}

	void NavDataHandler::wakeUp() {
		std::cout << std::endl << "Sending wakeup on navData";
		nav.wakeUp();
		std::cin.ignore();
	}

	void NavDataHandler::receive() {
		std::cout << std::endl << "Listening to answer on navData" << std::endl;
		nav.recvDTGram();
		std::cout << std::endl;

		std::cout << "Answer on navData control" << std::endl;
		std::cout << nav.RecvBuff << std::endl;
	}
}