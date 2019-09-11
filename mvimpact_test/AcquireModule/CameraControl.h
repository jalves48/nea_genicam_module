#include "AcqModule.h"

inline mvIMPACT::acquire::Device* getDeviceFromUserInput_(const mvIMPACT::acquire::DeviceManager& devMgr, int nDeviceID = 0, SUPPORTED_DEVICE_CHECK pSupportedDeviceCheckFn = 0, bool boSilent = false, bool boAutomaticallyUseGenICamInterface = true)
//-----------------------------------------------------------------------------
{
	const unsigned int devCnt = devMgr.deviceCount();
	if (devCnt == 0)
	{
		std::cout << "No compliant device found!" << std::endl;
		return 0;
	}

	std::set<unsigned int> validDeviceNumbers;

	// display every device detected that matches
	for (unsigned int i = 0; i < devCnt; i++)
	{
		Device* pDev = devMgr[i];
		if (pDev)
		{
			if (!pSupportedDeviceCheckFn || pSupportedDeviceCheckFn(pDev))
			{
				std::cout << "[" << i << "]: " << pDev->serial.read() << " (" << pDev->product.read() << ", " << pDev->family;
				if (pDev->interfaceLayout.isValid())
				{
					if (boAutomaticallyUseGenICamInterface)
					{
						// if this device offers the 'GenICam' interface switch it on, as this will
						// allow are better control over GenICam compliant devices
						conditionalSetProperty(pDev->interfaceLayout, dilGenICam, true);
					}
					std::cout << ", interface layout: " << pDev->interfaceLayout.readS();
				}
				if (pDev->acquisitionStartStopBehaviour.isValid())
				{
					// if this device offers a user defined acquisition start/stop behaviour
					// enable it as this allows finer control about the streaming behaviour
					conditionalSetProperty(pDev->acquisitionStartStopBehaviour, assbUser, true);
					std::cout << ", acquisition start/stop behaviour: " << pDev->acquisitionStartStopBehaviour.readS();
				}
				if (pDev->interfaceLayout.isValid() && !pDev->interfaceLayout.isWriteable())
				{
					if (pDev->isInUse())
					{
						std::cout << ", !!!ALREADY IN USE!!!";
					}
				}
				std::cout << ")" << std::endl;
				validDeviceNumbers.insert(i);
			}
		}
	}

	if (validDeviceNumbers.empty())
	{
		std::cout << devMgr.deviceCount() << " devices have been detected:" << std::endl;
		for (unsigned int i = 0; i < devCnt; i++)
		{
			Device* pDev = devMgr[i];
			if (pDev)
			{
				std::cout << "  [" << i << "]: " << pDev->serial.read() << " (" << pDev->product.read() << ", " << pDev->family << ")" << std::endl;
			}
		}
		std::cout << "However none of these devices seems to be supported by this sample." << std::endl << std::endl;
		return 0;
	}

	// get user input
	//std::cout << std::endl << "Please enter the number in front of the listed device followed by [ENTER] to open it: ";
	unsigned int devNr = 0;
	//std::cin >> devNr;
	devNr = nDeviceID;
	// remove the '\n' from the stream
	std::cin.get();

	if (validDeviceNumbers.find(devNr) == validDeviceNumbers.end())
	{
		std::cout << "Invalid selection!" << std::endl;
		return 0;
	}

	if (!boSilent)
	{
		std::cout << "Using device number " << devNr << "." << std::endl;
	}
	return devMgr[devNr];
}
