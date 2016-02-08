#ifndef FLIGHTINPUT_H
#define FLIGHTINPUT_H

#include"windows.h"
#include "spwmacro.h"
#include "si.h"
#include "siapp.h"

#include <iostream>
#include <list>

namespace mouse3D {
	class FlightInput {
	public:
		std::list<float> pitch;
		std::list<float> roll;
		std::list<float> throttle;
		std::list<float> yaw;

		FlightInput();
		~FlightInput();

		int initialize(HWND);
		void listen();

		float getNormalizedTX(long); // -3500 / 3100
		float getNormalizedTY(long); // -3500 / 2700
		float getNormalizedTZ(long); // -4100 / 3600
		float getNormalizedRX(long); // -2500 / 3200
		float getNormalizedRY(long); // -2900 / 3900
		float getNormalizedRZ(long); // -3100 / 2800

		static bool initState;

		LRESULT CALLBACK MyWndCBProc(HWND, UINT, WPARAM, LPARAM);

	private:
		SiHdl       devHdl;       /* Handle to 3D Mouse Device */
		SiOpenData oData;

		void  SbMotionEvent(SiSpwEvent *pEvent);
		void  SbZeroEvent();
		void  SbButtonPressEvent(int buttonnumber);
		void  SbButtonReleaseEvent(int buttonnumber);
		void  HandleDeviceChangeEvent(SiSpwEvent *pEvent);

		long getTX(SiSpwEvent*);
		long getTY(SiSpwEvent*);
		long getTZ(SiSpwEvent*);
		long getRX(SiSpwEvent*);
		long getRY(SiSpwEvent*);
		long getRZ(SiSpwEvent*);

	};
}


#endif
