#ifndef DRONECONSTANT_H
#define DRONECONSTANT_H

#include <string>
#include <stdint.h>

class DroneConstant {

public:
	 const std::string addr = "10.78.0.16";
	 const std::string NavDataPort = "5554";
	 const std::string ATCommandPort = "5556";
	 const std::string VideoPort = "5555";
	 const std::string ConfigPort = "5559";

	 const size_t BuffLen = 1024;
};

#endif;
