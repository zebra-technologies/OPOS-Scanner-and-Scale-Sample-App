/*******************************************************************************************
*
* ©2016 Symbol Technologies LLC. All rights reserved.
*
********************************************************************************************/
// ScannerSDK_SampleApp_OPOS_Scanner.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "ScannerSDK_SampleApp_OPOS_Scanner.h"
#include "ScannerSDK_SampleApp_OPOS_Scanner_Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScannerSDK_SampleApp_OPOS_Scanner

BEGIN_MESSAGE_MAP(CScannerSDK_SampleApp_OPOS_Scanner, CWinApp)
	//{{AFX_MSG_MAP(CScannerSDK_SampleApp_OPOS_Scanner)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScannerSDK_SampleApp_OPOS_Scanner construction

CScannerSDK_SampleApp_OPOS_Scanner::CScannerSDK_SampleApp_OPOS_Scanner()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CScannerSDK_SampleApp_OPOS_Scanner object

CScannerSDK_SampleApp_OPOS_Scanner theApp;

/////////////////////////////////////////////////////////////////////////////
// CScannerSDK_SampleApp_OPOS_Scanner initialization

BOOL CScannerSDK_SampleApp_OPOS_Scanner::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	//Enable3dControls();		// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CScannerSDK_SampleApp_OPOS_Scanner_Dlg dlg;
	m_pMainWnd = &dlg;
	auto nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
