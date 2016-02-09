#include "../3DMouseH/FlightInput.h"

using namespace mouse3D;

static FlightInput* sharePtr;

/* Creating a hack callback becuase we cant assign callback to local function MyWndCBProc */
static LRESULT Callback(HWND hwnd, UINT wm, WPARAM wParam, LPARAM lParam) {
	//if ( FlightInput::initState )
	{
		FlightInput * self = static_cast<FlightInput*>(sharePtr);
		return self->MyWndCBProc(hwnd, wm, wParam, lParam);
	}
	//return NULL;
}

bool FlightInput::initState = false; // Not yet initialized. so check this flag before processing callback function.

FlightInput::FlightInput() {
	HWND windowHandle = GetConsoleWindow();

	sharePtr = this;
	/* Register a custom window class */
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = (WNDPROC)(&Callback);
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = GetModuleHandle(NULL);
	wcex.hIcon = NULL;
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = L"MyWindowClassName";
	wcex.hIconSm = NULL;
	RegisterClassEx(&wcex);

	/* Create a hidden window owned by our process and parented to the console window */
	HWND hWndChild = CreateWindow(wcex.lpszClassName, L"MyWindowTitle", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, wcex.hInstance, NULL);

	initialize(hWndChild);
	initState = true;
}

FlightInput::~FlightInput() {
	SiClose(devHdl);
	SiTerminate();
}

int FlightInput::initialize(HWND hwndC) {
	int res;                             /* result of SiOpen, to be returned  */

										 /*init the SpaceWare input library */
	if (SiInitialize() == SPW_DLL_LOAD_ERROR) {
		std::cout << "Error: Could not load SiAppDll dll files" << std::endl;
	} else {
		//std::cout << "SiInitialize() done " << std::endl;
	}

	SiOpenWinInit(&oData, hwndC);    /* init Win. platform specific data  */

									 /* open data, which will check for device type and return the device handle to be used by this function */
	if ((devHdl = SiOpen("AppSpaceMouse.exe", SI_ANY_DEVICE, SI_NO_MASK, SI_EVENT, &oData)) == NULL) {
		std::cout << "SiOpen error:" << std::endl;
		SiTerminate();  /* called to shut down the SpaceWare input library */
		std::cout << "SiTerminate()" << std::endl;
		res = 0;        /* could not open device */
		return res;
	}

	SiDeviceName pname;
	SiGetDeviceName(devHdl, &pname);
	//std::cout << "devicename =  " << pname.name << std::endl;

	SiSetUiMode(devHdl, SI_UI_ALL_CONTROLS); /* Config SoftButton Win Display */
	SiGrabDevice(devHdl, SPW_TRUE); /* PREVENTS OTHER APPLICATIONS FROM RECEIVING 3D CONNEXION DATA !!! */
	res = 1;        /* opened device succesfully */
	return res;
}

void FlightInput::listen() {
	/* Implement message loop */
	int bRet;
	MSG msg;      /* incoming message to be evaluated */

	int i = 0;

	std::cout << "TX=0 TY=0 TZ=0 RX=0 RY=0 RZ=0" << std::endl;

	while (bRet = GetMessage(&msg, NULL, 0, 0)) {
		if (bRet == -1) {
			/* handle the error and possibly exit */
			return;
		} else {
			if (i > 1) {
				break;
			}

			i++;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}

long FlightInput::getTX(SiSpwEvent * pEvent) {
	return pEvent->u.spwData.mData[SI_TX];
}

long FlightInput::getTY(SiSpwEvent * pEvent) {
	return pEvent->u.spwData.mData[SI_TY];
}

long FlightInput::getTZ(SiSpwEvent * pEvent) {
	return pEvent->u.spwData.mData[SI_TZ];
}

long FlightInput::getRX(SiSpwEvent * pEvent) {
	return pEvent->u.spwData.mData[SI_RX];
}

long FlightInput::getRY(SiSpwEvent * pEvent) {
	return pEvent->u.spwData.mData[SI_RY];
}

long FlightInput::getRZ(SiSpwEvent * pEvent) {
	return pEvent->u.spwData.mData[SI_RZ];
}

float FlightInput::getNormalizedTX(long TX) {
	float posMax = 3100;
	float negMax = -3500;

	if (TX > posMax) {
		posMax = TX;
	}

	if (TX < negMax) {
		negMax = TX;
	}

	if (TX < 0) {
		return -TX / negMax;
	} else {
		return TX / posMax;
	}
}

float FlightInput::getNormalizedTY(long TY) {
	float posMax = 2700;
	float negMax = -3500;

	if (TY > posMax) {
		posMax = TY;
	}

	if (TY < negMax) {
		negMax = TY;
	}

	if (TY < 0) {
		return -TY / negMax;
	} else {
		return TY / posMax;
	}
}

float FlightInput::getNormalizedTZ(long TZ) {
	float posMax = 3600;
	float negMax = -4100;

	if (TZ > posMax) {
		posMax = TZ;
	}

	if (TZ < negMax) {
		negMax = TZ;
	}

	if (TZ < 0) {
		return -TZ / negMax;
	} else {
		return TZ / posMax;
	}
}

float FlightInput::getNormalizedRX(long RX) {
	float posMax = 3200;
	float negMax = -2500;

	if (RX > posMax) {
		posMax = RX;
	}

	if (RX < negMax) {
		negMax = RX;
	}

	if (RX < 0) {
		return -RX / negMax;
	} else {
		return RX / posMax;
	}
}

float FlightInput::getNormalizedRY(long RY) {
	float posMax = 3900;
	float negMax = -2900;

	if (RY > posMax) {
		posMax = RY;
	}

	if (RY < negMax) {
		negMax = RY;
	}

	if (RY < 0) {
		return -RY / negMax;
	} else {
		return RY / posMax;
	}
}

float FlightInput::getNormalizedRZ(long RZ) {
	float posMax = 2800;
	float negMax = -3100;

	if (RZ > posMax) {
		posMax = RZ;
	}

	if (RZ < negMax) {
		negMax = RZ;
	}

	if (RZ < 0) {
		return -RZ / negMax;
	} else {
		return RZ / posMax;
	}
}

LRESULT FlightInput::MyWndCBProc(HWND hwnd, UINT wm, WPARAM wParam, LPARAM lParam) {
	SiSpwEvent     Event;    /* SpaceWare Event */
	SiGetEventData EData;    /* SpaceWare Event Data */

							 /* initialize Window platform specific data for a call to SiGetEvent */
	SiGetEventWinInit(&EData, wm, wParam, lParam);

	/* check whether wm was a 3D mouse event and process it */
	//if (SiGetEvent (devHdl, SI_AVERAGE_EVENTS, &EData, &Event) == SI_IS_EVENT)
	SpwRetVal retval = SiGetEvent(devHdl, 0, &EData, &Event);


	if (retval == SI_IS_EVENT) {
		if (Event.type == SI_MOTION_EVENT) {
			SbMotionEvent(&Event);        /* process 3D mouse motion event */
		} else if (Event.type == SI_ZERO_EVENT) {
			SbZeroEvent();                /* process 3D mouse zero event */
		} else if (Event.type == SI_BUTTON_PRESS_EVENT) {
			SbButtonPressEvent(Event.u.hwButtonEvent.buttonNumber);  /* process button press event */
		} else if (Event.type == SI_BUTTON_RELEASE_EVENT) {
			SbButtonReleaseEvent(Event.u.hwButtonEvent.buttonNumber); /* process button release event */
		} else if (Event.type == SI_DEVICE_CHANGE_EVENT) {
			//SbHandleDeviceChangeEvent(&Event); /* process 3D mouse device change event */
		}
	}

	return DefWindowProc(hwnd, wm, wParam, lParam);
}

void  FlightInput::SbMotionEvent(SiSpwEvent *pEvent) {
	std::cout << "TX=" << getNormalizedTX(getTX(pEvent))
		<< " TY=" << getNormalizedTY(getTY(pEvent))
		<< " TZ=" << getNormalizedTZ(getTZ(pEvent))
		<< " RX=" << getNormalizedRX(getRX(pEvent))
		<< " RY=" << getNormalizedRY(getRY(pEvent))
		<< " RZ=" << getNormalizedRZ(getRZ(pEvent)) << std::endl;


	pitch = getNormalizedTX(getTX(pEvent));
	roll = getNormalizedTZ(getTZ(pEvent));
	yaw = getNormalizedRZ(getRZ(pEvent));
	throttle = getNormalizedTY(getTY(pEvent));
}

void  FlightInput::SbZeroEvent() {
	std::cout << "TX=0 TY=0 TZ=0 RX=0 RY=0 RZ=0" << std::endl;
}

void  FlightInput::SbButtonPressEvent(int buttonnumber) {
	std::cout << "Buttonnumber : " << buttonnumber << std::endl;
}

void  FlightInput::SbButtonReleaseEvent(int buttonnumber) {
	std::cout << "Buttonnumber : " << buttonnumber << std::endl;
}

void  FlightInput::HandleDeviceChangeEvent(SiSpwEvent *pEvent) {
	std::cout << "HandleDeviceChangeEvent : " << std::endl;
}
