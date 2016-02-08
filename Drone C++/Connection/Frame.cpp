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

		int l = params.size();

		for (int i = 0 ; i < l ; i++) {
			frame.append(params.front());
			params.pop_front();

			if (i != l - 1) {
				frame.append(",");
			}
		}

		frame.append("\r");

		params.clear();
	}

	int Frame::floatToIntegerByteByByte(float f) {
		int result;
		::memcpy(&result, &f, sizeof(int));
		return result;
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
		params.push_back("\"general:navdata_demo\"");
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

	void Frame::hover() {
		com = "PCMD";
		params.push_back("1");
		params.push_back("0");
		params.push_back("0");
		params.push_back("0");
		params.push_back("0");
		buildFrameParams();
	}

	void Frame::move(float LR, float FB, float throttle, float yaw) {
		com = "PCMD";
		params.push_back("1");
		params.push_back(std::to_string(floatToIntegerByteByByte(LR)));
		params.push_back(std::to_string(floatToIntegerByteByByte(FB)));
		params.push_back(std::to_string(floatToIntegerByteByByte(throttle)));
		params.push_back(std::to_string(floatToIntegerByteByByte(yaw)));
		buildFrameParams();
	}
}
