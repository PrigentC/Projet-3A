#ifndef FRAME_H
#define FRAME_H

#include <string>
#include <list>

namespace connection {
	class Frame {
	public:
		Frame();
		~Frame();

		int getFrameLength();
		const char* getFrame();

		int getCurrentSeqNumb();
		void resetSeqNumb();

		void navdataDemoMode();
		void takeoff();
		void land();
		void watchdog();
		void fTrim();
		void move();

	private:
		std::string frame;
		const std::string prefix = "AT*";
		std::string com;
		int seqNumb = 1;
		std::list<std::string> params;

		void buildFrame();
		void buildFrameParams();
	};
}


#endif