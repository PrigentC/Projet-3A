#include "../ConnectionH/ATCommandConnection.h"

namespace connection {
	AtCommandConnection::AtCommandConnection() {
		SendToAddr.sin_port = htons(5556);
		SendToAddr.sin_addr.s_addr = inet_addr("192.168.1.1");

		RecvFromAddr.sin_port = htons(5556);
		RecvFromAddr.sin_addr.s_addr = inet_addr("192.168.1.2");

		addr = "192.168.1.1";
		port = 5556;
	}

	AtCommandConnection::~AtCommandConnection() {
		closesocket(ConnectSocket);
		WSACleanup();
	}

	void AtCommandConnection::navdataDemoMode() {
		std::cout << "Navdata_demo data control" << std::endl;
		//char trame1[] = "AT*CONFIG=1,\"general:navdata_demo\",\"TRUE\"\r";
		frame.navdataDemoMode();
		frame.buildFrameParams();
		std::cout << frame.getFrame() << std::endl;

		SendBuff.putBytes(frame.getFrame(), frame.getFrameLength());

		std::cout << "Sending Navdata_demo on ATCommands" << std::endl;
		sendDTGram();
		SendBuff.clear();
	}

	void AtCommandConnection::takeOff() {
		std::cout << "TakeOff data control" << std::endl;
		//char trame3[] = "AT*REF=2,290718208\r";
		frame.takeoff();
		frame.buildFrameParams();
		std::cout << frame.getFrame() << std::endl;
		SendBuff.putBytes(frame.getFrame(), frame.getFrameLength());

		std::cout << "Sending TakeOff on ATCommands" << std::endl;
		sendDTGram();
		SendBuff.clear();
	}

	void AtCommandConnection::land() {
		std::cout << "Land data control" << std::endl;
		//char trame5[] = "AT*REF=2,290717696\r";
		frame.land();
		frame.buildFrameParams();
		std::cout << frame.getFrame() << std::endl;
		SendBuff.putBytes(frame.getFrame(), frame.getFrameLength());

		std::cout << "Sending Land on ATCommands" << std::endl;
		sendDTGram();
		SendBuff.clear();
	}

	void AtCommandConnection::watchDog() {
		std::cout << "Watchdog data control" << std::endl;
		//char trame4[] = "AT*COMWDG=3,\r";
		frame.watchdog();
		frame.buildFrame();
		std::cout << frame.getFrame() << std::endl;
		SendBuff.putBytes(frame.getFrame(), frame.getFrameLength());

		std::cout << "Sending WatchDog on ATCommands" << std::endl;
		sendDTGram();
		SendBuff.clear();
	}

	void AtCommandConnection::fTrim() {
		std::cout << "FTrim for stabilizing" << std::endl;
		//char trame4[] = "AT*FTRIM=3,\r";
		frame.fTrim();
		frame.buildFrame();
		std::cout << frame.getFrame() << std::endl;
		SendBuff.putBytes(frame.getFrame(), frame.getFrameLength());

		std::cout << "Sending FTrim on ATCommands" << std::endl;
		sendDTGram();
		SendBuff.clear();
	}
}


