// Drone C++.cpp : définit le point d'entrée pour l'application console.
//

#include "STDEXCPT.h"
#include "ConnectionH\AtCommandConnection.h"
#include "ConnectionH\NavDataConnection.h"
#include "ConnectionH\Frame.h"

#include <thread>

#include <winsock2.h>
#include <WS2tcpip.h>

#include <iostream>

#include "HandlerH\DroneHandler.h"

using namespace buffer;
using namespace connection;
using namespace handler;

void test() {
	AtCommandConnection atc;
	NavDataConnection nav;

	atc.connectUDPServer();
	nav.connectUDPServer();

	/* ------------------------------------------------------------------- */
	std::cout << "Sending first message (wakeup)" << std::endl;

	nav.wakeUp();

	std::cin.ignore();

	/* ------------------------------------------------------------------- */
	std::cout << "Sending second message (NavData Demo Mode)" << std::endl;

	atc.navdataDemoMode();

	std::cin.ignore();

	/* ------------------------------------------------------------------- */

	std::cout << "Listening to answer on navData" << std::endl;
	//nav.recvDTGram();

	/*std::cout << "Answer on ATCommands control" << std::endl;
	std::cout << nav.RecvBuff << std::endl;

	std::cout << std::endl;*/

	/* ------------------------------------------------------------------- */
	std::cout << "Sending third message (ftrim)" << std::endl;

	atc.fTrim();

	std::cin.ignore();

	/* ------------------------------------------------------------------- */
	std::cout << "Sending fourth message (take off)" << std::endl;

	atc.takeOff();

	std::cin.ignore();

	/* ------------------------------------------------------------------- */
	std::cout << "Sending fifth message (watchdog)" << std::endl;

	atc.watchDog();

	std::cin.ignore();

	/* ------------------------------------------------------------------- */
	std::cout << "Sending sixth message (hover)" << std::endl;

	atc.hover();

	std::cin.ignore();

	/* ------------------------------------------------------------------- */
	/*std::cout << "Sending seventh message (moving right)" << std::endl;

	atc.move(0.1, 0, 0, 0);

	std::cin.ignore();*/

	/* ------------------------------------------------------------------- */
	std::cout << "Sending seventh message (moving ahead)" << std::endl;

	atc.move(0, 0.5, 0, 0);

	std::cin.ignore();

	/* ------------------------------------------------------------------- */
	/*std::cout << "Sending seventh message (moving up)" << std::endl;

	atc.move(0, 0, 0.1, 0);

	std::cin.ignore();*/

	/* ------------------------------------------------------------------- */
	/*std::cout << "Sending seventh message (rotation)" << std::endl;

	atc.move(0, 0, 0, 0.3);

	std::cin.ignore();*/

	/* ------------------------------------------------------------------- */
	std::cout << "Sending eighth message (land)" << std::endl;

	atc.land();
}

int main()
{	
	test();
	
	/*DroneHandler *droneHandler;
	droneHandler->run();
	std::cin.ignore();*/
	return 0;
}

