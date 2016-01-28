#ifndef ATCOMMANDHANDLER_H
#define ATCOMMANDHANDLER_H

#include "../ConnectionH/ATCommandConnection.h"
#include "../ConnectionH/Frame.h"

#include <thread>
#include <future>

using namespace connection;

namespace handler {
	class ATCommandHandler {
	public:
		ATCommandHandler();
		static void run();
		static void watchdogThread();
		virtual ~ATCommandHandler() {};

	private :
		static void navDataDemoMode();
		static void takeOff();
		static void watchdog();
		static void land();
		static void fTrim();
	};
}

#endif;
