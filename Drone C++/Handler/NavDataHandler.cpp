#include "../HandlerH/NavDataHandler.h"

namespace handler {
	NavDataHandler::NavDataHandler() {
	}

	void NavDataHandler::run() {
		WakeUp();
	}

	void NavDataHandler::WakeUp() {
		NavDataConnection nav;

		std::cout << "Wakeup data control" << std::endl;
		char wakeup[] = { 0x01, 0x00, 0x00, 0x00 };
		std::cout << wakeup << std::endl;

		std::cout << "Sending wakeup on navData" << std::endl;
		nav.SendBuff.putBytes(wakeup, 4);
		std::cout << nav.SendBuff << std::endl;
		std::cout << nav.SendBuff.farray() << std::endl;

		nav.sendDTGram();

		std::cin.ignore();
		
		//navData.RecvBuff.getBytes(frame.wakeup(), frame.getFrameLength());
		//navData.sendDTGram();
	}
}