/*******************************************************************************************
*
* ©2016 Symbol Technologies LLC. All rights reserved.
*
********************************************************************************************/
// ScannerSDK_SampleApp_OPOS_Scanner_Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "ScannerSDK_SampleApp_OPOS_Scanner.h"
#include "ScannerSDK_SampleApp_OPOS_Scanner_Dlg.h"
#include "OpenSODialog.h"
#include <chrono>
#include <sstream>
#include <iomanip>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//Maximum value for a variable of type long
#define MAX_LONG_VALUE L"2147483647"

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

const LONG PIDX_NUMBER = 0;
const LONG PIDX_Claimed = 1 + PIDX_NUMBER;
const LONG PIDX_DataEventEnabled = 2 + PIDX_NUMBER;
const LONG PIDX_DeviceEnabled = 3 + PIDX_NUMBER;
const LONG PIDX_FreezeEvents = 4 + PIDX_NUMBER;
const LONG PIDX_OutputID = 5 + PIDX_NUMBER;
const LONG PIDX_ResultCode = 6 + PIDX_NUMBER;
const LONG PIDX_ResultCodeExtended = 7 + PIDX_NUMBER;
const LONG PIDX_ServiceObjectVersion = 8 + PIDX_NUMBER;
const LONG PIDX_State = 9 + PIDX_NUMBER;

//      Added for Release 1.2:
const LONG PIDX_AutoDisable = 10 + PIDX_NUMBER;
const LONG PIDX_BinaryConversion = 11 + PIDX_NUMBER;
const LONG PIDX_DataCount = 12 + PIDX_NUMBER;

//      Added for Release 1.3:
const LONG PIDX_PowerNotify = 13 + PIDX_NUMBER;
const LONG PIDX_PowerState = 14 + PIDX_NUMBER;

const LONG PISY = 0;
const LONG    PIDX_CapPowerReporting = 15 + PISY;//+PIDX_NUMBER  

const LONG    PIDXScan_DecodeData = 16 + PISY;//+PIDX_NUMBER
const LONG    PIDXScan_ScanDataType = 17 + PISY;//+PIDX_NUMBER 


const LONG PIDX_CheckHealthText = 1 + PISY + 17;
const LONG PIDX_DeviceDescription = 2 + PISY + 17;
const LONG PIDX_DeviceName = 3 + PISY + 17;
const LONG PIDX_ServiceObjectDescription = 4 + PISY + 17;
const LONG PIDXScan_ScanData = 5 + PISY + 17;
const LONG PIDXScan_ScanDataLabel = 6 + PISY + 17;


const LONG PIDXScan_ControlObjectDescription = 7 + PISY + 17;
const LONG PIDXScan_ControlObjectVersion = 8 + PISY + 17;

const LONG PIDX_CapStatisticsReporting = 9 + PISY + 17;
const LONG PIDX_CapUpdateStatistics = 10 + PISY + 17;

const LONG PIDX_CapCompareFirmwareVersion = 11 + PISY + 17;
const LONG PIDX_CapUpdateFirmware = 12 + PISY + 17;

class DataBinder
{
public:
	typedef BOOL(COPOSScanner::* fpTypeOPOSGetterBool)(void);
	typedef void (COPOSScanner::* fpTypeOPOSSetterBool)(BOOL);
	typedef long (COPOSScanner::* fpTypeOPOSGetterLong)(void);
	typedef void (COPOSScanner::* fpTypeOPOSSetterLong)(long);
	typedef CString(COPOSScanner::* fpTypeOPOSGetterString)(void);
	typedef CY(COPOSScanner::* fpTypeOPOSGetterCurrency)(void);
	typedef void (COPOSScanner::* fpTypeOPOSSetterCurrency)(CY);


	COPOSScanner* pCScale_;

	fpTypeOPOSGetterBool fpGetterBool_;
	fpTypeOPOSSetterBool fpSetterBool_;
	fpTypeOPOSGetterLong fpGetterLong_;
	fpTypeOPOSSetterLong fpSetterlong_;
	fpTypeOPOSGetterString fpGetterString_;
	fpTypeOPOSGetterCurrency fpGetterCurrency_;
	fpTypeOPOSSetterCurrency fpSetterCurrency_;

	enum OPOSDataTypes
	{
		dtBool,
		dtLong,
		dtString,
		dtCurrency,
	};

	OPOSDataTypes dt;
	BOOL bIsReadOnly;


	DataBinder(COPOSScanner* pScaleObj, fpTypeOPOSGetterBool fpGetterBool, fpTypeOPOSSetterBool fpSetterBool = NULL) : pCScale_(pScaleObj), fpGetterBool_(fpGetterBool), fpSetterBool_(fpSetterBool)
	{
		bIsReadOnly = true;
		dt = dtBool;
		if (fpSetterBool)
		{
			bIsReadOnly = false;
		}
	}
	DataBinder(COPOSScanner* pScaleObj, fpTypeOPOSGetterLong fpGetterLong, fpTypeOPOSSetterLong fpSetterLong = NULL) : pCScale_(pScaleObj), fpGetterLong_(fpGetterLong), fpSetterlong_(fpSetterLong)
	{
		bIsReadOnly = true;
		dt = dtLong;
		if (fpSetterLong)
		{
			bIsReadOnly = false;
		}
	}

	DataBinder(COPOSScanner* pScaleObj, fpTypeOPOSGetterCurrency fpGetterCurrency, fpTypeOPOSSetterCurrency fpSetterCurrency = NULL) : pCScale_(pScaleObj), fpGetterCurrency_(fpGetterCurrency), fpSetterCurrency_(fpSetterCurrency)
	{
		bIsReadOnly = true;
		dt = dtCurrency;
		if (fpSetterCurrency)
		{
			bIsReadOnly = false;
		}
	}
	DataBinder(COPOSScanner* pScaleObj, fpTypeOPOSGetterString fpGetterString) : pCScale_(pScaleObj), fpGetterString_(fpGetterString)
	{
		dt = dtString;
		bIsReadOnly = true;
	}

	BOOL ExecGetterBool()
	{
		return (pCScale_->*fpGetterBool_)();
	}
	void ExecSetterBool(BOOL param)
	{
		(pCScale_->*fpSetterBool_)(param);
	}
	long ExecGetterLong()
	{
		return (pCScale_->*fpGetterLong_)();
	}
	void ExecSetterLong(long param)
	{
		(pCScale_->*fpSetterlong_)(param);
	}
	CY ExecGetterCurrency()
	{
		return (pCScale_->*fpGetterCurrency_)();
	}
	void ExecSetterCurrency(CY param)
	{
		(pCScale_->*fpSetterCurrency_)(param);
	}
	CString ExecGetterString()
	{
		return (pCScale_->*fpGetterString_)();
	}

};

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

	// Dialog Data
		//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScannerSDK_SampleApp_OPOS_Scanner_Dlg dialog

CScannerSDK_SampleApp_OPOS_Scanner_Dlg::CScannerSDK_SampleApp_OPOS_Scanner_Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CScannerSDK_SampleApp_OPOS_Scanner_Dlg::IDD, pParent)
	, m_defaultScannerIDXML(NULL)
{
	//{{AFX_DATA_INIT(CScannerSDK_SampleApp_OPOS_Scanner_Dlg)
	m_strProperty = _T("");
	m_strReturnValue = _T("");
	m_strResultCode = _T("");
	m_strScanDataLabel = _T("");
	m_nUIEventCount = 0;
	m_nGoodScanCount = 0;
	m_statisticsFilter = _T(""); //SSDK-19840 - Implementing retrieve statistics filter
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON_OPOS_MSA);//IDR_MAINFRAME);
	m_nReturnValue = 0;
	m_nEventCount = 0;
	m_iScanCount = 0;
}

void CScannerSDK_SampleApp_OPOS_Scanner_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScannerSDK_SampleApp_OPOS_Scanner_Dlg)
	DDX_Control(pDX, IDC_PROPERTIES_COMBO, m_ctProp);
	DDX_Control(pDX, IDC_EDIT1, m_editScanData);
	DDX_Text(pDX, IDC_PRO_EDIT, m_strProperty);
	DDX_Text(pDX, IDC_RETURN_EDIT, m_strReturnValue);
	DDX_Text(pDX, IDC_RESULT_CODE_EDIT, m_strResultCode);
	DDX_Text(pDX, IDC_SCANDATALABE_EDIT, m_strScanDataLabel);
	//DDX_Text(pDX, IDC_EVENT_COUNT_EDIT, m_nUIEventCount);
	DDX_Control(pDX, IDC_SCANNER1, m_ctrlScanner);
	DDX_Text(pDX, IDC_STATISTICS_FILTER, m_statisticsFilter); //SSDK-19840 - Implementing retrieve statistics filter
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_CHECK_AutoEvtEnable, m_check_DataEventAutoenable);
	DDX_Control(pDX, IDC_EDIT_Scan_Count, m_edit_ScanCount);
	DDX_Control(pDX, IDC_EDIT_OutXML, m_editOutXML);
	DDX_Control(pDX, IDC_EDIT_InXML, m_editInXml);
	DDX_Control(pDX, IDC_EDIT_CSstatus, m_editCSstatus);
	DDX_Control(pDX, IDC_EDIT_LOGVIEW, m_editLogView);
}

BEGIN_MESSAGE_MAP(CScannerSDK_SampleApp_OPOS_Scanner_Dlg, CDialog)
	//{{AFX_MSG_MAP(CScannerSDK_SampleApp_OPOS_Scanner_Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OPENSO, OnOpenSO)
	ON_UPDATE_COMMAND_UI(IDC_EDIT1, OnUpdateEdit)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_CBN_SELCHANGE(IDC_PROPERTIES_COMBO, OnSelchangePropertiesCombo)
	ON_BN_CLICKED(IDC_SET_BUTTON, OnSetButton)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_CLAIM_BUTTON, OnClaimButton)
	ON_BN_CLICKED(IDC_RELEASE_BUTTON, OnReleaseButton)
	ON_BN_CLICKED(IDC_CHECK_HEALTH_BUTTON, OnCheckHealthButton)
	ON_BN_CLICKED(IDC_LEAR_INPUT_BUTTON, OnLearInputButton)
	//ON_BN_CLICKED(IDC_CLEAR_BUTTON, OnClearButton)
	ON_BN_CLICKED(IDC_EVENT_ENABLE_BUTTON, OnEventEnableButton)
	ON_BN_CLICKED(IDC_CL_BUTTON, OnClButton)
	ON_BN_CLICKED(IDC_DECODE_BUTTON, OnDecodeButton)
	ON_BN_CLICKED(IDC_RETRIEV_BUTTON, OnRetrievButton)
	ON_BN_CLICKED(IDC_UPDATE_STATIS_BUTTON, OnUpdateStatisButton)
	ON_BN_CLICKED(IDC_RESET_STAT_BUTTON, OnResetStatButton)
	ON_BN_CLICKED(IDC_INPUT_BUTTON, OnInputButton)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_CLOSE_BUTTON, &CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnBnClickedCloseButton)
	ON_BN_CLICKED(IDC_CHECK_AutoEvtEnable, &CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnBnClickedCheckAutoevtenable)
	ON_CBN_SELCHANGE(IDC_COMBO_DIO_OpCodes, &CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnCbnSelchangeComboDioOpcodes)
	ON_BN_CLICKED(IDC_BUTTON_Execute, &CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnBnClickedButtonExecute)
	ON_BN_CLICKED(IDC_BUTTON_Clear, &CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_CheckHealth, &CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnBnClickedButtonCheckhealth)
	ON_BN_CLICKED(IDC_BUTTON_CH_Intercative, &CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnBnClickedButtonChIntercative)
	ON_EN_CHANGE(IDC_UPDATE_EDIT, &CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnEnChangeUpdateEdit)
	ON_BN_CLICKED(IDC_BUTTON5, &CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnBnClickedClearLog)
	ON_COMMAND(IDCANCEL, OnCancelOverride)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScannerSDK_SampleApp_OPOS_Scanner_Dlg message handlers

BOOL CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

#if defined(_WIN64)
#define MY_CAPTION L"Scanner SDK Sample Application OPOS Scanner (64bit)"
#else
#define MY_CAPTION L"Scanner SDK Sample Application OPOS Scanner (32bit)"
#endif
	SetWindowText(MY_CAPTION);

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	CString strAboutMenu;
	strAboutMenu.LoadString(IDS_ABOUTBOX);
	if (!strAboutMenu.IsEmpty())
	{
		pSysMenu->AppendMenu(MF_SEPARATOR);
		pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	m_bIsOpen = FALSE;
	UpdateDialogControls(this, FALSE);
	LoadPropertyList();

	//disable the sacn label txt box- first text box

	 //get the hander of control 
	 //ctl0=GetDlgItem(IDC_SCANDATALABE_EDIT);
	 //if (ctl0) ctl0->EnableWindow(FALSE);

	//disable the sacn data type  txt box- second text box
	CWnd* ctl1;
	//get the hander of control 
	ctl1 = GetDlgItem(IDC_EDIT1);
	if (ctl1) ctl1->EnableWindow(FALSE);


	//disable the return value label txt box- third text box
	CWnd* ctl2;
	//get the hander of control 
	ctl2 = GetDlgItem(IDC_RETURN_EDIT);
	if (ctl2) ctl2->EnableWindow(FALSE);

	//disable the result code label txt box- fourth text box
	CWnd* ctl3;
	//get the hander of control 
	ctl3 = GetDlgItem(IDC_RESULT_CODE_EDIT);
	if (ctl3) ctl3->EnableWindow(FALSE);

	UpdateData(FALSE);
	SetupDirectIO();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{


	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();

	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM)dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnQueryDragIcon()
{
	return (HCURSOR)m_hIcon;
}

BEGIN_EVENTSINK_MAP(CScannerSDK_SampleApp_OPOS_Scanner_Dlg, CDialog)
	//{{AFX_EVENTSINK_MAP(CScannerSDK_SampleApp_OPOS_Scanner_Dlg)
	ON_EVENT(CScannerSDK_SampleApp_OPOS_Scanner_Dlg, IDC_SCANNER1, 1 /* DataEvent */, OnDataEventScanner1, VTS_I4)
	//}}AFX_EVENTSINK_MAP
	ON_EVENT(CScannerSDK_SampleApp_OPOS_Scanner_Dlg, IDC_SCANNER1, 5, CScannerSDK_SampleApp_OPOS_Scanner_Dlg::StatusUpdateEventScanner1, VTS_I4)
	ON_EVENT(CScannerSDK_SampleApp_OPOS_Scanner_Dlg, IDC_SCANNER1, 2, CScannerSDK_SampleApp_OPOS_Scanner_Dlg::DirectIOEventScanner1, VTS_I4 VTS_PI4 VTS_PBSTR)
END_EVENTSINK_MAP()

void CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnDataEventScanner1(long lStatus)
{
	// The control fired an event. Get the new data
	CString straa = _T("");
	CString strScanData = _T("");
	CString strScanDataLabel = _T("");
	CString strType;

	++m_nEventCount;
	m_nUIEventCount = m_nEventCount;

	//get the sana data, and update the UI
	strType = GetScanDataType(m_ctrlScanner.GetScanDataType());

	strScanData = strType;

	strScanDataLabel = m_ctrlScanner.GetScanDataLabel();

	CString scanDataTypeDigit; //DNS-169
	scanDataTypeDigit.Format(L"%d", m_ctrlScanner.GetScanDataType());

	//get the scan data
	m_editScanData.SetWindowText(scanDataTypeDigit + L" (" + strScanData + L")");
	m_strScanDataLabel = m_ctrlScanner.GetScanDataLabel();

	LPWSTR t = m_strScanDataLabel.GetBuffer();

	if (BST_CHECKED == m_check_DataEventAutoenable.GetCheck())
	{
		m_ctrlScanner.SetDataEventEnabled(TRUE);
	}
	wchar_t chBuff[5];
	_itow_s(++m_iScanCount, chBuff, sizeof(chBuff), 10);
	m_edit_ScanCount.SetWindowText(chBuff);
	//update the UI with new scaned values
	UpdateData(FALSE);
}

void CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnOpenSO()
{
	COpenSODialog dlg;


	//dlg.m_strSOName = "ZEBRA_SCANNER";

	//Gien a device name, corretly
	if (dlg.DoModal() == IDOK)
	{
		if (m_bIsOpen)
		{
			if (m_ctrlScanner.Close() == 0)
				m_bIsOpen = FALSE;
			else
			{
				::AfxMessageBox(IDS_ERROR);
				return;
			}
		}

		scannerProfile = dlg.m_strSOName; //DNS-174

		//call the open method with given values
		m_nReturnValue = m_ctrlScanner.Open(dlg.m_strSOName);

		//error has occured
		if (m_nReturnValue)
		{
			CString strTemp;
			strTemp.Format(L"open%d", m_nReturnValue);
		}

		m_iScanCount = 0;

		if (m_nReturnValue == OPOS_SUCCESS)
		{
			GetDlgItem(IDC_CHECK_AutoEvtEnable)->EnableWindow(TRUE);
		}

		//update with return values
		UpdateState();

		m_check_DataEventAutoenable.SetCheck(BST_UNCHECKED);
		UpdateDialogControls(this, FALSE);
	}
}

void CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnUpdateEdit(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(m_bIsOpen);
}

void CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnButton1()
{
	//enable the device
	m_ctrlScanner.SetDeviceEnabled(TRUE);

	UpdateState();

}

void CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnButton2()
{
	//diable the device
	m_ctrlScanner.SetDeviceEnabled(FALSE);
	UpdateState();
}

short CScannerSDK_SampleApp_OPOS_Scanner_Dlg::LoadPropertyList()
{
	long nCell = 0;
	CString strProperty = _T("");
	m_ctProp.SetItemData(m_ctProp.AddString(L"PIDX_Claimed"), (DWORD_PTR) new DataBinder(&m_ctrlScanner, &COPOSScanner::GetClaimed));
	m_ctProp.SetItemData(m_ctProp.AddString(L"PIDX_DataEventEnabled"), (DWORD_PTR) new DataBinder(&m_ctrlScanner, &COPOSScanner::GetDataEventEnabled, &COPOSScanner::SetDataEventEnabled));
	m_ctProp.SetItemData(m_ctProp.AddString(L"PIDX_DeviceEnabled"), (DWORD_PTR) new DataBinder(&m_ctrlScanner, &COPOSScanner::GetDeviceEnabled, &COPOSScanner::SetDeviceEnabled));
	m_ctProp.SetItemData(m_ctProp.AddString(L"PIDX_FreezeEvents"), (DWORD_PTR) new DataBinder(&m_ctrlScanner, &COPOSScanner::GetFreezeEvents, &COPOSScanner::SetFreezeEvents));
	m_ctProp.SetItemData(m_ctProp.AddString(L"PIDX_ResultCode"), (DWORD_PTR) new DataBinder(&m_ctrlScanner, &COPOSScanner::GetResultCode));
	m_ctProp.SetItemData(m_ctProp.AddString(L"PIDX_ResultCodeExtended"), (DWORD_PTR) new DataBinder(&m_ctrlScanner, &COPOSScanner::GetResultCodeExtended));
	m_ctProp.SetItemData(m_ctProp.AddString(L"PIDX_ServiceObjectVersion"), (DWORD_PTR) new DataBinder(&m_ctrlScanner, &COPOSScanner::GetServiceObjectVersion));
	m_ctProp.SetItemData(m_ctProp.AddString(L"PIDX_State"), (DWORD_PTR) new DataBinder(&m_ctrlScanner, &COPOSScanner::GetState));

	m_ctProp.SetItemData(m_ctProp.AddString(L"PIDX_AutoDisable"), (DWORD_PTR) new DataBinder(&m_ctrlScanner, &COPOSScanner::GetAutoDisable, &COPOSScanner::SetAutoDisable));
	m_ctProp.SetItemData(m_ctProp.AddString(L"PIDX_BinaryConversion"), (DWORD_PTR) new DataBinder(&m_ctrlScanner, &COPOSScanner::GetBinaryConversion, &COPOSScanner::SetBinaryConversion));
	m_ctProp.SetItemData(m_ctProp.AddString(L"PIDX_DataCount"), (DWORD_PTR) new DataBinder(&m_ctrlScanner, &COPOSScanner::GetDataCount));

	m_ctProp.SetItemData(m_ctProp.AddString(L"PIDX_PowerNotify"), (DWORD_PTR) new DataBinder(&m_ctrlScanner, &COPOSScanner::GetPowerNotify, &COPOSScanner::SetPowerNotify));
	m_ctProp.SetItemData(m_ctProp.AddString(L"PIDX_PowerState"), (DWORD_PTR) new DataBinder(&m_ctrlScanner, &COPOSScanner::GetPowerState));

	m_ctProp.SetItemData(m_ctProp.AddString(L"PIDX_CapPowerReporting"), (DWORD_PTR) new DataBinder(&m_ctrlScanner, &COPOSScanner::GetCapPowerReporting));
	m_ctProp.SetItemData(m_ctProp.AddString(L"PIDXScan_DecodeData"), (DWORD_PTR) new DataBinder(&m_ctrlScanner, &COPOSScanner::GetDecodeData, &COPOSScanner::SetDecodeData));
	m_ctProp.SetItemData(m_ctProp.AddString(L"PIDXScan_ScanDataType"), (DWORD_PTR) new DataBinder(&m_ctrlScanner, &COPOSScanner::GetScanDataType));

	m_ctProp.SetItemData(m_ctProp.AddString(L"PIDX_CheckHealthText"), (DWORD_PTR) new DataBinder(&m_ctrlScanner, &COPOSScanner::GetCheckHealthText));
	m_ctProp.SetItemData(m_ctProp.AddString(L"PIDX_DeviceDescription"), (DWORD_PTR) new DataBinder(&m_ctrlScanner, &COPOSScanner::GetDeviceDescription));
	m_ctProp.SetItemData(m_ctProp.AddString(L"PIDX_DeviceName"), (DWORD_PTR) new DataBinder(&m_ctrlScanner, &COPOSScanner::GetDeviceName));
	m_ctProp.SetItemData(m_ctProp.AddString(L"PIDX_ServiceObjectDescription"), (DWORD_PTR) new DataBinder(&m_ctrlScanner, &COPOSScanner::GetServiceObjectDescription));
	m_ctProp.SetItemData(m_ctProp.AddString(L"PIDXScan_ScanData"), (DWORD_PTR) new DataBinder(&m_ctrlScanner, &COPOSScanner::GetScanData));
	m_ctProp.SetItemData(m_ctProp.AddString(L"PIDXScan_ScanDataLabel"), (DWORD_PTR) new DataBinder(&m_ctrlScanner, &COPOSScanner::GetScanDataLabel));




	m_ctProp.SetItemData(m_ctProp.AddString(L"PIDXScan_ControlObjectDescription"), (DWORD_PTR) new DataBinder(&m_ctrlScanner, &COPOSScanner::GetControlObjectDescription));
	m_ctProp.SetItemData(m_ctProp.AddString(L"PIDXScan_ControlObjectVersion"), (DWORD_PTR) new DataBinder(&m_ctrlScanner, &COPOSScanner::GetControlObjectVersion));

	//for upos 1.11
	m_ctProp.SetItemData(m_ctProp.AddString(L"PIDX_CapStatisticsReporting"), (DWORD_PTR) new DataBinder(&m_ctrlScanner, &COPOSScanner::GetCapStatisticsReporting));
	m_ctProp.SetItemData(m_ctProp.AddString(L"PIDX_CapUpdateStatistics"), (DWORD_PTR) new DataBinder(&m_ctrlScanner, &COPOSScanner::GetCapUpdateStatistics));
	m_ctProp.SetItemData(m_ctProp.AddString(L"PIDX_CapCompareFirmwareVersion"), (DWORD_PTR) new DataBinder(&m_ctrlScanner, &COPOSScanner::GetCapCompareFirmwareVersion));
	m_ctProp.SetItemData(m_ctProp.AddString(L"PIDX_CapUpdateFirmware"), (DWORD_PTR) new DataBinder(&m_ctrlScanner, &COPOSScanner::GetCapUpdateFirmware));



	//m_ctProp.SetCurSel( nCell );
	//OnSelchangePropertiesCombo();
	//strProperty.Format("%d",m_ctrlScanner.GetClaimed ());
	//m_strProperty=strProperty;

	UpdateData(FALSE);
	return 0;

}

void CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnSelchangePropertiesCombo()
{
	BOOL bValid = TRUE;

	DataBinder* pDB = (DataBinder*)m_ctProp.GetItemData(m_ctProp.GetCurSel());

	CString csPropVal;
	switch (pDB->dt)
	{
	case pDB->dtBool:
		csPropVal.Format(L"%d", pDB->ExecGetterBool());
		break;
	case pDB->dtCurrency:
		csPropVal.Format(L"%d", pDB->ExecGetterCurrency());
		break;
	case pDB->dtLong:
		csPropVal.Format(L"%d", pDB->ExecGetterLong());
		break;
	case pDB->dtString:
		csPropVal.Format(L"%s", pDB->ExecGetterString());
		break;
	}

	GetDlgItem(IDC_SET_BUTTON)->EnableWindow(!pDB->bIsReadOnly);
	m_strProperty = csPropVal;
	((CEdit*)GetDlgItem(IDC_PRO_EDIT))->SetReadOnly(pDB->bIsReadOnly);

	if (bValid == TRUE)
	{
		UpdateState();
	}
	UpdateData(FALSE);

}

void CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnSetButton()
{
	UpdateData(TRUE);
	int index = m_ctProp.GetCurSel();
	if (index < 0)
	{
		return;
	}
	CString selectedText;
	m_ctProp.GetLBText(index, selectedText);
	CString existingText;
	m_editLogView.GetWindowText(existingText);
	DataBinder* pDB = (DataBinder*)m_ctProp.GetItemData(index);
	if (pDB == NULL)
	{
		return;
	}
	if (pDB->bIsReadOnly == FALSE)
	{
		CString csPropVal;
		((CEdit*)GetDlgItem(IDC_PRO_EDIT))->GetWindowText(csPropVal);
		WCHAR* p;
		int x = wcstol(csPropVal, &p, 10);
		if (*p != 0) {
			m_editLogView.SetWindowText(existingText + L"\r\n" + CurrentTime() + L" : Scanner : " + scannerProfile + L" Incorrect Parameter Value :" + selectedText); //DNS-174
			return; // Bad Intiger
		}

		switch (pDB->dt)
		{
		case pDB->dtBool:
			if (x == 0) { //DNS-174
				pDB->ExecSetterBool(FALSE);
			}
			else if (x == 1) {
				pDB->ExecSetterBool(TRUE);
			}
			else {
				m_editLogView.SetWindowText(existingText + L"\r\n" + CurrentTime() + L" : Scanner : " + scannerProfile + L" Incorrect Parameter Value :" + selectedText);
			}
			break;
		case pDB->dtCurrency:
		{
			tagCY tc;
			tc.int64 = x;
			pDB->ExecSetterCurrency(tc);
			break;
		}
		case pDB->dtLong:
			pDB->ExecSetterLong(x);
			break;
		}
	}

	UpdateState();
	if (m_strResultCode == "OPOS_E_ILLEGAL       ") //DNS-174
		m_editLogView.SetWindowText(existingText + L"\r\n" + CurrentTime() + L" : Scanner : " + scannerProfile + L" Exception in Set Properties :" + selectedText);
}

void CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnButton3()
{
	// TODO: Add your control notification handler code here
}

short CScannerSDK_SampleApp_OPOS_Scanner_Dlg::UpdateState()
{
	m_strReturnValue = GetErrorString(m_nReturnValue);
	wchar_t chBuff[20];
	_itow_s(m_iScanCount, chBuff, 20, 10);
	m_edit_ScanCount.SetWindowText(chBuff);
	//get the result code
	m_strResultCode = GetErrorString(m_ctrlScanner.GetResultCode());
	UpdateData(FALSE);
	return OPOS_SUCCESS;
}

CString CScannerSDK_SampleApp_OPOS_Scanner_Dlg::GetErrorString(long lVal)
{
	CString sRet = _T("");
	switch (lVal)
	{
	case OPOS_SUCCESS: sRet = "OPOS_SUCCESS"; break;

		//status
	case OPOS_S_CLOSED: sRet = "OPOS_S_CLOSED"; break;
	case OPOS_S_IDLE: sRet = "OPOS_S_IDLE";   break;
	case OPOS_S_BUSY: sRet = "OPOS_S_BUSY";   break;
	case OPOS_S_ERROR: sRet = "OPOS_S_ERROR";  break;

		//Error
	case OPOS_E_CLOSED: sRet = "OPOS_E_CLOSED        "; break;
	case OPOS_E_CLAIMED: sRet = "OPOS_E_CLAIMED       "; break;
	case OPOS_E_NOTCLAIMED: sRet = "OPOS_E_NOTCLAIMED    "; break;
	case OPOS_E_NOSERVICE: sRet = "OPOS_E_NOSERVICE     "; break;
	case OPOS_E_DISABLED: sRet = "OPOS_E_DISABLED      "; break;
	case OPOS_E_ILLEGAL: sRet = "OPOS_E_ILLEGAL       "; break;
	case OPOS_E_NOHARDWARE: sRet = "OPOS_E_NOHARDWARE    "; break;
	case OPOS_E_OFFLINE: sRet = "OPOS_E_OFFLINE       "; break;
	case OPOS_E_NOEXIST: sRet = "OPOS_E_NOEXIST       "; break;
	case OPOS_E_EXISTS: sRet = "OPOS_E_EXISTS        "; break;
	case OPOS_E_FAILURE: sRet = "OPOS_E_FAILURE       "; break;
	case OPOS_E_TIMEOUT: sRet = "OPOS_E_TIMEOUT       "; break;
	case OPOS_E_BUSY: sRet = "OPOS_E_BUSY          "; break;
	case OPOS_E_EXTENDED: sRet = "OPOS_E_EXTENDED      "; break;


		//OpenResult
	case EOPEN_ALREADYOPEN: sRet = "EOPEN_ALREADYOPEN    "; break;
	case EOPEN_REGBADNAME: sRet = "EOPEN_REGBADNAME     "; break;
	case EOPEN_REGPROGID: sRet = "EOPEN_REGPROGID      "; break;
	case EOPEN_CREATE: sRet = "EOPEN_CREATE         "; break;
	case EOPEN_BADIF: sRet = "EOPEN_BADIF          "; break;
	case EOPEN_FAILEDOPEN: sRet = "EOPEN_FAILEDOPEN     "; break;
	case EOPEN_BADVERSION: sRet = "EOPEN_BADVERSION     "; break;

		//SO
	case EOPENS_NOPORT: sRet = "EOPENS_NOPORT        "; break;
	case EOPENS_NOTSUPPORTED: sRet = "EOPENS_NOTSUPPORTED  "; break;
	case EOPENS_CONFIG: sRet = "EOPENS_CONFIG        "; break;
	case EOPENS_SPECIFIC: sRet = "EOPENS_SPECIFIC      "; break;

	default: sRet.Format(L"%ld", lVal); break;

	}

	return sRet;
}

void CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnClaimButton()
{
	//clall the claim method with appropriate value
	m_nReturnValue = m_ctrlScanner.ClaimDevice(6000);
	m_iScanCount = 0;

	//update the screen with return values
	UpdateState();
}

void CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnReleaseButton()
{
	//clall the rlease method
	m_nReturnValue = m_ctrlScanner.ReleaseDevice();
	m_iScanCount = 0;

	//update the UI with return values
	UpdateState();
}

void CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnLearInputButton()
{
	//clall the clear input methos
	m_nReturnValue = m_ctrlScanner.ClearInput();

	//update the UI with return values
	UpdateState();

	//lcear the windows
	m_strReturnValue = _T("");
	m_strResultCode = _T("");

	m_editScanData.SetWindowText(_T(""));
	m_strScanDataLabel = _T("");

	UpdateData(FALSE);
	UpdateState();

}

void CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnClearButton()
{
	//clear the string variables
	m_strReturnValue = _T("");
	m_strResultCode = _T("");

	m_editScanData.SetWindowText(_T(""));
	m_strScanDataLabel = _T("");
	UpdateData(FALSE);
}

void CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnEventEnableButton()
{
	//enable the device
	m_ctrlScanner.SetDataEventEnabled(1);

	//get the return values and update UI with new values
	UpdateState();
}

void CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnClButton()
{
	//cla the close method
	m_nReturnValue = m_ctrlScanner.Close();//CloseDevice();
	m_iScanCount = 0;
	if (m_nReturnValue == OPOS_SUCCESS)
	{
		GetDlgItem(IDC_CHECK_AutoEvtEnable)->EnableWindow(FALSE);
		m_check_DataEventAutoenable.SetCheck(BST_UNCHECKED);
	}
	//get the return values and update the UI
	UpdateState();
	OnLearInputButton();
}

void CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnDecodeButton()
{
	//Set decode data as one(1)
	m_ctrlScanner.SetDecodeData(1);
	UpdateState();
}

CString CScannerSDK_SampleApp_OPOS_Scanner_Dlg::GetScanDataType(long p_nLabelType)
{

	switch (p_nLabelType)
	{

	case SCAN_SDT_UPCA:
		return _T("SCAN_SDT_UPCA");
		break;

	case SCAN_SDT_UPCE:
		return _T("SCAN_SDT_UPCE");
		break;

	case SCAN_SDT_JAN8:
		return _T("SCAN_SDT_JAN8");
		break;

	case SCAN_SDT_JAN13:
		return _T("SCAN_SDT_JAN13");
		break;

	case SCAN_SDT_TF:
		return _T("SCAN_SDT_TF");
		break;
	case SCAN_SDT_ITF:
		return _T("SCAN_SDT_ITF");
		break;
	case SCAN_SDT_Codabar:
		return _T("SCAN_SDT_Codabar");
		break;

	case SCAN_SDT_Code39:
		return _T("SCAN_SDT_Code39");
		break;

	case SCAN_SDT_Code93:
		return _T("SCAN_SDT_Code93");
		break;
	case SCAN_SDT_Code128:
		return _T("SCAN_SDT_Code128");
		break;

	case SCAN_SDT_UPCA_S:
		return _T("SCAN_SDT_UPCA_S");
		break;

	case SCAN_SDT_UPCE_S:
		return _T("SCAN_SDT_UPCE_S");
		break;

	case SCAN_SDT_UPCD1:
		return _T("SCAN_SDT_UPCD");
		break;
	case SCAN_SDT_UPCD2:
		return _T("SCAN_SDT_UPCD2");
		break;
	case SCAN_SDT_UPCD3:
		return _T("SCAN_SDT_UPCD3");
		break;
	case SCAN_SDT_UPCD4:
		return _T("SCAN_SDT_UPCD4");
		break;
	case SCAN_SDT_UPCD5:
		return _T("SCAN_SDT_UPCD5");
		break;
	case SCAN_SDT_EAN8_S:
		return _T("SCAN_SDT_EAN8_S");
		break;

	case SCAN_SDT_EAN13_S:
		return _T("SCAN_SDT_EAN13_S");
		break;

	case SCAN_SDT_EAN128:
		return _T("SCAN_SDT_EAN128");
		break;
	case SCAN_SDT_OCRA:
		return _T("SCAN_SDT_OCRA");
		break;
	case SCAN_SDT_OCRB:
		return _T("SCAN_SDT_OCRB");
		break;

	case SCAN_SDT_PDF417:
		return _T("SCAN_SDT_PDF417");
		break;
	case SCAN_SDT_MAXICODE:
		return _T("SCAN_SDT_MAXICODE");
		break;
		///
	case SCAN_SDT_RSS14:
		return _T("SCAN_SDT_GS1DATABAR");
		break;
	case SCAN_SDT_RSS_EXPANDED:
		return _T("SCAN_SDT_GS1DATABAR_E");
		break;

		///
	case SCAN_SDT_OTHER:
		return _T("SCAN_SDT_OTHER");
		break;
	case SCAN_SDT_UNKNOWN:
		return _T("SCAN_SDT_UNKNOWN");
		break;

	case SCAN_SDT_DATAMATRIX:
		return _T("SCAN_SDT_DATAMATRIX");
		break;

	case SCAN_SDT_QRCODE:
		return _T("SCAN_SDT_QRCODE");
		break;

	case SCAN_SDT_UQRCODE:
		return _T("SCAN_SDT_UQRCODE");
		break;

	case SCAN_SDT_AZTEC:
		return _T("SCAN_SDT_AZTEC");
		break;

	case SCAN_SDT_UPDF417:
		return _T("SCAN_SDT_UPDF417");
		break;

	case SCAN_SDT_GS1DATAMATRIX:
		return _T("SCAN_SDT_GS1DATAMATRIX");
		break;

	case SCAN_SDT_GS1QRCODE:
		return _T("SCAN_SDT_GS1QRCODE");
		break;

	case SCAN_SDT_GRIDMATRIX:
		return _T("SCAN_SDT_GRIDMATRIX");
		break;
	case SCAN_SDT_UsPlanet:
		return _T("SCAN_SDT_UsPlanet");
		break;
	case SCAN_SDT_ISBT128:
		return _T("SCAN_SDT_ISBT128");
		break;
	case SCAN_SDT_TRIOPTIC39:
		return _T("SCAN_SDT_TRIOPTIC39");
		break;
	case SCAN_SDT_PostNet:
		return _T("SCAN_SDT_PostNet");
		break;
	case SCAN_SDT_JapanPost:
		return _T("SCAN_SDT_JapanPost");
		break;
	case SCAN_SDT_UkPost:
		return _T("SCAN_SDT_UkPost");
		break;
	case SCAN_SDT_AusPost:
		return _T("SCAN_SDT_AusPost");
		break;
	case SCAN_SDT_HANXIN:
		return _T("SCAN_SDT_HANXIN");
		break;

	default:
	{
		return _T("SCAN_SDT_UNKNOWN");
		break;
	}
	}
}

//SSDK-19840 - Implementing retrieve statistics filter
void CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnRetrievButton()
{
	((CEdit*)GetDlgItem(IDC_STATISTICS_FILTER))->GetWindowText(m_statisticsFilter);

	BSTR  test = m_statisticsFilter.AllocSysString();
	if (m_ctrlScanner.GetCapStatisticsReporting() == TRUE)
	{
		//AfxMessageBox("supporting");
	}
	else
	{
		AfxMessageBox(L"StatisticsReporting is not supported");
		return;
	}

	long lRetVal = m_ctrlScanner.RetrieveStatistics(&test);

	if (lRetVal == OPOS_SUCCESS)
	{

		CString strTemp;
		strTemp = test;
		AfxMessageBox(strTemp);
	}
	else
	{
		AfxMessageBox(L"Statistics cannot be retrieved.");
		UpdateState();
	}
}

void CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnUpdateStatisButton()
{
	BOOL notErrorOccured = UpdateData(TRUE);
	CString strTemp;

	if (m_ctrlScanner.GetCapUpdateStatistics() == TRUE)
	{
		//AfxMessageBox("supporting");
	}
	else
	{
		AfxMessageBox(L"StatisticsReporting is not supported");
		return;
	}

	if (notErrorOccured)
	{
		strTemp.Format(L"GoodScanCount=%d", m_nGoodScanCount);
	}

	else
	{
		//if error occured, send a Non-nemeric value to SO for identify that an error has occured
		strTemp = "GoodScanCount=Error";
	}

	m_nReturnValue = m_ctrlScanner.UpdateStatistics(strTemp);

	//update the screen with return values
	UpdateState();
}

void CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnResetStatButton()
{
	m_nReturnValue = m_ctrlScanner.ResetStatistics(L"GoodScanCount");
	m_iScanCount = 0;
	UpdateState();
}

void CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnInputButton()
{
	m_ctrlScanner.ClearInputProperties();
}

void CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnBnClickedCloseButton()
{
	// TODO: Add your control notification handler code here
}

void CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnBnClickedCheckAutoevtenable()
{
	if (m_check_DataEventAutoenable.GetCheck() == BST_CHECKED)
	{
		m_ctrlScanner.SetDataEventEnabled(TRUE);
		//GetDlgItem(IDC_EVENT_ENABLE_BUTTON)->EnableWindow(FALSE);
	}
	else
	{
		m_ctrlScanner.SetDataEventEnabled(FALSE);
		//GetDlgItem(IDC_EVENT_ENABLE_BUTTON)->EnableWindow();
	}
}

int CScannerSDK_SampleApp_OPOS_Scanner_Dlg::SetupDirectIO(void)
{
	CComboBox* cmbDIOCommands = (CComboBox*)GetDlgItem(IDC_COMBO_DIO_OpCodes);
	for (size_t i = 0; i < DIOOpCodes.size(); i++)
	{
		cmbDIOCommands->SetItemData(cmbDIOCommands->AddString(DIOOpCodes[i].m_opcode_name), (DWORD_PTR)&DIOOpCodes[i]);
	}
	cmbDIOCommands->SetCurSel(0);
	m_pdioSelectedItem = (PDIO_OPCODES)cmbDIOCommands->GetItemDataPtr(cmbDIOCommands->GetCurSel());
	return 0;
}

void CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnCbnSelchangeComboDioOpcodes()
{
	CComboBox* cmbDIOCommands = (CComboBox*)GetDlgItem(IDC_COMBO_DIO_OpCodes);
	m_pdioSelectedItem = (PDIO_OPCODES)cmbDIOCommands->GetItemDataPtr(cmbDIOCommands->GetCurSel());
	//CEdit* peditInXml = (CEdit*)GetDlgItem(IDC_EDIT_InXML);
	m_editInXml.SetWindowText(m_pdioSelectedItem->m_inxml);
}

void CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnBnClickedButtonExecute()
{
	LONG retVal;
	CString csInXML;
	m_editInXml.GetWindowText(csInXML);

	BSTR inXML = csInXML.AllocSysString();
	LONG a = -1;
	retVal = m_ctrlScanner.DirectIO(m_pdioSelectedItem->m_opcode_value, &a, &inXML);
	wchar_t wcstat[10];
	_ltow_s(a, wcstat, 10);
	m_editCSstatus.SetWindowText(wcstat);

	if (retVal == OPOS_SUCCESS)
	{
		CString csOutXml(inXML);
		m_editOutXML.SetWindowText(csOutXml);
	}
	else
	{
		CString csOutXml(L"");
		m_editOutXML.SetWindowText(csOutXml);
	}
	SysFreeString(inXML);
	UpdateState();

}

void CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnBnClickedButtonClear()
{
	CString empty(L"");
	m_editOutXML.SetWindowText(empty);
	m_editCSstatus.SetWindowText(empty);
}

void CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnCheckHealthButton()
{
	m_nReturnValue = m_ctrlScanner.CheckHealth(OPOS_CH_INTERNAL);
	UpdateState();
}

void CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnBnClickedButtonCheckhealth()
{
	m_nReturnValue = m_ctrlScanner.CheckHealth(OPOS_CH_EXTERNAL);
	UpdateState();
}

void CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnBnClickedButtonChIntercative()
{
	m_nReturnValue = m_ctrlScanner.CheckHealth(OPOS_CH_INTERACTIVE);
	UpdateState();
}

void CScannerSDK_SampleApp_OPOS_Scanner_Dlg::StatusUpdateEventScanner1(long Data)
{
	switch (Data)
	{
	case OPOS_SUE_POWER_OFF:
		MessageBox(L"Device power off");
		break;
	case OPOS_SUE_POWER_OFFLINE:
		MessageBox(L"Device power offline");
		break;
	case OPOS_SUE_POWER_OFF_OFFLINE:
		MessageBox(L"Device power off or offline");
		break;
	case OPOS_SUE_POWER_ONLINE:
		MessageBox(L"Device power online");
		break;
	default:
		break;
	}
}

void CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnEnChangeUpdateEdit()
{
	CEdit* pe1 = (CEdit*)GetDlgItem(IDC_UPDATE_EDIT);
	CString str;

	pe1->GetWindowText(str);

	if (_wtoll(str) > _wtoll(MAX_LONG_VALUE)) {

		AfxMessageBox(L"Exceeded the maximum input limit");
		SetDlgItemTextW(IDC_UPDATE_EDIT, (LPCTSTR)MAX_LONG_VALUE);
	}
}


void CScannerSDK_SampleApp_OPOS_Scanner_Dlg::DirectIOEventScanner1(long EventNumber, long* pData, BSTR* pString)
{
	CString logMessage(*pString);
	PrintLog(logMessage);
}

void CScannerSDK_SampleApp_OPOS_Scanner_Dlg::PrintLog(CString logMessage)
{
	logMessage = CurrentTime() + _T("\r\n") + logMessage + _T("\r\n");
	m_editLogView.SendMessage(EM_SETSEL, -1, -1);
	m_editLogView.SendMessage(EM_REPLACESEL, 0, (LPARAM)(LPCTSTR)logMessage);
}

CString CScannerSDK_SampleApp_OPOS_Scanner_Dlg::CurrentTime()
{
	auto now = std::chrono::system_clock::now();
	std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
	std::tm now_tm;
	localtime_s(&now_tm, &now_time_t);

	std::wostringstream oss;
	oss << std::put_time(&now_tm, L"%Y-%m-%d %H:%M:%S");

	CString currentTime(oss.str().c_str());
	return currentTime;
}

void CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnBnClickedClearLog()
{
	CString empty(L"");
	m_editLogView.SetWindowText(empty);
}

void CScannerSDK_SampleApp_OPOS_Scanner_Dlg::OnCancelOverride() //DNS -169
{
	if ((GetKeyState(VK_ESCAPE) & 0x8000) == 0)
		OnCancel();
}
