#ifndef FRAME_H
#define FRAME_H

#include <string>
#include <list>

namespace connection {
	class Frame {
	public:
		Frame();
		~Frame();

		void buildFrame();
		void buildFrameParams();

		int getFrameLength();
		const char* getFrame();

		int getCurrentSeqNumb();
		void resetSeqNumb();

		char* wakeup();
		void navdataDemoMode();
		void takeoff();
		void land();
		void watchdog();
		void move();

	private:
		std::string frame;
		const std::string prefix = "AT*";
		std::string com;
		int seqNumb;
		std::list<std::string> params;
	};
}


#endif