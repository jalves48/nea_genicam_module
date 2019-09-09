#include "..\stdafx.h"
#include "Camera.h"
#include <apps/Common/exampleHelper.h>
#include <functional>
#include <iostream>
#include <mvIMPACT_CPP/mvIMPACT_acquire_helper.h>


#ifdef _WIN32
#   include <mvDisplay/Include/mvIMPACT_acquire_display.h>
using namespace mvIMPACT::acquire::display;
#   define USE_DISPLAY
#endif // #ifdef _WIN32

using namespace mvIMPACT::acquire;
using namespace std;


CCamera::CCamera() {     // Constructor
	//cout << "Hello World!";
}

CCamera::~CCamera() {     // Destructor
	//cout << "By World!";
}

bool CCamera::Init()
{
	ListCameras();

	

	return true;
}

bool CCamera::ListCameras()
{
	m_v_devices.clear();
	getValidDevices(m_devMgr, m_v_devices);

	STLvec_CameraInfo.clear();

	// display every device detected that matches
	for (unsigned int i = 0; i < m_v_devices.size(); i++)
	{
		SCAMERAINFO sCameraInfo;
		Device* pDev = m_v_devices[i];
		if (pDev)
		{
			sCameraInfo.DeviceClass			= pDev->deviceClass.readS();	
			sCameraInfo.Family				= pDev->family.readS();
			sCameraInfo.Product				= pDev->product.readS();;
			sCameraInfo.Capabilities		= pDev->capabilities.readS();	
			sCameraInfo.Serial				= pDev->serial.readS();
			sCameraInfo.State				= pDev->state.readS();
			sCameraInfo.DeviceID			= pDev->deviceID.readS();
			sCameraInfo.DeviceVersion		= pDev->deviceVersion.readS();
			sCameraInfo.FirmwareVersion		= pDev->firmwareVersion.readS();
			sCameraInfo.LoadSettings		= pDev->loadSettings.readS();



			STLvec_CameraInfo.push_back(sCameraInfo);
		}
	}

	return 0;
}