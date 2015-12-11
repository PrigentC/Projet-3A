#ifndef FRAME_H
#define FRAME_H

#include <string>
#include <list>

namespace connection {
	class Frame {
	public:
		Frame(std::string cmd);
		Frame(std::string cmd, std::string param);
		~Frame();

		Frame buildFrame();

		int getFrameLength();
		const char* getFrame();

		int getCurrentSeqNumb();
		void resetSeqNumb();

		char* wakeup();
		void takeoff();
		void land();
		void watchdog();
		//Frame navdata_demomode();
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