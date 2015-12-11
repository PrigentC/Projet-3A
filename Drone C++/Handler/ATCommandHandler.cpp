#include "../HandlerH/ATCommandHandler.h"

namespace handler {
	ATCommandHandler::ATCommandHandler() {}

	void ATCommandHandler::run() {
		takeOff();
		watchdog();
		land();
	}

	void ATCommandHandler::takeOff() {
		AtCommandConnection atc;
		
		std::cout << "Sending second message (take off)" << std::endl;

		std::cout << "TakeOff data control" << std::endl;
		char trame3[] = "AT*REF=2,290718208\r";
		std::cout << trame3 << std::endl;
		atc.SendBuff.putBytes(trame3, 20);

		std::cout << "Sending TakeOff on ATCommands" << std::endl;
		atc.sendDTGram();
		atc.SendBuff.clear();

		std::cin.ignore();

		//atc.SendBuff.getBytes((char*) frame.takeoff().getFrameContent(), frame.getFrameLength());
		//atc.sendDTGram();
	}

	void ATCommandHandler::watchdog() {
		AtCommandConnection atc;
	
		std::cout << "Sending third message (watchdog)" << std::endl;

		std::cout << "Watchdog data control" << std::endl;
		char trame4[] = "AT*COMWDG=3,\r";
		std::cout << trame4 << std::endl;
		atc.SendBuff.putBytes(trame4, 14);

		std::cout << "Sending WatchDog on ATCommands" << std::endl;
		atc.sendDTGram();
		atc.SendBuff.clear();

		std::cin.ignore();

		//atc.SendBuff.getBytes((char*) frame.land().getFrameContent(), frame.getFrameLength());
		//atc.sendDTGram();
	}

	void ATCommandHandler::land() {
		AtCommandConnection atc;
		
		std::cout << "Sending fifth message (land)" << std::endl;

		std::cout << "Land data control" << std::endl;
		char trame5[] = "AT*REF=2,290717696\r";
		std::cout << trame5 << std::endl;
		atc.SendBuff.putBytes(trame5, 20);

		std::cout << "Sending Land on ATCommands" << std::endl;
		atc.sendDTGram();
		atc.SendBuff.clear();

		std::cin.ignore();

		//atc.SendBuff.getBytes((char*) frame.land().getFrameContent(), frame.getFrameLength());
		//atc.sendDTGram();
	}
}