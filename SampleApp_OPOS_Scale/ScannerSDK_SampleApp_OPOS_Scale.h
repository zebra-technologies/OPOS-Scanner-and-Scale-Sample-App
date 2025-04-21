/*******************************************************************************************
*
* ©2016 Symbol Technologies LLC. All rights reserved.
*
********************************************************************************************/
// Motorola_ScannerSDK_SampleApp_OPOS_Scale.h : main header file for the SCANNERSDK_SAMPLEAPP_OPOS_SCALE application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols

// CMotorola_ScannerSDK_SampleApp_OPOS_Scale:
// See Motorola_ScannerSDK_SampleApp_OPOS_Scale.cpp for the implementation of this class
//

class CMotorola_ScannerSDK_SampleApp_OPOS_Scale : public CWinApp
{
public:
	CMotorola_ScannerSDK_SampleApp_OPOS_Scale();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMotorola_ScannerSDK_SampleApp_OPOS_Scale theApp;