// Drone C++.cpp : définit le point d'entrée pour l'application console.
//

#include "STDEXCPT.h"
#include "ConnectionH\AtCommandConnection.h"
#include "ConnectionH\NavDataConnection.h"
#include "ConnectionH\Frame.h"
#include "3DMouseH\FlightInput.h"

#include <thread>

#include <winsock2.h>
#include <WS2tcpip.h>

#include <iostream>

#include "HandlerH\DroneHandler.h"

using namespace buffer;
using namespace connection;
using namespace handler;

void navTest() {
	AtCommandConnection atc;
	NavDataConnection nav;

	atc.connectUDPServer();
	nav.connectUDPServer();

	/* -------------------------------------------------------- */
	std::cout << "Sending first message (wakeup)" << std::endl;
	nav.wakeUp();
	std::cin.ignore();

	/* -------------------------------------------------------- */
	std::cout << "Sending second message (navData Demo Mode)" << std::endl;
	atc.navdataDemoMode();
	std::cin.ignore();

	/* -------------------------------------------------------- */
	std::cout << "Listening to answer on navData" << std::endl;
	//nav.recvDTGram();

	/*std::cout << "Answer on ATCommands control" << std::endl;
	std::cout << nav.RecvBuff << std::endl;

	std::cout << std::endl;*/
	std::cin.ignore();

	/* -------------------------------------------------------- */
	std::cout << "Sending third message (ftrim)" << std::endl;
	atc.fTrim();
	std::cin.ignore();

	/* -------------------------------------------------------- */
	std::cout << "Sending fourth message (take off)" << std::endl;
	atc.takeOff();
	std::cin.ignore();

	/* -------------------------------------------------------- */
	/*std::cout << "Sending message (watchdog)" << std::endl;
	atc.watchDog();
	std::cin.ignore();*/

	/* -------------------------------------------------------- */
	/*std::cout << "Sending  message (hover)" << std::endl;
	atc.hover();
	std::cin.ignore();*/

	/* -------------------------------------------------------- */
	std::cout << "Sending message (move right)" << std::endl;
	atc.move(0.2, 0, 0, 0);
	std::cin.ignore();

	/* -------------------------------------------------------- */
	/*std::cout << "Sending message (move back)" << std::endl;
	atc.move(0, 0.2, 0, 0);
	std::cin.ignore();*/

	/* -------------------------------------------------------- */
	/*std::cout << "Sending message (move up)" << std::endl;
	atc.move(0, 0, 0.2, 0);
	std::cin.ignore();*/

	/* -------------------------------------------------------- */
	/*std::cout << "Sending message (rotation)" << std::endl;
	atc.move(0, 0, 0, 0.2);
	std::cin.ignore();*/

	/* -------------------------------------------------------- */
	std::cout << "Sending last message (land)" << std::endl;
	atc.land();
	std::cin.ignore();
}

void test() {
	AtCommandConnection atc;
	NavDataConnection nav;
	mouse3D::FlightInput fi;

	atc.connectUDPServer();
	nav.connectUDPServer();

	/* -------------------------------------------------------- */
	std::cout << "Sending first message (wakeup)" << std::endl;
	nav.wakeUp();
	std::cin.ignore();

	/* -------------------------------------------------------- */
	std::cout << "Sending second message (navData Demo Mode)" << std::endl;
	atc.navdataDemoMode();
	std::cin.ignore();

	/* -------------------------------------------------------- */
	std::cout << "Listening to answer on navData" << std::endl;
	//nav.recvDTGram();

	/*std::cout << "Answer on ATCommands control" << std::endl;
	std::cout << nav.RecvBuff << std::endl;

	std::cout << std::endl;*/
	std::cin.ignore();
	
	/* -------------------------------------------------------- */
	std::cout << "Sending third message (ftrim)" << std::endl;
	atc.fTrim();
	std::cin.ignore();

	/* -------------------------------------------------------- */
	std::cout << "Sending fourth message (take off)" << std::endl;
	atc.takeOff();

	/* -------------------------------------------------------- */
	/*std::cout << "Sending message (watchdog)" << std::endl;
	atc.watchDog();
	std::cin.ignore();*/

	/* -------------------------------------------------------- */
	/*std::cout << "Sending  message (hover)" << std::endl;
	atc.hover();
	std::cin.ignore();*/

	/* -------------------------------------------------------- */
	/*std::cout << "Sending message (move right)" << std::endl;
	atc.move(0.2, 0, 0, 0);
	std::cin.ignore();*/

	/* -------------------------------------------------------- */
	/*std::cout << "Sending message (move back)" << std::endl;
	atc.move(0, 0.2, 0, 0);
	std::cin.ignore();*/

	/* -------------------------------------------------------- */
	/*std::cout << "Sending message (move up)" << std::endl;
	atc.move(0, 0, 0.2, 0);
	std::cin.ignore();*/

	/* -------------------------------------------------------- */
	/*std::cout << "Sending message (rotation)" << std::endl;
	atc.move(0, 0, 0, 0.2);
	std::cin.ignore();*/

	/* -------------------------------------------------------- */
	int i = 0;

	while (i < 400) {
		fi.listen();

		atc.move(fi.pitch, fi.roll, fi.yaw, fi.throttle);

		i++;
	}
	
	std::cout << std::endl;

	/* -------------------------------------------------------- */
	std::cout << "Sending last message (land)" << std::endl;
	atc.land();
	std::cin.ignore();
}

int main()
{	
	//test();
	
	DroneHandler *droneHandler;
	droneHandler->run();
	std::cin.ignore();
	return 0;
}

