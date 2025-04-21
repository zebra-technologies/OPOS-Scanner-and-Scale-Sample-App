/*******************************************************************************************
*
* ©2016 Symbol Technologies LLC. All rights reserved.
*
********************************************************************************************/
// Motorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg.h : header file
//

#pragma once
#include "scale.h"
#include "afxcmn.h"
#include "afxwin.h"
#include "Includes\Opos.h"
#include "Includes\OposScal.h"
#include "Includes\Opos.hi"
#include "Includes\OposScal.hi"
#include "TooltipCtrlExt.h"
#include <vector>

#define GET_SCANNERS            1
#define RSM_ATTR_GETALL         5000
#define RSM_ATTR_GET            5001
#define RSM_ATTR_GETNEXT        5002
#define RSM_ATTR_SET            5004
#define RSM_ATTR_STORE          5005
#define NCRDIO_SCAL_LIVE_WEIGHT 604
#define NCRDIO_SCALE_STATUS     601
#define NCRDIO_SCAL_DIRECT      605

//RTA Event Configuration OpCodes 
#define RTA_GET_SUPPORTED       5500
#define RTA_REGISTER            5501
#define RTA_UNREGISTER          5502
#define RTA_GET_EVENT_STATUS    5503
#define RTA_SET_EVENT_STATUS    5504
#define RTA_SUSPEND             5505
#define RTA_GETSTATE            5506

typedef struct _DIO_OPCODES
{
	wchar_t* m_opcode_name;
	int m_opcode_value;
	wchar_t* m_inxml;
}DIO_OPCODES,*PDIO_OPCODES;

static std::vector<DIO_OPCODES> DIOOpCodes = {
	{L"GET_SCANNERS" , GET_SCANNERS ,L""},
	{L"RSM_ATTR_GETALL" , RSM_ATTR_GETALL ,L"<inArgs>\r\n <scannerID>1</scannerID>\r\n</inArgs>"},
	{L"RSM_ATTR_GET" , RSM_ATTR_GET ,L"<inArgs>\r\n <scannerID>1</scannerID>\r\n <cmdArgs>\r\n  <arg-xml>\r\n   <attrib_list>1</attrib_list>\r\n  </arg-xml>\r\n </cmdArgs>\r\n</inArgs>"},
	{L"RSM_ATTR_GETNEXT" , RSM_ATTR_GETNEXT , L"<inArgs>\r\n <scannerID>1</scannerID>\r\n <cmdArgs>\r\n  <arg-xml>\r\n   <attrib_list>1</attrib_list>\r\n  </arg-xml>\r\n </cmdArgs>\r\n</inArgs>"},
	{L"RSM_ATTR_SET" , RSM_ATTR_SET , L"<inArgs>\r\n <scannerID>1</scannerID>\r\n <cmdArgs>\r\n  <arg-xml>\r\n   <attrib_list>\r\n    <attribute>\r\n     <id>6000</id>\r\n     <datatype>X</datatype>\r\n     <value>2</value>\r\n    </attribute>\r\n   </attrib_list>\r\n  </arg-xml>\r\n </cmdArgs>\r\n</inArgs>"},
	{L"RSM_ATTR_STORE" , RSM_ATTR_STORE , L"<inArgs>\r\n <scannerID>1</scannerID>\r\n <cmdArgs>\r\n  <arg-xml>\r\n   <attrib_list>\r\n    <attribute>\r\n     <id>1</id>\r\n     <datatype>F</datatype>\r\n     <value>True</value>\r\n    </attribute>\r\n   </attrib_list>\r\n  </arg-xml>\r\n </cmdArgs>\r\n</inArgs>"},
	{L"NCRDIO_SCAL_LIVE_WEIGHT", NCRDIO_SCAL_LIVE_WEIGHT , L""},
	{L"NCRDIO_SCALE_STATUS", NCRDIO_SCALE_STATUS , L""},
	{L"NCRDIO_SCAL_DIRECT", NCRDIO_SCAL_DIRECT , L"<inArgs>\r\n <scannerID>1</scannerID>\r\n <opcode>5004</opcode>\r\n <cmdArgs>\r\n  <arg-xml>\r\n   <attrib_list>\r\n    <attribute>\r\n     <id>6000</id>\r\n     <datatype>X</datatype>\r\n     <value>2</value>\r\n    </attribute>\r\n   </attrib_list>\r\n  </arg-xml>\r\n </cmdArgs>\r\n</inArgs>"},
	{L"RTA_GET_SUPPORTED", RTA_GET_SUPPORTED , L"<inArgs>\r\n <scannerID>1</scannerID>\r\n</inArgs>"},
	{L"RTA_REGISTER", RTA_REGISTER ,L"<inArgs>\r\n <scannerID>1</scannerID>\r\n <cmdArgs>\r\n  <arg-xml>\r\n   <rtaevent_list>\r\n    <rtaevent>\r\n     <id>38004</id>\r\n     <stat>7</stat>\r\n     <onlimit>Not set</onlimit>\r\n     <offlimit>Not applicable</offlimit>\r\n    </rtaevent>\r\n    <rtaevent>\r\n     <id>25015</id>\r\n     <stat>13</stat>\r\n     <onlimit>Not applicable</onlimit>\r\n     <offlimit>Not applicable</offlimit>\r\n    </rtaevent>\r\n   </rtaevent_list>\r\n  </arg-xml>\r\n </cmdArgs>\r\n</inArgs>"},
	{L"RTA_UNREGISTER", RTA_UNREGISTER ,L"<inArgs>\r\n <scannerID>1</scannerID>\r\n <cmdArgs>\r\n <arg-xml>\r\n  <rtaevent_list>\r\n   <rtaevent>\r\n    <id>30012</id>\r\n    <stat>7</stat>\r\n   </rtaevent>\r\n   <rtaevent>\r\n    <id>616</id>\r\n    <stat>2</stat>\r\n   </rtaevent>\r\n  </rtaevent_list>\r\n </arg-xml>\r\n </cmdArgs>\r\n</inArgs>"},
	{L"RTA_GET_EVENT_STATUS", RTA_GET_EVENT_STATUS ,L"<inArgs>\r\n <scannerID>1</scannerID>\r\n</inArgs>"},
	{L"RTA_SET_EVENT_STATUS", RTA_SET_EVENT_STATUS ,L"<inArgs>\r\n <scannerID>1</scannerID>\r\n <cmdArgs>\r\n <arg-xml>\r\n  <rtaevent_list>\r\n   <rtaevent>\r\n    <id>30012</id>\r\n    <stat>7</stat>\r\n    <reported>1</reported>\r\n   </rtaevent>\r\n   <rtaevent>\r\n    <id>616</id>\r\n    <stat>2</stat>\r\n    <reported>0</reported>\r\n   </rtaevent>\r\n  </rtaevent_list>\r\n </arg-xml>\r\n </cmdArgs>\r\n</inArgs>"},
	{L"RTA_SUSPEND", RTA_SUSPEND ,L"<inArgs>\r\n <scannerID>1</scannerID>\r\n <cmdArgs>\r\n  <arg-bool>false</arg-bool>\r\n </cmdArgs>\r\n</inArgs>"},
	{L"RTA_GETSTATE", RTA_GETSTATE ,L"<inArgs>\r\n <scannerID>1</scannerID>\r\n</inArgs>"}
};

#define MAX_KEY_LENGTH 255
#define MAX_VALUE_NAME 16383
// CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg dialog
class CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg : public CDialog
{
// Construction
public:
	CMotorola_ScannerSDK_SampleApp_OPOS_Scale_Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MOTOROLA_SCANNERSDK_SAMPLEAPP_OPOS_SCALE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCancelOverride(); //DNS-169
	DECLARE_MESSAGE_MAP()
public:
	// This is the variable for OPOS Scale
	CScale1 OposScale;
	afx_msg void OnBnClickedButtonOpen();
	afx_msg void OnBnClickedButtonClaim();
	CListCtrl CtrlList;
	afx_msg void OnBnClickedButtonDeviceEnable();
	afx_msg void OnBnClickedButtonReadWeight();
	void ClearErrorMessage();
	afx_msg void OnCbnSelchangeComboScaleProperties();
private:
	// UPOS Scale Properties
	CComboBox m_cmbProperties;
	void LoadProperties();
	CEdit m_editLogicalDeviceName;
	CEdit m_editWeghtData;
	LONG UpdateResultCode();
	CString GetErrorString( long lVal );
	PDIO_OPCODES m_pdioSelectedItem;
	void SetupDirectIO(void);
	CToolTipCtrlExt m_ctrl_tooltip_ext;
	void PrintLog(CString logMessage);
	CString CurrentTime();
	CString scaleProfile; //DNS-174
public:
	afx_msg void OnBnClickedButtonDeviceDisable();
	afx_msg void OnBnClickedButtonRelease();
	afx_msg void OnBnClickedButtonClose();
	CEdit m_editResultCode;
	afx_msg void OnBnClickedButtonZeroScale();
	CEdit m_editPropValue;
	afx_msg void OnBnClickedButtonUpdate();
	CEdit m_editKgPounds;
	CEdit m_editReturnValue;
	CEdit m_editStatus;
	DECLARE_EVENTSINK_MAP()
	void DataEventScale1(long Status);
	void ErrorEventScale1(long ResultCode, long ResultCodeExtended, long ErrorLocus, long* pErrorResponse);
	afx_msg void OnBnClickedButtonClearInput();
	afx_msg void OnBnClickedCheckFreezEvents();
	afx_msg void OnBnClickedCheckDataeventEnable();
	// Freez Events CheckBox
	CButton m_check_FreezEvents;
	// Enable DataEvents check box
	CButton m_check_DataEventEnable;
	afx_msg void OnBnClickedCheckAsyncMode();
	// Async Mode Check Box
	CButton m_check_AsyncMode;
	afx_msg void OnBnClickedButtonExecute();
	CEdit m_editInXml;
	CEdit m_editOutXML;
	afx_msg void OnCbnSelchangeCombDioOpcodes();
	void StatusUpdateEventScale1(long Data);
	afx_msg void OnBnClickedButtonClear();
	CEdit m_edit_LiveWeight;
	afx_msg void OnBnClickedCheckStatusnotify();
	CButton m_check_StatusNotify;
	CEdit m_editCSstatus;
	void QueryKey(HKEY hKey);
	CComboBox m_combo_SONames;
	afx_msg void OnBnClickedButtonCheckhealth();
	afx_msg void OnBnClickedButtonChexternal();
	afx_msg void OnBnClickedButtonChinteractive();
	CEdit m_error_Message;
	CEdit m_statisticsFilter;
	afx_msg void OnBnClickedRetrieveStats();
	afx_msg void OnBnClickedResetStats();
	void DirectIOEventScale1(long EventNumber, long* pData, BSTR* pString);
	CEdit m_editLogView;
	afx_msg void OnBnClickedButtonClearLog();
};
