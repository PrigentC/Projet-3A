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


void f1(int n)
{
	for (int i = 0; i < 5; ++i) {
		std::cout << "Thread 1 executing\n";
		++n;
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}

void f2(int& n)
{
	for (int i = 0; i < 5; ++i) {
		std::cout << "Thread 2 executing\n";
		++n;
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}

void testThread() {
	int n = 0;
	//std::thread t1; // t1 is not a thread
	std::thread t2(f1, n + 1); // pass by value
	std::thread t3(f2, std::ref(n)); // pass by reference
	std::thread t4(std::move(t3)); // t4 is now running f2(). t3 is no longer a thread

	t2.join();
	t4.join();

	std::cout << "Final value of n is " << n << '\n';
}

int main()
{
	//testThread();
	
	AtCommandConnection atc;
	NavDataConnection nav;

	std::cout << "Wakeup data control" << std::endl;
	char wakeup[] = { 0x01, 0x00, 0x00, 0x00 };
	std::cout << wakeup << std::endl;

	std::cout << "Sending wakeup on navData" << std::endl;
	nav.SendBuff.putBytes(wakeup, 4);
	std::cout << nav.SendBuff << std::endl;
	std::cout << nav.SendBuff.farray() << std::endl;

	nav.sendDTGram();

	/*std::cout << "Listening to answer on navData" << std::endl;
	nav.recvDTGram();

	std::cout << "Answer on navData control" << std::endl;
	std::cout << nav.RecvBuff << std::endl;

	std::cout << std::endl;*/

	std::cin.ignore();
	std::cout << "Sending second message" << std::endl;

	std::cout << "Navdata_demo data control" << std::endl;
	char trame1[] = "AT*CONFIG=1,\"general:navdata_demo\",\"TRUE\"\r";
	std::cout << trame1 << std::endl;

	atc.SendBuff.putBytes(trame1, 43);

	std::cout << "Sending Navdata_demo on ATCommands" << std::endl;
	atc.sendDTGram();
	atc.SendBuff.clear();

	/*std::cout << "Listening to answer on navData" << std::endl;
	atc.recvDTGram();

	std::cout << "Answer on ATCommands control" << std::endl;
	std::cout << atc.RecvBuff << std::endl;

	std::cout << std::endl;*/


	std::cin.ignore();
	std::cout << "Sending third message (take off)" << std::endl;

	std::cout << "TakeOff data control" << std::endl;
	char trame3[] = "AT*REF=2,290718208\r";
	std::cout << trame3 << std::endl;
	atc.SendBuff.putBytes(trame3, 20);

	std::cout << "Sending TakeOff on ATCommands" << std::endl;
	atc.sendDTGram();
	atc.SendBuff.clear();


	std::cin.ignore();
	std::cout << "Sending fourth message (watchdog)" << std::endl;

	std::cout << "Watchdog data control" << std::endl;
	char trame4[] = "AT*COMWDG=3,\r";
	std::cout << trame4 << std::endl;
	atc.SendBuff.putBytes(trame4, 14);

	std::cout << "Sending WatchDog on ATCommands" << std::endl;
	atc.sendDTGram();
	atc.SendBuff.clear();


	std::cin.ignore();
	std::cout << "Sending fifth message (land)" << std::endl;

	std::cout << "Land data control" << std::endl;
	char trame5[] = "AT*REF=2,290717696\r";
	std::cout << trame5 << std::endl;
	atc.SendBuff.putBytes(trame5, 20);

	std::cout << "Sending Land on ATCommands" << std::endl;
	atc.sendDTGram();
	atc.SendBuff.clear();
}

