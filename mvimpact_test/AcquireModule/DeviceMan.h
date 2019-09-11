#include "AcqModule.h"
#include "Capture.h"



typedef bool(*SUPPORTED_DEVICE_CHECK)(const mvIMPACT::acquire::Device* const);


class CDeviceMan {       // The class
public:             // Access specifier
	
	CDeviceMan();
	~CDeviceMan();

	int Play();
	int Stop();
	void UpdateLogInfo(std::string str);

	typedef enum { 
		eCamStop	= 0,
		eCamStart   = 1

	}CAMSTATUS;

	CAMSTATUS m_CamStatus;
	int Status()
	{return int(m_CamStatus);}

	//Arguments
	DeviceManager m_devMgr;
	std::vector<mvIMPACT::acquire::Device*> m_v_devices;
	Device* m_pDev;		//Pointer to Device
	CCapture m_Capture;


	std::string m_strLog;

	typedef struct _sCameraInfo
	{
		std::string DeviceClass;
		std::string Family;
		std::string Product;
		std::string Capabilities;
		std::string Serial;
		std::string State;
		std::string DeviceID;
		std::string DeviceVersion;
		std::string FirmwareVersion;
		std::string LoadSettings;
		std::string AutoLoadSettingOrder;
		std::string InterfaceLayout;
		std::string CustomDataDirectory;
		std::string DefaultRequestCount;
		std::string ResultQueueCount;
		std::string UserControlledImageProcessingEnable;
		std::string AllowUnrecommendedFeatures;
		std::string AcquisitionStartStopBehaviour;
		std::string HWUpdateResult;
		std::string Manufacturer;
		std::string ManufacturerSpecificInformation;
		std::string DesiredAccess;
		std::string GrantedAccess;


	}SCAMERAINFO;

	std::vector < SCAMERAINFO > STLvec_CameraInfo;


	//Methods
	bool Init();

public:

	bool ListCameras();

private:
	int RunSequence(void);


};

