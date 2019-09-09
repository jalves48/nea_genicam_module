
// mvimpact_test.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Cmvimpact_testApp:
// See mvimpact_test.cpp for the implementation of this class
//

class Cmvimpact_testApp : public CWinApp
{
public:
	Cmvimpact_testApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Cmvimpact_testApp theApp;