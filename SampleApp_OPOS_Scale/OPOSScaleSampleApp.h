/*******************************************************************************************
*
* ©2016 Symbol Technologies LLC. All rights reserved.
*
********************************************************************************************/
// MotorolaOPOSScaleSampleApp.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols

// CMotorolaOPOSScaleSampleAppApp:
// See MotorolaOPOSScaleSampleApp.cpp for the implementation of this class
//

class CMotorolaOPOSScaleSampleAppApp : public CWinApp
{
public:
	CMotorolaOPOSScaleSampleAppApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMotorolaOPOSScaleSampleAppApp theApp;