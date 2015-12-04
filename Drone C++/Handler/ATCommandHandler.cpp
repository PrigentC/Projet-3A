#include "../HandlerH/ATCommandHandler.h"

namespace handler {
	void ATCommandHandler::run() {
		takeOff();
		land();
	}

	void ATCommandHandler::takeOff() {
		atc.SendBuff.getBytes((char*) frame.takeoff().getFrameContent(), frame.getFrameLength());
		atc.sendDTGram();
	}

	void ATCommandHandler::land() {
		atc.SendBuff.getBytes((char*) frame.land().getFrameContent(), frame.getFrameLength());
		atc.sendDTGram();
	}
}