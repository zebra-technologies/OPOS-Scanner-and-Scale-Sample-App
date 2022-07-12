/*******************************************************************************************
*
* ©2016 Symbol Technologies LLC. All rights reserved.
*
********************************************************************************************/
// OpenSODialog.cpp : implementation file
//

#include "stdafx.h"
#include "testscan.h"
#include "OpenSODialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define MAX_KEY_LENGTH 255
#define MAX_VALUE_NAME 16383

/////////////////////////////////////////////////////////////////////////////
// COpenSODialog dialog


COpenSODialog::COpenSODialog(CWnd* pParent /*=NULL*/)
	: CDialog(COpenSODialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(COpenSODialog)
	m_strSOName = _T("");
	//}}AFX_DATA_INIT
}


void COpenSODialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COpenSODialog)
	//DDX_Text(pDX, IDC_SONAME, m_strSOName);
	DDX_Text(pDX, IDC_COMBO_SO_NAMES, m_strSOName);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_COMBO_SO_NAMES, CtrlComboSONames);
}



BEGIN_MESSAGE_MAP(COpenSODialog, CDialog)
	//{{AFX_MSG_MAP(COpenSODialog)
	//ON_EN_CHANGE(IDC_SONAME, OnChangeSoname)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &COpenSODialog::OnBnClickedOk)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COpenSODialog message handlers

void COpenSODialog::OnChangeSoname() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}




void COpenSODialog::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();

}

void COpenSODialog::QueryKey(HKEY hKey) 
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
        printf( "\nNumber of subkeys: %d\n", cSubKeys);

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
				CtrlComboSONames.AddString(achKey);
            }
        }
    } 
}


BOOL COpenSODialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	HKEY hTestKey;
	if( RegOpenKeyEx( HKEY_LOCAL_MACHINE, TEXT("SOFTWARE\\OLEforRetail\\ServiceOPOS\\Scanner"), 0, KEY_READ, &hTestKey) == ERROR_SUCCESS)
	{
		QueryKey(hTestKey);
	}
   
	RegCloseKey(hTestKey);
	CtrlComboSONames.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
