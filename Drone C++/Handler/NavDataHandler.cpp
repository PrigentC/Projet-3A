#include "../HandlerH/NavDataHandler.h"

namespace handler {
	void NavDataHandler::run() {
		WakeUp();
	}

	void NavDataHandler::WakeUp() {
		navData.RecvBuff.getBytes(frame.wakeup(), frame.getFrameLength());
		navData.sendDTGram();
	}
}