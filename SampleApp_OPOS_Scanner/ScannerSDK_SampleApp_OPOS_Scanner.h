/*******************************************************************************************
*
* ©2016 Symbol Technologies LLC. All rights reserved.
*
********************************************************************************************/
// ScannerSDK_SampleApp_OPOS_Scanner.h : main header file for the SCANNERSDK_SAMPLEAPP_OPOS_SCANNER application
//

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CScannerSDK_SampleApp_OPOS_Scanner:
// See ScannerSDK_SampleApp_OPOS_Scanner.cpp for the implementation of this class
//

class CScannerSDK_SampleApp_OPOS_Scanner : public CWinApp
{
public:
	CScannerSDK_SampleApp_OPOS_Scanner();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScannerSDK_SampleApp_OPOS_Scanner)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CScannerSDK_SampleApp_OPOS_Scanner)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////
