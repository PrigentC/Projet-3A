/*
* Copyright (c) 2011 Jean-Marc Perronne
* Ensisa, 12 rue des Freres Lumieres, F-68093 Mulhouse cedex
* All rights reserved.
*
* The copyright of this software is owned by Werner Randelshofer.
* You may not use, copy or modify this software, except in
* accordance with the license agreement you entered into with
* Jean-Marc Perronne. For details see accompanying license terms.
*/

#ifndef DRONECONSTANTS_H
#define DRONECONSTANTS_H

#include <string>

class DroneConstants
{
public :
	
	//network
	const std::string WIFI_ARDRONE_IP = "192.168.1.1";
	const std::string NETWORK_INTERFACE = "en1"; //wifi nerwork interface

	const int UDP_AT_BUFFER_SIZE = 2048;
	const int UDP_NAV_BUFFER_SIZE = 2048;
	const int UDP_VIDEO_BUFFER_SIZE = 64000;
	const int TCP_CONFIG_BUFFER_SIZE = 4096;

	const int UDP_TIMEOUT = 1000;

	const int AT_COMMAND_PORT = 5556;
	const int VIDEO_PORT = 5555;
	const int NAVDATA_PORT = 5554;
	const int CONTROL_PORT = 5559;

	const unsigned char WAKEUP_BYTES[4] = { 0x01, 0x00, 0x00, 0x00 };


	//Navadata

	 const int NAVDATA_HEADER = 0x55667788;

	 const int NAVDATA_DEMO_TAG = 0;
	 const int NAVDATA_TIME_TAG = 1;
	 const int NAVDATA_RAW_MEASURES_TAG = 2;
	 const int NAVDATA_PHYS_MEASURES_TAG = 3;
	 const int NAVDATA_GYROS_OFFSETS_TAG = 4;
	 const int NAVDATA_EULER_ANGLES_TAG = 5;
	 const int NAVDATA_REFERENCES_TAG = 6;
	 const int NAVDATA_TRIMS_TAG = 7;
	 const int NAVDATA_RC_REFERENCES_TAG = 8;
	 const int NAVDATA_PWM_TAG = 9;
	 const int NAVDATA_ALTITUDE_TAG = 10;
	 const int NAVDATA_VISION_RAW_TAG = 11;
	 const int NAVDATA_VISION_OF_TAG = 12;
	 const int NAVDATA_VISION_TAG = 13;
	 const int NAVDATA_VISION_PERF_TAG = 14;
	 const int NAVDATA_TRACKERS_SEND_TAG = 15;
	 const int NAVDATA_VISION_DETECT_TAG = 16;
	 const int NAVDATA_WATCHDOG_TAG = 17;
	 const int NAVDATA_ADC_DATA_FRAME_TAG = 18;
	 const int NAVDATA_VIDEO_STREAM_TAG = 19;

	 const int NAVDATA_CKS_TAG = 0xFFFF;

	//boot
	 const int MAX_BOOT_RETRY = 20;

	//at commands
	 const int AT_REFRESH_MS = 30;
	 const int AT_ALTITUDE = 2000;

	//recorders
	 const std::string RECORDS_DIR = System.getProperty("user.dir") + "/records";

	 const std::string NAVDATA_RECORDS_DIR = RECORDS_DIR + "/navdata";
	 const std::string NAVDATA_DEMO_RECORDS_DIR = NAVDATA_RECORDS_DIR + "/demo/";

	 const std::string NAVDATA_DEMO_EXT = "txt";
	 const char NAVDATA_DEMO_SEPARATOR = ' ';

	 const std::string PICTURE_WRITER_FORMAT = "png";

	 const std::string VIDEO_RECORDS_DIR = RECORDS_DIR + "/videos/";
	 const std::string PICTURES_RECORDS_DIR = RECORDS_DIR + "/pictures/";
	 const std::string CONFIGS_RECORDS_DIR = RECORDS_DIR + "/configs/";

	 const std::string CONFIGS_EXT = "txt";
	 const std::string DEFAULT_CONFIGS_FILE_NAME = "drone_configs";

	//consumers keys
	 const std::string NAVDATA_DEMO_RECORDER_KEY = "navadata_demo_recorder";
	 const std::string PICTURE_RECORDER_KEY = "picture_recorder";
	 const std::string VIDEO_RECORDER_KEY = "video_recorder";
	 const std::string DRONE_CONFIG_RECORDER_KEY = "drone_config_recorder";
	 const std::string COCKPIT_KEY = "cockpit";

	//Video data
	 const int VIDEO_FRAMERATE = 15;
}

#endif

