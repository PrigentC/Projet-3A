#ifndef FRAME_H
#define FRAME_H

#include <string>

namespace connection {
	class Frame {
	public:
		Frame(std::string cmd);
		Frame(std::string cmd, std::string param);
		~Frame();

		int getFrameLength();
		const char* getFrameContent();
		int getCurrentSeqNumb();
		std::string getFrame();
		void resetSeqNumb();

		char* wakeup();
		Frame takeoff();
		Frame land();
		Frame watchdog();
		//Frame navdata_demomode();

	private:
		std::string frame;
		const std::string prefix = "AT*";
		int seqNumb;
	};
}


#endif
