#include "../ConnectionH/Frame.h"

namespace connection {
	Frame::Frame() {}

	Frame::~Frame() {}

	void Frame::buildFrame() {
		frame.clear();

		frame.append(Frame::prefix);
		frame.append(com);
		frame.append("=");

		frame.append(std::to_string(getCurrentSeqNumb()));
		seqNumb++;
		frame.append(",");

		frame.append("\r");
	}
	
	void Frame::buildFrameParams() {
		frame.clear();
		
		frame.append(Frame::prefix);
		frame.append(com);
		frame.append("=");

		frame.append(std::to_string(getCurrentSeqNumb()));
		seqNumb++;
		frame.append(",");

		for (int i = 0 ; i < params.size()+1 ; i++) {
			frame.append(params.front());
			params.pop_front();
		}

		frame.append("\r");

		params.clear();
	}

	int Frame::getFrameLength() {
		return frame.length();
	}

	const char* Frame::getFrame() {
		return frame.c_str();
	}

	int Frame::getCurrentSeqNumb() {
		return seqNumb;
	}

	void Frame::resetSeqNumb() {
		seqNumb = 1;
	}

	void Frame::navdataDemoMode() {
		com = "CONFIG";
		params.push_back("\"general:navdata_demo\",");
		params.push_back("\"TRUE\"");
		buildFrameParams();
	}	

	void Frame::takeoff() {
		com = "REF";
		params.push_back("290718208");
		buildFrameParams();
	}

	void Frame::land() {
		com = "REF";
		params.push_back("290717696");
		buildFrameParams();
	}

	void Frame::watchdog() {
		com = "COMWDG";
		buildFrame();
	}

	void Frame::fTrim() {
		com = "FTRIM";
		buildFrame();
	}

	void Frame::move() {
		com = "PCMD";
		//Frame frame("PCMD", "0,0,0,0,0.5");
	}
}
