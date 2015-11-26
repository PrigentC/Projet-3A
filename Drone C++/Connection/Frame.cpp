#include "../ConnectionH/Frame.h"

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
	frame.append(std::to_string(Frame::seqNumb)+",");
	frame.append(param);
	frame.append("\r");
}

Frame::~Frame() {}

int Frame::getTrameLength() {
	return frame.length();
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

Frame Frame::takeoff() {
	Frame f("REF", "290718208");
	return f;
}

Frame Frame::land() {
	Frame f("REF", "290717696");
	return f;
}

Frame Frame::watchdog() {
	Frame f("COMWDG");
	return f;
}



