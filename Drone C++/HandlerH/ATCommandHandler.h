#ifndef ATCOMMANDHANDLER_H
#define ATCOMMANDHANDLER_H

#include "../ConnectionH/ATCommandConnection.h"
#include "../ConnectionH/Frame.h"
#include "../3DMouseH/FlightInput.h"

#include <thread>
#include <future>
#include "spwmacro.h"
#include "si.h"
#include "siapp.h"

using namespace connection;
using namespace mouse3D;

namespace handler {
	class ATCommandHandler {
	public:
		ATCommandHandler();
		static void run();
		virtual ~ATCommandHandler() {};

	private :
		static void navDataDemoMode();
		static void takeOff();
		static void watchdog();
		static void land();
		static void fTrim();
		static void move();
	};
}

#endif;
