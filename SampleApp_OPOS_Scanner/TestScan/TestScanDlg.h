/*******************************************************************************************
*
* ©2016 Symbol Technologies LLC. All rights reserved.
*
********************************************************************************************/
// TestScanDlg.h : header file
//
#include "Opos.h"
#include <vector>
/////////////////////////////////////////////////////////////////////
// OPOS "OpenResult" Property Constants
/////////////////////////////////////////////////////////////////////

// The following can be set by the control object.
const LONG OPOSOPENERR  = 300;
const LONG EOPEN_ALREADYOPEN    =  1 + OPOSOPENERR;
    // Control Object already open.
const LONG EOPEN_REGBADNAME     =  2 + OPOSOPENERR;
    // The registry does not contain a key for the specified
    // device name.
const LONG EOPEN_REGPROGID      =  3 + OPOSOPENERR;
    // Could not read the device name key's default value, or
    // could not convert this Prog ID to a valid Class ID.
const LONG EOPEN_CREATE         =  4 + OPOSOPENERR;
    // Could not create a service object instance, or
    // could not get its IDispatch interface.
const LONG EOPEN_BADIF          =  5 + OPOSOPENERR;
    // The service object does not support one or more of the
    // method required by its release.
const LONG EOPEN_FAILEDOPEN     =  6 + OPOSOPENERR;
    // The service object returned a failure status from its
    // open call, but doesn't have a more specific failure code.
const LONG EOPEN_BADVERSION     =  7 + OPOSOPENERR;
    // The service object major version number is not 1.

// The following can be returned by the service object if it
// returns a failure status from its open call.
const LONG OPOSOPENERRSO  = 400;
const LONG EOPENS_NOPORT        =  1 + OPOSOPENERRSO;
    // Port access required at open, but configured port
    // is invalid or inaccessible.
const LONG EOPENS_NOTSUPPORTED  =  2 + OPOSOPENERRSO;
    // Service Object does not support the specified device.
const LONG EOPENS_CONFIG        =  3 + OPOSOPENERRSO;
    // Configuration information error.
const LONG EOPENS_SPECIFIC      = 50 + OPOSOPENERRSO;
    // Errors greater than this value are SO-specific.




// One dimensional symbologies
const LONG SCAN_SDT_UPCA        = 101;  // Digits
const LONG SCAN_SDT_UPCE        = 102;  // Digits
const LONG SCAN_SDT_JAN8        = 103;  // = EAN 8
const LONG SCAN_SDT_EAN8        = 103;  // = JAN 8 (added in 1.2)
const LONG SCAN_SDT_JAN13       = 104;  // = EAN 13
const LONG SCAN_SDT_EAN13       = 104;  // = JAN 13 (added in 1.2)
const LONG SCAN_SDT_TF          = 105;  // (Discrete 2 of 5) Digits
const LONG SCAN_SDT_ITF         = 106;  // (Interleaved 2 of 5) Digits
const LONG SCAN_SDT_Codabar     = 107;  // Digits, -, $, :, /, ., +;
                                        //   4 start/stop characters
                                        //   (a, b, c, d)
const LONG SCAN_SDT_Code39      = 108;  // Alpha, Digits, Space, -, .,
                                        //   $, /, +, %; start/stop (*)
                                        // Also has Full ASCII feature
const LONG SCAN_SDT_Code93      = 109;  // Same characters as Code 39
const LONG SCAN_SDT_Code128     = 110;  // 128 data characters

const LONG SCAN_SDT_UPCA_S      = 111;  // UPC-A with supplemental
                                        //   barcode
const LONG SCAN_SDT_UPCE_S      = 112;  // UPC-E with supplemental
                                        //   barcode
const LONG SCAN_SDT_UPCD1       = 113;  // UPC-D1
const LONG SCAN_SDT_UPCD2       = 114;  // UPC-D2
const LONG SCAN_SDT_UPCD3       = 115;  // UPC-D3
const LONG SCAN_SDT_UPCD4       = 116;  // UPC-D4
const LONG SCAN_SDT_UPCD5       = 117;  // UPC-D5
const LONG SCAN_SDT_EAN8_S      = 118;  // EAN 8 with supplemental
                                        //   barcode
const LONG SCAN_SDT_EAN13_S     = 119;  // EAN 13 with supplemental
                                        //   barcode
const LONG SCAN_SDT_EAN128      = 120;  // EAN 128
const LONG SCAN_SDT_OCRA        = 121;  // OCR "A"
const LONG SCAN_SDT_OCRB        = 122;  // OCR "B"

//  - One dimensional symbologies (added in 1.8)
const LONG SCAN_SDT_RSS14       = 131;  // Reduced Space Symbology - 14 digit GTIN
const LONG SCAN_SDT_RSS_EXPANDED= 132;  // RSS - 14 digit GTIN plus additional fields

// - One dimensional symbologies (added in 1.12)
const LONG SCAN_SDT_GS1DATABAR = 131;  // GS1 DataBar Omnidirectional (normal or stacked)
const LONG SCAN_SDT_GS1DATABAR_E = 132;  // GS1 DataBar Expanded (normal or stacked)

// - One dimensional symbologies (added in Release 1.14)
const LONG SCAN_SDT_ITF_CK      = 133;  // Interleaved 2 of 5 check digit verified and transmitted
const LONG SCAN_SDT_GS1DATABAR_TYPE2 = 134;  // GS1 DataBar Limited
const LONG SCAN_SDT_AMES        = 135;  // Ames Code
const LONG SCAN_SDT_TFMAT       = 136;  // Matrix 2 of 5
const LONG SCAN_SDT_Code39_CK   = 137;  // Code 39 with check character verified and transmitted
const LONG SCAN_SDT_Code32      = 138;  // Code 39 with Mod 32 check character
const LONG SCAN_SDT_CodeCIP     = 139;  // Code 39 CIP
const LONG SCAN_SDT_TRIOPTIC39  = 140;  // Tri-Optic Code 39
const LONG SCAN_SDT_ISBT128     = 141;  // ISBT-128
const LONG SCAN_SDT_Code11      = 142;  // Code 11
const LONG SCAN_SDT_MSI         = 143;  // MSI Code
const LONG SCAN_SDT_PLESSEY     = 144;  // Plessey Code
const LONG SCAN_SDT_TELEPEN     = 145;  // Telepen

//  - Composite Symbologies (added in 1.8)
const LONG SCAN_SDT_CCA         = 151;  // Composite Component A.
const LONG SCAN_SDT_CCB         = 152;  // Composite Component B.
const LONG SCAN_SDT_CCC         = 153;  // Composite Component C.

// - Composite Symbologies (Added in Release 1.14)
const LONG SCAN_SDT_TLC39 = 154;  // TLC-39

// Two dimensional symbologies
const LONG SCAN_SDT_PDF417      = 201;
const LONG SCAN_SDT_MAXICODE    = 202;

//  - Two dimensional symbologies (added in 1.11)
const LONG SCAN_SDT_DATAMATRIX  = 203;  // Data Matrix
const LONG SCAN_SDT_QRCODE      = 204;  // QR Code
const LONG SCAN_SDT_UQRCODE     = 205;  // Micro QR Code
const LONG SCAN_SDT_AZTEC       = 206;  // Aztec
const LONG SCAN_SDT_UPDF417     = 207;  // Micro PDF 417

// - Two dimensional symbologies (Added in Release 1.14)
const LONG SCAN_SDT_GS1DATAMATRIX = 208;  // GS1 DataMatrix
const LONG SCAN_SDT_GS1QRCODE	= 209;	// GS1 QR
const LONG SCAN_SDT_Code49      = 210;  // Code 49
const LONG SCAN_SDT_Code16k     = 211;  // Code 16K
const LONG SCAN_SDT_CodablockA  = 212;  // Codablock A
const LONG SCAN_SDT_CodablockF  = 213;  // Codablock F
const LONG SCAN_SDT_Codablock256 = 214;  // Codablock 256
const LONG SCAN_SDT_HANXIN      = 215;  // Han Xin Code
const LONG SCAN_SDT_GRIDMATRIX	= 216;	// Grid Matrix

// - Postal Code Symbologies (Added in Release 1.14)
const LONG SCAN_SDT_AusPost     = 250;  // Australian Post
const LONG SCAN_SDT_CanPost     = 251;  // Canada Post
const LONG SCAN_SDT_ChinaPost   = 252;  // China Post
const LONG SCAN_SDT_DutchKix    = 253;  // Dutch Post
const LONG SCAN_SDT_InfoMail    = 254;  // InfoMail
const LONG SCAN_SDT_JapanPost   = 255;  // Japan Post
const LONG SCAN_SDT_KoreanPost  = 256;  // Korean Post
const LONG SCAN_SDT_SwedenPost  = 257;  // Sweden Post
const LONG SCAN_SDT_UkPost      = 258;  // UK Post BPO
const LONG SCAN_SDT_UsIntelligent = 259;  // US Intelligent Mail
const LONG SCAN_SDT_UsPlanet    = 260;  // US Planet Code
const LONG SCAN_SDT_PostNet     = 261;  // US Postnet

// Special cases
const LONG SCAN_SDT_OTHER       = 501;  // Start of Scanner-Specific bar
                                        //   code symbologies
const LONG SCAN_SDT_UNKNOWN     =   0;  // Cannot determine the barcode
                                        //   symbology.

#define GET_SCANNERS            1
#define RSM_ATTR_GETALL         5000
#define RSM_ATTR_GET            5001
#define RSM_ATTR_GETNEXT        5002
#define RSM_ATTR_SET            5004
#define RSM_ATTR_STORE          5005
#define NCRDIO_SCAN_NOT_ON_FILE 508
#define NCRDIO_SCAN_RESET       502
#define NCRDIO_SCAN_STATUS      503
#define NCRDIO_SCAN_DIRECT      507

typedef struct _DIO_OPCODES
{
	wchar_t* m_opcode_name;
	int m_opcode_value;
	wchar_t* m_inxml;
}DIO_OPCODES,*PDIO_OPCODES;

static  std::vector< DIO_OPCODES> DIOOpCodes = {
	{L"GET_SCANNERS" , GET_SCANNERS ,L""},
	{L"RSM_ATTR_GETALL" , RSM_ATTR_GETALL ,L"<inArgs>\r\n <scannerID>1</scannerID>\r\n</inArgs>"},
	{L"RSM_ATTR_GET" , RSM_ATTR_GET ,L"<inArgs>\r\n <scannerID>1</scannerID>\r\n <cmdArgs>\r\n  <arg-xml>\r\n   <attrib_list>1</attrib_list>\r\n  </arg-xml>\r\n </cmdArgs>\r\n</inArgs>"},
	{L"RSM_ATTR_GETNEXT" , RSM_ATTR_GETNEXT , L"<inArgs>\r\n <scannerID>1</scannerID>\r\n <cmdArgs>\r\n  <arg-xml>\r\n   <attrib_list>1</attrib_list>\r\n  </arg-xml>\r\n </cmdArgs>\r\n</inArgs>"},
	{L"RSM_ATTR_SET" , RSM_ATTR_SET , L"<inArgs>\r\n <scannerID>1</scannerID>\r\n <cmdArgs>\r\n  <arg-xml>\r\n   <attrib_list>\r\n    <attribute>\r\n     <id>6000</id>\r\n     <datatype>X</datatype>\r\n     <value>2</value>\r\n    </attribute>\r\n   </attrib_list>\r\n  </arg-xml>\r\n </cmdArgs>\r\n</inArgs>"},
	{L"RSM_ATTR_STORE" , RSM_ATTR_STORE , L"<inArgs>\r\n <scannerID>1</scannerID>\r\n <cmdArgs>\r\n  <arg-xml>\r\n   <attrib_list>\r\n    <attribute>\r\n     <id>1</id>\r\n     <datatype>F</datatype>\r\n     <value>True</value>\r\n    </attribute>\r\n   </attrib_list>\r\n  </arg-xml>\r\n </cmdArgs>\r\n</inArgs>"},
	{L"NCRDIO_SCAN_NOT_ON_FILE" , NCRDIO_SCAN_NOT_ON_FILE , L""},
	{L"NCRDIO_SCAN_RESET" , NCRDIO_SCAN_RESET , L""},
	{L"NCRDIO_SCAN_STATUS" , NCRDIO_SCAN_STATUS , L""},
	{L"NCRDIO_SCAN_DIRECT", NCRDIO_SCAN_DIRECT ,L"<inArgs>\r\n <scannerID>1</scannerID>\r\n <opcode>5004</opcode>\r\n <cmdArgs>\r\n  <arg-xml>\r\n   <attrib_list>\r\n    <attribute>\r\n     <id>6000</id>\r\n     <datatype>X</datatype>\r\n     <value>2</value>\r\n    </attribute>\r\n   </attrib_list>\r\n  </arg-xml>\r\n </cmdArgs>\r\n</inArgs>"}
};

/////////////////////////////////////////////////////////////////////////////
// CTestScanDlg dialog
//{{AFX_INCLUDES()
#include "scanner.h"
#include "oposscanner.h"
#include "afxwin.h"
//}}AFX_INCLUDES

class CTestScanDlg : public CDialog
{
// Construction
public:
	short UpdateState();
	short LoadProtocolList();
	CTestScanDlg(CWnd* pParent = NULL);	// standard constructor
    short LoadPropertyList();
	CString GetErrorString( long lVal );
// Dialog Data
	//{{AFX_DATA(CTestScanDlg)
	enum { IDD = IDD_TESTSCAN_DIALOG };
	CComboBox	m_ctProp;
	CEdit	m_editScanData;
	CString	m_strProperty;
	CString	m_strReturnValue;
	CString	m_strResultCode;
	CString	m_strScanDataLabel;
	long	m_nUIEventCount;
	COPOSScanner	m_ctrlScanner;
	long	m_nGoodScanCount;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestScanDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	BOOL m_bIsOpen;
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTestScanDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDataEventScanner1(long lStatus);
	afx_msg void OnOpenSO();
	afx_msg void OnUpdateEdit(CCmdUI *pCmdUI);
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnSelchangePropertiesCombo();
	afx_msg void OnSetButton();
	afx_msg void OnButton3();
	//afx_msg void OnDataEventScanner3(long Status);
	afx_msg void OnClaimButton();
	afx_msg void OnReleaseButton();
//	afx_msg void OnCloseButton();
	afx_msg void OnCheckHealthButton();
	afx_msg void OnLearInputButton();
	afx_msg void OnClearButton();
	afx_msg void OnEventEnableButton();
	afx_msg void OnButton4();
	afx_msg void OnClButton();
	afx_msg void OnDecodeButton();
	afx_msg void OnRetrievButton();
	afx_msg void OnUpdateStatisButton();
	afx_msg void OnResetStatButton();
	afx_msg void OnInputButton();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	long m_nEventCount;
	CString GetScanDataType(long p_nLabelType);
	long m_nReturnValue;
	int m_iScanCount;
public:
	afx_msg void OnBnClickedCloseButton();
	// DataEvent auto enablec check box
	CButton m_check_DataEventAutoenable;
	afx_msg void OnBnClickedCheckAutoevtenable();
	// Tex box to hold the scan count
	CEdit m_edit_ScanCount;
private:
	int SetupDirectIO(void);
	PDIO_OPCODES m_pdioSelectedItem;
public:
	afx_msg void OnCbnSelchangeComboDioOpcodes();
	// Default Scanner ID XML for DIO commands
	char* m_defaultScannerIDXML;
	int m_iFirstScannerID;
	afx_msg void OnBnClickedButtonExecute();
	CEdit m_editOutXML;
	CEdit m_editInXml;
	afx_msg void OnBnClickedButtonClear();
	CEdit m_editCSstatus;
	afx_msg void OnBnClickedButtonCheckhealth();
	afx_msg void OnBnClickedButtonChIntercative();
	void StatusUpdateEventScanner1(long Data);
};


//janaka-original
//CScanner	m_ctrlScanner;
//	CString	m_strProperty;
//	COPOSScanner	m_ctOPOSScanner;
	//end -ajana
