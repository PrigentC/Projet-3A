#ifndef FRAME_H
#define FRAME_H

#include <string>

class Frame {
public :
	Frame(std::string cmd);
	Frame(std::string cmd, std::string param);
	~Frame();

	int getTrameLength();
	int getCurrentSeqNumb();
	void resetSeqNumb();

	static char* wakeup();
	static Frame takeoff();
	static Frame land();
	static Frame watchdog();
	//static Frame navdata_demomode();

private :
	std::string frame;
	const std::string prefix = "AT*";
	int seqNumb;


};

#endif
