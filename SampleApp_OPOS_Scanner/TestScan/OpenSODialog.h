/*******************************************************************************************
*
* ©2016 Symbol Technologies LLC. All rights reserved.
*
********************************************************************************************/
// OpenSODialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COpenSODialog dialog

#include "afxwin.h"
class COpenSODialog : public CDialog
{
// Construction
public:

	COpenSODialog(CWnd* pParent = NULL);   // standard constructor
    
// Dialog Data
	//{{AFX_DATA(COpenSODialog)
	enum { IDD = IDD_OPENSO };
	CString	m_strSOName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpenSODialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COpenSODialog)
	afx_msg void OnChangeSoname();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	void QueryKey(HKEY hKey);
	CComboBox CtrlComboSONames;
	virtual BOOL OnInitDialog();
};
