#ifndef ATCOMMANDHANDLER_H
#define ATCOMMANDHANDLER_H

#include "../ConnectionH/ATCommandConnection.h"
#include "../ConnectionH/Frame.h"

#include <thread>
#include <future>

namespace handler {
	class ATCommandHandler {
	public:
		void run();

	private :
		connection::AtCommandConnection atc;
		connection::Frame frame;

		void takeOff();
		void land();
	};
}

#endif;
