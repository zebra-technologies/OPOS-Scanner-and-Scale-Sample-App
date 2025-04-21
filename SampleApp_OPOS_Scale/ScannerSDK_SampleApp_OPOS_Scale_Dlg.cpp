/*******************************************************************************************
*
* ©2016 Symbol Technologies LLC. All rights reserved.
*
********************************************************************************************/
// Motorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "ScannerSDK_SampleApp_OPOS_Scale.h"
#include "ScannerSDK_SampleApp_OPOS_Scale_Dlg.h"
#include "Windows.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <chrono>
#include <sstream>
#include <iomanip>


// CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg dialog



CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SCALE1, OposScale);
	DDX_Control(pDX, IDC_COMBO_SCALE_PROPERTIES, m_cmbProperties);
	//DDX_Control(pDX, IDC_EDIT_LOGICAL_DEVICE, m_editLogicalDeviceName);
	DDX_Control(pDX, IDC_EDIT_READ_WEIGHT, m_editWeghtData);
	DDX_Control(pDX, IDC_EDIT_RESULT_CODE, m_editResultCode);
	DDX_Control(pDX, IDC_EDIT1, m_editPropValue);
	DDX_Control(pDX, IDC_EDIT_KG_POUNDS, m_editKgPounds);
	DDX_Control(pDX, IDC_EDIT_RET_VAL, m_editReturnValue);
	DDX_Control(pDX, IDC_EDIT_SATUS, m_editStatus);
	DDX_Control(pDX, IDC_CHECK_FREEZ_EVENTS, m_check_FreezEvents);
	DDX_Control(pDX, IDC_CHECK_DATAEVENT_ENABLE, m_check_DataEventEnable);
	DDX_Control(pDX, IDC_CHECK_ASYNC_MODE, m_check_AsyncMode);
	DDX_Control(pDX, IDC_EDIT_InXml, m_editInXml);
	DDX_Control(pDX, IDC_EDIT_OutXml, m_editOutXML);
	DDX_Control(pDX, IDC_EDIT_LiveWeight, m_edit_LiveWeight);
	DDX_Control(pDX, IDC_CHECK_StatusNotify, m_check_StatusNotify);
	DDX_Control(pDX, IDC_EDIT_CSStatus, m_editCSstatus);
	DDX_Control(pDX, IDC_COMBO_SO_NAMES, m_combo_SONames);
	DDX_Control(pDX, IDC_EDIT_ERROR_MESSAGE, m_error_Message);
	DDX_Control(pDX, IDC_STATISTICS_FILTER, m_statisticsFilter);
	DDX_Control(pDX, IDC_EDIT_LOGVIEW, m_editLogView);
}

BEGIN_MESSAGE_MAP(CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_OPEN, &CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedButtonOpen)
	ON_BN_CLICKED(IDC_BUTTON_CLAIM, &CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedButtonClaim)
	ON_BN_CLICKED(IDC_BUTTON_DEVICE_ENABLE, &CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedButtonDeviceEnable)
	ON_BN_CLICKED(IDC_BUTTON_READ_WEIGHT, &CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedButtonReadWeight)
	ON_CBN_SELCHANGE(IDC_COMBO_SCALE_PROPERTIES, &CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnCbnSelchangeComboScaleProperties)
	ON_BN_CLICKED(IDC_BUTTON_DEVICE_DISABLE, &CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedButtonDeviceDisable)
	ON_BN_CLICKED(IDC_BUTTON_RELEASE, &CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedButtonRelease)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, &CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedButtonClose)
	ON_BN_CLICKED(IDC_BUTTON_ZERO_SCALE, &CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedButtonZeroScale)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE, &CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedButtonUpdate)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR_INPUT, &CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedButtonClearInput)
	ON_BN_CLICKED(IDC_CHECK_FREEZ_EVENTS, &CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedCheckFreezEvents)
	ON_BN_CLICKED(IDC_CHECK_DATAEVENT_ENABLE, &CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedCheckDataeventEnable)
	ON_BN_CLICKED(IDC_CHECK_ASYNC_MODE, &CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedCheckAsyncMode)
	ON_BN_CLICKED(IDC_BUTTON_Execute, &CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedButtonExecute)
	ON_CBN_SELCHANGE(IDC_COMBO_DIO_OpCodes, &CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnCbnSelchangeCombDioOpcodes)
	ON_BN_CLICKED(IDC_BUTTON_Clear, &CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_CHECK_StatusNotify, &CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedCheckStatusnotify)
	ON_BN_CLICKED(IDC_BUTTON_CheckHealth, &CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedButtonCheckhealth)
	ON_BN_CLICKED(IDC_BUTTON_CHExternal, &CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedButtonChexternal)
	ON_BN_CLICKED(IDC_BUTTON_CHInteractive, &CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedButtonChinteractive)
	ON_BN_CLICKED(IDC_Retrieve_Stats, &CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedRetrieveStats)
	ON_BN_CLICKED(IDC_Reset_Stats, &CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedResetStats)
	ON_COMMAND(IDCANCEL, OnCancelOverride)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR_LOG, &CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedButtonClearLog)
END_MESSAGE_MAP()


// CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg message handlers

BOOL CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	#if defined(_WIN64)
		#define MY_CAPTION L"Scanner SDK Sample Application OPOS Scale (64bit)"
	#else
		#define MY_CAPTION L"Scanner SDK Sample Application OPOS Scale (32bit)"
	#endif
	SetWindowText(MY_CAPTION);
	LoadProperties();
	GetDlgItem(IDC_BUTTON_UPDATE)->EnableWindow(false);
	UpdateResultCode();
	SetupDirectIO();

	CFont* pNewFont = new CFont();
	pNewFont->CreateFont( 20, 0, 0, 0, FW_HEAVY, false, false,0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FIXED_PITCH|FF_MODERN, _T("Courier New") );
	m_editWeghtData.SetFont(pNewFont);
	m_edit_LiveWeight.SetFont(pNewFont);

	m_ctrl_tooltip_ext.Create(this);
	m_ctrl_tooltip_ext.DisplayTooltipText(L"Enable Live Weight (before Device Enable). This enables Status Notify Events.", &m_check_StatusNotify);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


class DataBinder
{
public:
	typedef BOOL(CScale1::* fpTypeOPOSGetterBool)(void);
	typedef void (CScale1::* fpTypeOPOSSetterBool)(BOOL);
	typedef long (CScale1::* fpTypeOPOSGetterLong)(void);
	typedef void (CScale1::* fpTypeOPOSSetterLong)(long);
	typedef CString (CScale1::* fpTypeOPOSGetterString)(void);
	typedef CY(CScale1::* fpTypeOPOSGetterCurrency)(void);
	typedef void (CScale1::* fpTypeOPOSSetterCurrency)(CY);


	CScale1* pCScale_;

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


	DataBinder(CScale1* pScaleObj, fpTypeOPOSGetterBool fpGetterBool, fpTypeOPOSSetterBool fpSetterBool = NULL): pCScale_(pScaleObj), fpGetterBool_(fpGetterBool), fpSetterBool_(fpSetterBool)
	{
		bIsReadOnly = true;
		dt = dtBool;
		if(fpSetterBool)
		{
			bIsReadOnly = false;
		}
	}
	DataBinder(CScale1* pScaleObj, fpTypeOPOSGetterLong fpGetterLong, fpTypeOPOSSetterLong fpSetterLong = NULL): pCScale_(pScaleObj), fpGetterLong_(fpGetterLong), fpSetterlong_(fpSetterLong)
	{
		bIsReadOnly = true;
		dt = dtLong;
		if(fpSetterLong)
		{
			bIsReadOnly = false;
		}
	}

	DataBinder(CScale1* pScaleObj, fpTypeOPOSGetterCurrency fpGetterCurrency, fpTypeOPOSSetterCurrency fpSetterCurrency = NULL): pCScale_(pScaleObj), fpGetterCurrency_(fpGetterCurrency), fpSetterCurrency_(fpSetterCurrency)
	{
		bIsReadOnly = true;
		dt = dtCurrency;
		if(fpSetterCurrency)
		{
			bIsReadOnly = false;
		}
	}	
	DataBinder(CScale1* pScaleObj, fpTypeOPOSGetterString fpGetterString): pCScale_(pScaleObj), fpGetterString_(fpGetterString)
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

void CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::LoadProperties()
{
	HKEY hTestKey;
	if( RegOpenKeyEx( HKEY_LOCAL_MACHINE, TEXT("SOFTWARE\\OLEforRetail\\ServiceOPOS\\Scale"), 0, KEY_READ, &hTestKey) == ERROR_SUCCESS)
	{
		QueryKey(hTestKey);
	}
	RegCloseKey(hTestKey);
	//m_combo_SONames.SetWindowText(L"MOTOROLA_SCALE");
	m_combo_SONames.SetCurSel(0);
	m_editLogicalDeviceName.UpdateData();
	
	m_cmbProperties.SetItemData(m_cmbProperties.AddString(L"PIDX_BinaryConversion"),(DWORD_PTR)new DataBinder(&OposScale, &CScale1::get_BinaryConversion, &CScale1::put_BinaryConversion));       
	m_cmbProperties.SetItemData(m_cmbProperties.AddString(L"PIDX_Claimed"),(DWORD_PTR)new DataBinder(&OposScale, &CScale1::get_Claimed));       
	m_cmbProperties.SetItemData(m_cmbProperties.AddString(L"PIDX_DataEventEnabled"),(DWORD_PTR)new DataBinder(&OposScale, &CScale1::get_DataEventEnabled, &CScale1::put_DataEventEnabled));       
	m_cmbProperties.SetItemData(m_cmbProperties.AddString(L"PIDX_DeviceEnabled"),(DWORD_PTR)new DataBinder(&OposScale, &CScale1::get_DeviceEnabled, &CScale1::put_DeviceEnabled));       
	m_cmbProperties.SetItemData(m_cmbProperties.AddString(L"PIDX_FreezeEvents"),(DWORD_PTR)new DataBinder(&OposScale, &CScale1::get_FreezeEvents, &CScale1::put_FreezeEvents));       
	m_cmbProperties.SetItemData(m_cmbProperties.AddString(L"PIDX_ServiceObjectDescription"),(DWORD_PTR)new DataBinder(&OposScale, &CScale1::get_ServiceObjectDescription));       
	m_cmbProperties.SetItemData(m_cmbProperties.AddString(L"PIDX_ServiceObjectVersion"),(DWORD_PTR)new DataBinder(&OposScale, &CScale1::get_ServiceObjectVersion));       
	m_cmbProperties.SetItemData(m_cmbProperties.AddString(L"PIDX_State"),(DWORD_PTR)new DataBinder(&OposScale, &CScale1::get_State));       

	m_cmbProperties.SetItemData(m_cmbProperties.AddString(L"PIDX_AutoDisable"),(DWORD_PTR)new DataBinder(&OposScale, &CScale1::get_AutoDisable, &CScale1::put_AutoDisable));       
	m_cmbProperties.SetItemData(m_cmbProperties.AddString(L"PIDX_DataCount"),(DWORD_PTR)new DataBinder(&OposScale, &CScale1::get_DataCount));       

	m_cmbProperties.SetItemData(m_cmbProperties.AddString(L"PIDX_PowerNotify"),(DWORD_PTR)new DataBinder(&OposScale, &CScale1::get_PowerNotify, &CScale1::put_PowerNotify));       
	m_cmbProperties.SetItemData(m_cmbProperties.AddString(L"PIDX_PowerState"),(DWORD_PTR)new DataBinder(&OposScale, &CScale1::get_PowerState));       

	m_cmbProperties.SetItemData(m_cmbProperties.AddString(L"PIDX_CapPowerReporting"),(DWORD_PTR)new DataBinder(&OposScale, &CScale1::get_CapPowerReporting));       

	m_cmbProperties.SetItemData(m_cmbProperties.AddString(L"PIDX_CheckHealthText"),(DWORD_PTR)new DataBinder(&OposScale, &CScale1::get_CheckHealthText));       
	m_cmbProperties.SetItemData(m_cmbProperties.AddString(L"PIDX_DeviceDescription"),(DWORD_PTR)new DataBinder(&OposScale, &CScale1::get_DeviceDescription));       
	m_cmbProperties.SetItemData(m_cmbProperties.AddString(L"PIDX_DeviceName"),(DWORD_PTR)new DataBinder(&OposScale, &CScale1::get_DeviceName));       

	m_cmbProperties.SetItemData(m_cmbProperties.AddString(L"PIDX_ControlObjectDescription"),(DWORD_PTR)new DataBinder(&OposScale, &CScale1::get_ControlObjectDescription));       
	m_cmbProperties.SetItemData(m_cmbProperties.AddString(L"PIDX_ControlObjectVersion"),(DWORD_PTR)new DataBinder(&OposScale, &CScale1::get_ControlObjectVersion));       

	m_cmbProperties.SetItemData(m_cmbProperties.AddString(L"PIDX_CapStatisticsReporting"),(DWORD_PTR)new DataBinder(&OposScale, &CScale1::get_CapStatisticsReporting));       
	m_cmbProperties.SetItemData(m_cmbProperties.AddString(L"PIDX_CapUpdateStatistics"),(DWORD_PTR)new DataBinder(&OposScale, &CScale1::get_CapUpdateStatistics));       
	m_cmbProperties.SetItemData(m_cmbProperties.AddString(L"PIDX_CapCompareFirmwareVersion"),(DWORD_PTR)new DataBinder(&OposScale, &CScale1::get_CapCompareFirmwareVersion));       
	m_cmbProperties.SetItemData(m_cmbProperties.AddString(L"PIDX_CapUpdateFirmware"),(DWORD_PTR)new DataBinder(&OposScale, &CScale1::get_CapUpdateFirmware));       
	m_cmbProperties.SetItemData(m_cmbProperties.AddString(L"PIDX_ResultCodeExtended"),(DWORD_PTR)new DataBinder(&OposScale, &CScale1::get_ResultCodeExtended));
	m_cmbProperties.SetItemData(m_cmbProperties.AddString(L"PIDX_ResultCode"),(DWORD_PTR)new DataBinder(&OposScale, &CScale1::get_ResultCode));
	m_cmbProperties.SetItemData(m_cmbProperties.AddString(L"PIDX_OpenResult"),(DWORD_PTR)new DataBinder(&OposScale, &CScale1::get_OpenResult));
	

	m_cmbProperties.SetItemData(m_cmbProperties.AddString(L"PIDXScal_MaximumWeight"),(DWORD_PTR)new DataBinder(&OposScale, &CScale1::get_MaximumWeight));       
	m_cmbProperties.SetItemData(m_cmbProperties.AddString(L"PIDXScal_AsyncMode"),(DWORD_PTR)new DataBinder(&OposScale, &CScale1::get_AsyncMode, &CScale1::put_AsyncMode));       
	m_cmbProperties.SetItemData(m_cmbProperties.AddString(L"PIDXScal_MaxDisplayTextChars"),(DWORD_PTR)new DataBinder(&OposScale, &CScale1::get_MaxDisplayTextChars));       
	m_cmbProperties.SetItemData(m_cmbProperties.AddString(L"PIDXScal_ScaleLiveWeight"),(DWORD_PTR)new DataBinder(&OposScale, &CScale1::get_ScaleLiveWeight));       
	m_cmbProperties.SetItemData(m_cmbProperties.AddString(L"PIDXScal_StatusNotify"),(DWORD_PTR)new DataBinder(&OposScale, &CScale1::get_StatusNotify, &CScale1::put_StatusNotify));       
	m_cmbProperties.SetItemData(m_cmbProperties.AddString(L"PIDXScal_TarWeight"),(DWORD_PTR)new DataBinder(&OposScale, &CScale1::get_TareWeight, &CScale1::put_TareWeight));       
	m_cmbProperties.SetItemData(m_cmbProperties.AddString(L"PIDXScal_UnitPrice"),(DWORD_PTR)new DataBinder(&OposScale, &CScale1::get_UnitPrice, &CScale1::put_UnitPrice));       
	m_cmbProperties.SetItemData(m_cmbProperties.AddString(L"PIDXScal_SalesPrice"),(DWORD_PTR)new DataBinder(&OposScale, &CScale1::get_SalesPrice));       
	m_cmbProperties.SetItemData(m_cmbProperties.AddString(L"PIDXScal_WeightUnit"),(DWORD_PTR)new DataBinder(&OposScale, &CScale1::get_WeightUnit));       
	m_cmbProperties.SetItemData(m_cmbProperties.AddString(L"PIDXScal_ZeroValid"),(DWORD_PTR)new DataBinder(&OposScale, &CScale1::get_ZeroValid, &CScale1::put_ZeroValid));       
	m_cmbProperties.SetItemData(m_cmbProperties.AddString(L"PIDXScal_CapDisplay"),(DWORD_PTR)new DataBinder(&OposScale, &CScale1::get_CapDisplay));       
	m_cmbProperties.SetItemData(m_cmbProperties.AddString(L"PIDXScal_CapDisplayText"),(DWORD_PTR)new DataBinder(&OposScale, &CScale1::get_CapDisplayText));       
	m_cmbProperties.SetItemData(m_cmbProperties.AddString(L"PIDXScal_CapPriceCalculating"),(DWORD_PTR)new DataBinder(&OposScale, &CScale1::get_CapPriceCalculating));       
	m_cmbProperties.SetItemData(m_cmbProperties.AddString(L"PIDXScal_CapTareWeight"),(DWORD_PTR)new DataBinder(&OposScale, &CScale1::get_CapTareWeight));       
	m_cmbProperties.SetItemData(m_cmbProperties.AddString(L"PIDXScal_CapZeroScale"),(DWORD_PTR)new DataBinder(&OposScale, &CScale1::get_CapZeroScale));       
	m_cmbProperties.SetItemData(m_cmbProperties.AddString(L"PIDXScal_CapStatusUpdate"),(DWORD_PTR)new DataBinder(&OposScale, &CScale1::get_CapStatusUpdate));       
	
}

void CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedButtonOpen()
{
	WCHAR wcLogicalName[100];
	//m_editLogicalDeviceName.GetWindowText(wcLogicalName,100);
	m_combo_SONames.GetWindowText(wcLogicalName,100);
	scaleProfile = wcLogicalName; //DNS-174
	m_editReturnValue.SetWindowText(GetErrorString(OposScale.Open(wcLogicalName)));
	
	long result1 = 0;
	result1 = UpdateResultCode();
	if(0 == result1)
	{
		//m_editLogicalDeviceName.SetReadOnly();
		m_combo_SONames.EnableWindow(FALSE);
	}
}


void CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedButtonClaim()
{
	m_editReturnValue.SetWindowText(GetErrorString(OposScale.ClaimDevice(1000)));
	UpdateResultCode();
}
void CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedButtonDeviceEnable()
{
	OposScale.put_DeviceEnabled(TRUE);
	m_editReturnValue.SetWindowText(L"");
	UpdateResultCode();
}

void CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedButtonReadWeight()
{	
	CString csUnit;
	long unit = OposScale.get_WeightUnit();
	switch (unit)
	{
	case SCAL_WU_GRAM:
		csUnit = "g";
		break;
	case SCAL_WU_KILOGRAM:
		csUnit = "kg";
		break;
	case SCAL_WU_OUNCE:
		csUnit = "oz";
		break;
	case SCAL_WU_POUND:
		csUnit = "lb";
		break;
	}
	m_editKgPounds.SetWindowText(csUnit);
	m_editKgPounds.UpdateData();
	
	long lweightData = 0;
	float fweight_1 = 0;
	m_editReturnValue.SetWindowText(GetErrorString(OposScale.ReadWeight(&lweightData, 2000)));
	
	fweight_1 = (float)(((float)lweightData) /1000);
	
	ClearErrorMessage();
	WCHAR wcWeght[10];	
	swprintf_s(wcWeght, 10, L"%4.3f",fweight_1);
	if (!OposScale.get_AsyncMode()) {
		m_editWeghtData.SetWindowText(wcWeght);
		m_editWeghtData.UpdateData();
	}
	UpdateResultCode();
}

void CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::ClearErrorMessage() {
	/* OPOS Scale Async error event details will not be removed after performing non-async read weight process.
	This method is implemented for clear the Error event details in the error label. DNS-158 / SSDK-19757 fix - TR6469 */
	WCHAR wcErrorMessage[10];
	swprintf_s(wcErrorMessage, 10, L"");
	m_error_Message.SetWindowText(wcErrorMessage);
}
void CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnCbnSelchangeComboScaleProperties()
{
	int i = m_cmbProperties.GetCurSel();
	DataBinder* pDB = (DataBinder*)m_cmbProperties.GetItemData(i);
	
	CString csPropVal;
	switch(pDB->dt)
	{
		case pDB->dtBool:
			csPropVal.Format(L"%d",pDB->ExecGetterBool());
			break;
		case pDB->dtCurrency:
			csPropVal.Format(L"%d",pDB->ExecGetterCurrency());
			break;
		case pDB->dtLong:
			csPropVal.Format(L"%d",pDB->ExecGetterLong());
			break;
		case pDB->dtString:
			csPropVal.Format(L"%s",pDB->ExecGetterString());
			break;
	}

	m_editPropValue.SetReadOnly(pDB->bIsReadOnly);
	GetDlgItem(IDC_BUTTON_UPDATE)->EnableWindow(!pDB->bIsReadOnly);
	m_editReturnValue.SetWindowText(L"");
	if(OPOS_SUCCESS != UpdateResultCode())
	{
		//csPropVal = L"";
	}
	m_editPropValue.SetWindowText(csPropVal);
	m_editPropValue.UpdateData();
}

void CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedButtonDeviceDisable()
{
	OposScale.put_DeviceEnabled(FALSE);
	m_editReturnValue.SetWindowText(L"");
	UpdateResultCode();
}

void CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedButtonRelease()
{
	m_editReturnValue.SetWindowText(GetErrorString(OposScale.ReleaseDevice()));
	m_edit_LiveWeight.SetWindowText(_T(""));
	UpdateResultCode();
}

void CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedButtonClose()
{
	m_editReturnValue.SetWindowText(GetErrorString(OposScale.Close()));
	if(OPOS_E_CLOSED == UpdateResultCode())
	{
		//m_editLogicalDeviceName.SetReadOnly(FALSE);
		m_combo_SONames.EnableWindow();
	}
	m_editWeghtData.SetWindowText(_T(""));
	m_edit_LiveWeight.SetWindowText(_T(""));
	m_editPropValue.SetWindowText(_T(""));
	m_editOutXML.SetWindowText(L"");
}

LONG CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::UpdateResultCode()
{
	long lRc = OposScale.get_ResultCode();
	m_editResultCode.SetWindowText(GetErrorString(lRc));
	m_editStatus.SetWindowText(GetErrorString(OposScale.get_State()));
	m_editResultCode.UpdateData();
	m_check_DataEventEnable.SetCheck(OposScale.get_DataEventEnabled());
	m_check_FreezEvents.SetCheck(OposScale.get_FreezeEvents());
	m_check_AsyncMode.SetCheck(OposScale.get_AsyncMode());
	m_check_StatusNotify.SetCheck((OposScale.get_StatusNotify() == SCAL_SN_ENABLED) ? BST_CHECKED : BST_UNCHECKED);
	return lRc;
}

void CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedButtonZeroScale()
{
	m_editReturnValue.SetWindowText(GetErrorString(OposScale.ZeroScale()));
	WCHAR wcWeght[20] = {0};
	swprintf_s(wcWeght, 10, L"%4.3f", 0.000);
	m_editWeghtData.SetWindowText(wcWeght);
	m_editWeghtData.UpdateData();
	UpdateResultCode();
}

void CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedButtonUpdate()
{
	int index = m_cmbProperties.GetCurSel();
	CString selectedText;
	m_cmbProperties.GetLBText(index, selectedText);
	CString existingText;
	m_editLogView.GetWindowText(existingText);
	DataBinder* pDB = (DataBinder*)m_cmbProperties.GetItemData(index);
	if(pDB == NULL)
	{
		return;
	}
	if(pDB->bIsReadOnly == FALSE)
	{
		CString csPropVal;
		m_editPropValue.GetWindowTextW(csPropVal);
		WCHAR * p;
		int x = wcstol ( csPropVal, & p, 10 );
		if ( * p != 0 ) {
			m_editLogView.SetWindowText(existingText + L"\r\n" + CurrentTime() + L" : Scale : " + scaleProfile + L" Incorrect Parameter Value :" + selectedText); //DNS-174
		   return; // Bad Intiger
		}
		
		switch(pDB->dt)
		{
			case pDB->dtBool:
				if (x == 0) { //DNS-174
					pDB->ExecSetterBool(FALSE);
				}
				else if (x == 1) {
					pDB->ExecSetterBool(TRUE);
				}
				else {
					m_editLogView.SetWindowText(existingText + L"\r\n" + CurrentTime() + L" : Scale : " + scaleProfile + L" Incorrect Parameter Value :" + selectedText);
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
	UpdateResultCode();
	if (GetErrorString(OposScale.get_ResultCode()) == "OPOS_E_ILLEGAL") //DNS-174
		m_editLogView.SetWindowText(existingText + L"\r\n" + CurrentTime() + L" : Scale : " + scaleProfile + L" Exception in Set Properties :" + selectedText);
}

CString CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::GetErrorString( long lVal )
{
	CString sRet=_T("");
	switch(lVal)
	{
		case OPOS_SUCCESS : sRet = "OPOS_SUCCESS" ; break;    

			//status
		case OPOS_S_CLOSED : sRet = "OPOS_S_CLOSED" ; break;         
		case OPOS_S_IDLE   : sRet = "OPOS_S_IDLE" ;   break;        
		case OPOS_S_BUSY   : sRet = "OPOS_S_BUSY" ;   break;         
		case OPOS_S_ERROR  : sRet = "OPOS_S_ERROR" ;  break;    

			//Error
		case OPOS_E_CLOSED         : sRet = "OPOS_E_CLOSED" ; break;         
		case OPOS_E_CLAIMED        : sRet = "OPOS_E_CLAIMED" ; break;         
		case OPOS_E_NOTCLAIMED     : sRet = "OPOS_E_NOTCLAIMED" ; break;         
		case OPOS_E_NOSERVICE      : sRet = "OPOS_E_NOSERVICE" ; break;         
		case OPOS_E_DISABLED       : sRet = "OPOS_E_DISABLED" ; break;         
		case OPOS_E_ILLEGAL        : sRet = "OPOS_E_ILLEGAL" ; break;         
		case OPOS_E_NOHARDWARE     : sRet = "OPOS_E_NOHARDWARE" ; break;         
		case OPOS_E_OFFLINE        : sRet = "OPOS_E_OFFLINE" ; break;         
		case OPOS_E_NOEXIST        : sRet = "OPOS_E_NOEXIST" ; break;         
		case OPOS_E_EXISTS         : sRet = "OPOS_E_EXISTS" ; break;         
		case OPOS_E_FAILURE        : sRet = "OPOS_E_FAILURE" ; break;         
		case OPOS_E_TIMEOUT        : sRet = "OPOS_E_TIMEOUT" ; break;         
		case OPOS_E_BUSY           : sRet = "OPOS_E_BUSY" ; break;         
		case OPOS_E_EXTENDED       : sRet = "OPOS_E_EXTENDED" ; break; 
			
		case OPOS_ESCAL_OVERWEIGHT : sRet = "OPOS_ESCAL_OVERWEIGHT" ; break;
		case OPOS_ESCAL_SAME_WEIGHT: sRet = "OPOS_ESCAL_SAME_WEIGHT"; break;
		case OPOS_ESCAL_UNDER_ZERO: sRet = "OPOS_ESCAL_UNDER_ZERO" ; break;

		//	//OpenResult
		//case EOPEN_ALREADYOPEN    : sRet = "EOPEN_ALREADYOPEN    " ; break; 
		//case EOPEN_REGBADNAME     : sRet = "EOPEN_REGBADNAME     " ; break; 
		//case EOPEN_REGPROGID      : sRet = "EOPEN_REGPROGID      " ; break; 
		//case EOPEN_CREATE         : sRet = "EOPEN_CREATE         " ; break; 
		//case EOPEN_BADIF          : sRet = "EOPEN_BADIF          " ; break; 
		//case EOPEN_FAILEDOPEN     : sRet = "EOPEN_FAILEDOPEN     " ; break; 
		//case EOPEN_BADVERSION     : sRet = "EOPEN_BADVERSION     " ; break; 

		//	//SO
		//case EOPENS_NOPORT        : sRet = "EOPENS_NOPORT        " ; break; 
		//case EOPENS_NOTSUPPORTED  : sRet = "EOPENS_NOTSUPPORTED  " ; break; 
		//case EOPENS_CONFIG        : sRet = "EOPENS_CONFIG        " ; break; 
		//case EOPENS_SPECIFIC      : sRet = "EOPENS_SPECIFIC      " ; break; 

		default : sRet.Format(L"%ld",lVal); break;

	}

	return sRet;
}


BEGIN_EVENTSINK_MAP(CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg, CDialog)
	ON_EVENT(CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg, IDC_SCALE1, 1, CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::DataEventScale1, VTS_I4)
	ON_EVENT(CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg, IDC_SCALE1, 3, CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::ErrorEventScale1, VTS_I4 VTS_I4 VTS_I4 VTS_PI4)
	ON_EVENT(CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg, IDC_SCALE1, 5, CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::StatusUpdateEventScale1, VTS_I4)
	ON_EVENT(CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg, IDC_SCALE1, 2, CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::DirectIOEventScale1, VTS_I4 VTS_PI4 VTS_PBSTR)
END_EVENTSINK_MAP()

void CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::DataEventScale1(long Status)
{
	float fweight_1;
	
	fweight_1 = (float)(((float)Status) /1000);
	
	ClearErrorMessage();
	WCHAR wcWeght[10];
	swprintf_s(wcWeght, 10, L"%4.3f",fweight_1);
	m_editWeghtData.SetWindowText(wcWeght);
	m_editWeghtData.UpdateData();
	UpdateResultCode();
}

void CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::ErrorEventScale1(long ResultCode, long ResultCodeExtended, long ErrorLocus, long* pErrorResponse)
{
	WCHAR wcErrorMessage[100];
	swprintf_s(wcErrorMessage, 100, L"Error event received. ResultCode: %s [%d]", GetErrorString(ResultCode), ResultCode);
	m_error_Message.SetWindowText(wcErrorMessage);

	//Clear Read weight text box after error event 
	WCHAR wcWeght[10];
	swprintf_s(wcWeght, 10, L"");
	m_editWeghtData.SetWindowText(wcWeght);

	UpdateResultCode();
}

void CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedButtonClearInput()
{
	m_editReturnValue.SetWindowText(GetErrorString(OposScale.ClearInput()));
	UpdateResultCode();
}

void CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedCheckFreezEvents()
{
	if(m_check_FreezEvents.GetCheck() == BST_CHECKED)
	{
		OposScale.put_FreezeEvents(true);
	}
	else if(m_check_FreezEvents.GetCheck() == BST_UNCHECKED)
	{
		OposScale.put_FreezeEvents(false);
	}
	UpdateResultCode();
}

void CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedCheckDataeventEnable()
{
	if(m_check_DataEventEnable.GetCheck() == BST_CHECKED)
	{
		OposScale.put_DataEventEnabled(true);
	}
	else if(m_check_DataEventEnable.GetCheck() == BST_UNCHECKED)
	{
		OposScale.put_DataEventEnabled(false);
	}
	UpdateResultCode();
}

void CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedCheckAsyncMode()
{
	if(m_check_AsyncMode.GetCheck() == BST_CHECKED)
	{
		OposScale.put_AsyncMode(true);
	}
	else if(m_check_AsyncMode.GetCheck() == BST_UNCHECKED)
	{
		OposScale.put_AsyncMode(false);
	}
	UpdateResultCode();
}

void CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::SetupDirectIO(void)
{
	CComboBox* cmbDIOCommands = (CComboBox*)GetDlgItem(IDC_COMBO_DIO_OpCodes);
	for(size_t i = 0; i < DIOOpCodes.size(); i++)
	{
		cmbDIOCommands->SetItemData(cmbDIOCommands->AddString(DIOOpCodes[i].m_opcode_name),(DWORD_PTR)&DIOOpCodes[i]);
	}
	cmbDIOCommands->SetCurSel(0);
	m_pdioSelectedItem = (PDIO_OPCODES)cmbDIOCommands->GetItemDataPtr(cmbDIOCommands->GetCurSel());
}

void CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnCbnSelchangeCombDioOpcodes()
{
	CComboBox* cmbDIOCommands = (CComboBox*)GetDlgItem(IDC_COMBO_DIO_OpCodes);
	m_pdioSelectedItem = (PDIO_OPCODES)cmbDIOCommands->GetItemDataPtr(cmbDIOCommands->GetCurSel());
	m_editInXml.SetWindowText(m_pdioSelectedItem->m_inxml);
}

void CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedButtonExecute()
{
	LONG retVal;
	CString csInXML;
	m_editInXml.GetWindowText(csInXML);
	
	BSTR inXML = csInXML.AllocSysString();
	LONG a = -1;
	
	retVal = OposScale.DirectIO(m_pdioSelectedItem->m_opcode_value, &a, &inXML);
	m_editReturnValue.SetWindowText(GetErrorString(retVal));
	wchar_t wcstat[10];
	_ltow_s(a, wcstat, 10);
	m_editCSstatus.SetWindowText(wcstat);
	
	if(retVal == OPOS_SUCCESS)
	{
		CString csOutXml(inXML);
		m_editOutXML.SetWindowText(csOutXml);
		if (m_pdioSelectedItem->m_opcode_value == NCRDIO_SCAL_LIVE_WEIGHT)
		{
			m_editOutXML.SetWindowText(wcstat);
			m_editCSstatus.SetWindowText(L"0");

		}
	}
	else
	{
		CString csOutXml(L"");
		m_editOutXML.SetWindowText(csOutXml);
	}
	SysFreeString(inXML);
	UpdateResultCode();
	
}


void CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::StatusUpdateEventScale1(long Data)
{
	long lLiveWeightData = 0;
	float fweight_1;
	WCHAR wcWeght[10];
	ClearErrorMessage();

	switch(Data)
	{
	case SCAL_SUE_STABLE_WEIGHT:
		{
			lLiveWeightData = OposScale.get_ScaleLiveWeight();
			fweight_1 = (float)(((float)lLiveWeightData) /1000);
			
			swprintf_s(wcWeght, 10, L"%4.3f",fweight_1);
			m_edit_LiveWeight.SetWindowText(wcWeght);
		}
		break;
	case SCAL_SUE_WEIGHT_OVERWEIGHT:
			swprintf_s(wcWeght, 10,L"OW");
			m_edit_LiveWeight.SetWindowText(wcWeght);
		break;
	case SCAL_SUE_WEIGHT_UNDER_ZERO:
			swprintf_s(wcWeght, 10,L"UZ");
			m_edit_LiveWeight.SetWindowText(wcWeght);
		break;
	case SCAL_SUE_WEIGHT_UNSTABLE:
			swprintf_s(wcWeght, 10,L"US");
			m_edit_LiveWeight.SetWindowText(wcWeght);
		break;
	case SCAL_SUE_WEIGHT_ZERO:
			swprintf_s(wcWeght, 10,L"WZ");
			m_edit_LiveWeight.SetWindowText(wcWeght);
		break;
	case SCAL_SUE_NOT_READY:
			swprintf_s(wcWeght, 10,L"NR");
			m_edit_LiveWeight.SetWindowText(wcWeght);
		break;
	case OPOS_SUE_POWER_OFF_OFFLINE:
		AfxMessageBox(L"Device power off or offline");
		break;
	case OPOS_SUE_POWER_ONLINE:
		AfxMessageBox(L"Device power online");
		break;
	}
}

void CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedButtonClear()
{
	m_editOutXML.SetWindowText(L"");
	m_editCSstatus.SetWindowText(L"");
}

void CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedCheckStatusnotify()
{
	
	if(m_check_StatusNotify.GetCheck() == BST_CHECKED)
	{
		OposScale.put_StatusNotify(SCAL_SN_ENABLED);
	}
	else if(m_check_StatusNotify.GetCheck() == BST_UNCHECKED)
	{
		OposScale.put_StatusNotify(SCAL_SN_DISABLED);
	}
	UpdateResultCode();
}

// QueryKey - Enumerates the subkeys of key and its associated values.
//     hKey - Key whose subkeys and values are to be enumerated.

 
void CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::QueryKey(HKEY hKey) 
{ 
    TCHAR    achKey[MAX_KEY_LENGTH];   // buffer for subkey name
    DWORD    cbName;                   // size of name string 
    TCHAR    achClass[MAX_PATH] = TEXT("");  // buffer for class name 
    DWORD    cchClassName = MAX_PATH;  // size of class string 
    DWORD    cSubKeys=0;               // number of subkeys 
    DWORD    cbMaxSubKey;              // longest subkey size 
    DWORD    cchMaxClass;              // longest class string 
    DWORD    cValues;              // number of values for key 
    DWORD    cchMaxValue;          // longest value name 
    DWORD    cbMaxValueData;       // longest value data 
    DWORD    cbSecurityDescriptor; // size of security descriptor 
    FILETIME ftLastWriteTime;      // last write time 
 
    DWORD i, retCode; 
 
    //TCHAR  achValue[MAX_VALUE_NAME]; 
    DWORD cchValue = MAX_VALUE_NAME; 
 
    // Get the class name and the value count. 
    retCode = RegQueryInfoKey(
        hKey,                    // key handle 
        achClass,                // buffer for class name 
        &cchClassName,           // size of class string 
        NULL,                    // reserved 
        &cSubKeys,               // number of subkeys 
        &cbMaxSubKey,            // longest subkey size 
        &cchMaxClass,            // longest class string 
        &cValues,                // number of values for this key 
        &cchMaxValue,            // longest value name 
        &cbMaxValueData,         // longest value data 
        &cbSecurityDescriptor,   // security descriptor 
        &ftLastWriteTime);       // last write time 
 
    // Enumerate the subkeys, until RegEnumKeyEx fails.
    
    if (cSubKeys)
    {
        printf( "\nNumber of subkeys: %d\n", int(cSubKeys));

        for (i=0; i<cSubKeys; i++) 
        { 
            cbName = MAX_KEY_LENGTH;
            retCode = RegEnumKeyEx(hKey, i,
                     achKey, 
                     &cbName, 
                     NULL, 
                     NULL, 
                     NULL, 
                     &ftLastWriteTime); 
            if (retCode == ERROR_SUCCESS) 
            {
                _tprintf(TEXT("(%d) %s\n"), i+1, achKey);
				m_combo_SONames.AddString(achKey);
            }
        }
    } 
}

void CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedButtonCheckhealth()
{
	m_editReturnValue.SetWindowText(GetErrorString(OposScale.CheckHealth(OPOS_CH_INTERNAL)));
	UpdateResultCode();
}


//void CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedButton4()
//{
//	m_editReturnValue.SetWindowText(GetErrorString(OposScale.CheckHealth(OPOS_CH_INTERACTIVE)));
//	UpdateResultCode();
//}


void CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedButtonChexternal()
{
	m_editReturnValue.SetWindowText(GetErrorString(OposScale.CheckHealth(OPOS_CH_EXTERNAL)));
	UpdateResultCode();
}


void CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedButtonChinteractive()
{
	m_editReturnValue.SetWindowText(GetErrorString(OposScale.CheckHealth(OPOS_CH_INTERACTIVE)));
	UpdateResultCode();
}


void CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedRetrieveStats()
{
	CString filter;
	m_statisticsFilter.GetWindowTextW(filter);
	BSTR test = filter.AllocSysString();

	if (OposScale.get_CapStatisticsReporting() == FALSE) {
		AfxMessageBox(L"Statistics Reporting is not supported");
		return;
	}

	long lRetVal = OposScale.RetrieveStatistics(&test);

	if (lRetVal == OPOS_SUCCESS)
	{

		CString strTemp;
		strTemp = test;
		AfxMessageBox(strTemp);
	}
	else
	{
		AfxMessageBox(L"Statistics cannot be retrieved.");
	}
}


void CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedResetStats()
{
	CString filter;
	m_statisticsFilter.GetWindowTextW(filter);
	LPCTSTR test = filter.AllocSysString();

	if (OposScale.get_CapStatisticsReporting() == FALSE) {
		AfxMessageBox(L"Statistics Reporting is not supported");
		return;
	}

	if (OposScale.get_CapUpdateStatistics() == FALSE) {

	}

	long lRetVal = OposScale.ResetStatistics(test);

	if (lRetVal == OPOS_SUCCESS)
	{
		AfxMessageBox(L"Statistics successfully reset.");
	}
	else
	{
		AfxMessageBox(L"Statistics reset failed.");
	}
}


void CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnCancelOverride() //DNS-169
{
	if ((GetKeyState(VK_ESCAPE) & 0x8000) == 0)
		OnCancel();
}
void CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::DirectIOEventScale1(long EventNumber, long* pData, BSTR* pString)
{
	CString logMessage(*pString);
	PrintLog(logMessage);
}

void CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::PrintLog(CString logMessage)
{
	logMessage = CurrentTime() + _T("\r\n") + logMessage + _T("\r\n");
	m_editLogView.SendMessage(EM_SETSEL, -1, -1);
	m_editLogView.SendMessage(EM_REPLACESEL, 0, (LPARAM)(LPCTSTR)logMessage);
}

CString CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::CurrentTime()
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

void CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg::OnBnClickedButtonClearLog()
{
	CString empty(L"");
	m_editLogView.SetWindowText(empty);
}
