/*******************************************************************************************
*
* ©2016 Symbol Technologies LLC. All rights reserved.
*
********************************************************************************************/
// MotorolaOPOSScaleSampleAppDlg.h : header file
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
	{L"NCRDIO_SCAL_DIRECT", NCRDIO_SCAL_DIRECT , L"<inArgs>\r\n <scannerID>1</scannerID>\r\n <opcode>5004</opcode>\r\n <cmdArgs>\r\n  <arg-xml>\r\n   <attrib_list>\r\n    <attribute>\r\n     <id>6000</id>\r\n     <datatype>X</datatype>\r\n     <value>2</value>\r\n    </attribute>\r\n   </attrib_list>\r\n  </arg-xml>\r\n </cmdArgs>\r\n</inArgs>"}

};

#define MAX_KEY_LENGTH 255
#define MAX_VALUE_NAME 16383
// CMotorolaOPOSScaleSampleAppDlg dialog
class CMotorolaOPOSScaleSampleAppDlg : public CDialog
{
// Construction
public:
	CMotorolaOPOSScaleSampleAppDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MOTOROLAOPOSSCALESAMPLEAPP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// This is the variable for OPOS Scale
	CScale1 OposScale;
	afx_msg void OnBnClickedButtonOpen();
	afx_msg void OnBnClickedButtonClaim();
	CListCtrl CtrlList;
	afx_msg void OnBnClickedButtonDeviceEnable();
	afx_msg void OnBnClickedButtonReadWeight();
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
};
