/*******************************************************************************************
*
* ©2016 Symbol Technologies LLC. All rights reserved.
*
********************************************************************************************/
// Motorola_ScannerSDK_SampleApp_OPOS_Scale.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "ScannerSDK_SampleApp_OPOS_Scale.h"
#include "ScannerSDK_SampleApp_OPOS_Scale_Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMotorola_ScannerSDK_SampleApp_OPOS_Scale

BEGIN_MESSAGE_MAP(CMotorola_ScannerSDK_SampleApp_OPOS_Scale, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CMotorola_ScannerSDK_SampleApp_OPOS_Scale construction

CMotorola_ScannerSDK_SampleApp_OPOS_Scale::CMotorola_ScannerSDK_SampleApp_OPOS_Scale()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CMotorola_ScannerSDK_SampleApp_OPOS_Scale object

CMotorola_ScannerSDK_SampleApp_OPOS_Scale theApp;


// CMotorola_ScannerSDK_SampleApp_OPOS_Scale initialization

BOOL CMotorola_ScannerSDK_SampleApp_OPOS_Scale::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
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
