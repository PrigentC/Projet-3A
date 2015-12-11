#include "../ConnectionH/Frame.h"

namespace connection {
	Frame::Frame(std::string cmd) {
		frame.append(Frame::prefix);
		frame.append(cmd);
		frame.append("=");
		frame.append(std::to_string(Frame::seqNumb));
		frame.append("\r");
	}

	Frame::Frame(std::string cmd, std::string param) {
		frame.append(Frame::prefix);
		frame.append(cmd);
		frame.append("=");
		frame.append(std::to_string(Frame::seqNumb) + ",");
		frame.append(param);
		frame.append("\r");
	}

	Frame::~Frame() {}

	Frame Frame::buildFrame() {
		frame.append(Frame::prefix);
		frame.append(com);
		frame.append("=");
		frame.append(std::to_string(Frame::seqNumb));
		frame.append("\r");

		return frame;
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
		seqNumb = 0;
	}

	char* Frame::wakeup() {
		char wakeup[] = { 0x01, 0x00, 0x00, 0x00 };
		return wakeup;
	}

	void Frame::takeoff() {
		com = "REF";
		Frame f("REF", "290718208");
	}

	void Frame::land() {
		com = "REF";
		Frame f("REF", "290717696");
	}

	void Frame::watchdog() {
		com = "COMWDG";
	}

	void Frame::move() {
		com = "PCMD";
		Frame f("PCMD", "0,0,0,0,0.5");
	}
}
