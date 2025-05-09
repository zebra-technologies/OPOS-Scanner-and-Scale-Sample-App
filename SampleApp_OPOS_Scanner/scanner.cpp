/*******************************************************************************************
*
* �2016 Symbol Technologies LLC. All rights reserved.
*
********************************************************************************************/
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


#include "stdafx.h"
#include "scanner.h"

/////////////////////////////////////////////////////////////////////////////
// CScanner

IMPLEMENT_DYNCREATE(CScanner, CWnd)

/////////////////////////////////////////////////////////////////////////////
// CScanner properties

CString CScanner::GetCheckHealthText()
{
	CString result;
	GetProperty(0x1, VT_BSTR, (void*)&result);
	return result;
}

void CScanner::SetCheckHealthText(LPCTSTR propVal)
{
	SetProperty(0x1, VT_BSTR, propVal);
}

BOOL CScanner::GetClaimed()
{
	BOOL result;
	GetProperty(0x2, VT_BOOL, (void*)&result);
	return result;
}

void CScanner::SetClaimed(BOOL propVal)
{
	SetProperty(0x2, VT_BOOL, propVal);
}

BOOL CScanner::GetDataEventEnabled()
{
	BOOL result;
	GetProperty(0x3, VT_BOOL, (void*)&result);
	return result;
}

void CScanner::SetDataEventEnabled(BOOL propVal)
{
	SetProperty(0x3, VT_BOOL, propVal);
}

BOOL CScanner::GetDeviceEnabled()
{
	BOOL result;
	GetProperty(0x4, VT_BOOL, (void*)&result);
	return result;
}

void CScanner::SetDeviceEnabled(BOOL propVal)
{
	SetProperty(0x4, VT_BOOL, propVal);
}

BOOL CScanner::GetFreezeEvents()
{
	BOOL result;
	GetProperty(0x5, VT_BOOL, (void*)&result);
	return result;
}

void CScanner::SetFreezeEvents(BOOL propVal)
{
	SetProperty(0x5, VT_BOOL, propVal);
}

long CScanner::GetOutputID()
{
	long result;
	GetProperty(0x6, VT_I4, (void*)&result);
	return result;
}

void CScanner::SetOutputID(long propVal)
{
	SetProperty(0x6, VT_I4, propVal);
}

long CScanner::GetResultCode()
{
	long result;
	GetProperty(0x7, VT_I4, (void*)&result);
	return result;
}

void CScanner::SetResultCode(long propVal)
{
	SetProperty(0x7, VT_I4, propVal);
}

long CScanner::GetResultCodeExtended()
{
	long result;
	GetProperty(0x8, VT_I4, (void*)&result);
	return result;
}

void CScanner::SetResultCodeExtended(long propVal)
{
	SetProperty(0x8, VT_I4, propVal);
}

long CScanner::GetState()
{
	long result;
	GetProperty(0x9, VT_I4, (void*)&result);
	return result;
}

void CScanner::SetState(long propVal)
{
	SetProperty(0x9, VT_I4, propVal);
}

CString CScanner::GetControlObjectDescription()
{
	CString result;
	GetProperty(0xa, VT_BSTR, (void*)&result);
	return result;
}

void CScanner::SetControlObjectDescription(LPCTSTR propVal)
{
	SetProperty(0xa, VT_BSTR, propVal);
}

long CScanner::GetControlObjectVersion()
{
	long result;
	GetProperty(0xb, VT_I4, (void*)&result);
	return result;
}

void CScanner::SetControlObjectVersion(long propVal)
{
	SetProperty(0xb, VT_I4, propVal);
}

CString CScanner::GetServiceObjectDescription()
{
	CString result;
	GetProperty(0xc, VT_BSTR, (void*)&result);
	return result;
}

void CScanner::SetServiceObjectDescription(LPCTSTR propVal)
{
	SetProperty(0xc, VT_BSTR, propVal);
}

long CScanner::GetServiceObjectVersion()
{
	long result;
	GetProperty(0xd, VT_I4, (void*)&result);
	return result;
}

void CScanner::SetServiceObjectVersion(long propVal)
{
	SetProperty(0xd, VT_I4, propVal);
}

CString CScanner::GetDeviceDescription()
{
	CString result;
	GetProperty(0xe, VT_BSTR, (void*)&result);
	return result;
}

void CScanner::SetDeviceDescription(LPCTSTR propVal)
{
	SetProperty(0xe, VT_BSTR, propVal);
}

CString CScanner::GetDeviceName()
{
	CString result;
	GetProperty(0xf, VT_BSTR, (void*)&result);
	return result;
}

void CScanner::SetDeviceName(LPCTSTR propVal)
{
	SetProperty(0xf, VT_BSTR, propVal);
}

CString CScanner::GetScanData()
{
	CString result;
	GetProperty(0x10, VT_BSTR, (void*)&result);
	return result;
}

void CScanner::SetScanData(LPCTSTR propVal)
{
	SetProperty(0x10, VT_BSTR, propVal);
}

BOOL CScanner::GetAutoDisable()
{
	BOOL result;
	GetProperty(0x11, VT_BOOL, (void*)&result);
	return result;
}

void CScanner::SetAutoDisable(BOOL propVal)
{
	SetProperty(0x11, VT_BOOL, propVal);
}

long CScanner::GetBinaryConversion()
{
	long result;
	GetProperty(0x12, VT_I4, (void*)&result);
	return result;
}

void CScanner::SetBinaryConversion(long propVal)
{
	SetProperty(0x12, VT_I4, propVal);
}

long CScanner::GetCapPowerReporting()
{
	long result;
	GetProperty(0x13, VT_I4, (void*)&result);
	return result;
}

void CScanner::SetCapPowerReporting(long propVal)
{
	SetProperty(0x13, VT_I4, propVal);
}

long CScanner::GetDataCount()
{
	long result;
	GetProperty(0x14, VT_I4, (void*)&result);
	return result;
}

void CScanner::SetDataCount(long propVal)
{
	SetProperty(0x14, VT_I4, propVal);
}

long CScanner::GetPowerNotify()
{
	long result;
	GetProperty(0x15, VT_I4, (void*)&result);
	return result;
}

void CScanner::SetPowerNotify(long propVal)
{
	SetProperty(0x15, VT_I4, propVal);
}

long CScanner::GetPowerState()
{
	long result;
	GetProperty(0x16, VT_I4, (void*)&result);
	return result;
}

void CScanner::SetPowerState(long propVal)
{
	SetProperty(0x16, VT_I4, propVal);
}

BOOL CScanner::GetDecodeData()
{
	BOOL result;
	GetProperty(0x17, VT_BOOL, (void*)&result);
	return result;
}

void CScanner::SetDecodeData(BOOL propVal)
{
	SetProperty(0x17, VT_BOOL, propVal);
}

CString CScanner::GetScanDataLabel()
{
	CString result;
	GetProperty(0x18, VT_BSTR, (void*)&result);
	return result;
}

void CScanner::SetScanDataLabel(LPCTSTR propVal)
{
	SetProperty(0x18, VT_BSTR, propVal);
}

long CScanner::GetScanDataType()
{
	long result;
	GetProperty(0x19, VT_I4, (void*)&result);
	return result;
}

void CScanner::SetScanDataType(long propVal)
{
	SetProperty(0x19, VT_I4, propVal);
}

long CScanner::GetOpenResult()
{
	long result;
	GetProperty(0x25, VT_I4, (void*)&result);
	return result;
}

void CScanner::SetOpenResult(long propVal)
{
	SetProperty(0x25, VT_I4, propVal);
}

/////////////////////////////////////////////////////////////////////////////
// CScanner operations

long CScanner::Open(LPCTSTR lpszDeviceName)
{
	long result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x1a, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		lpszDeviceName);
	return result;
}

long CScanner::Close()
{
	long result;
	InvokeHelper(0x1b, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
	return result;
}

long CScanner::Claim(long lTimeout)
{
	long result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x1c, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		lTimeout);
	return result;
}

long CScanner::Release()
{
	long result;
	InvokeHelper(0x1d, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
	return result;
}

long CScanner::ClearInput()
{
	long result;
	InvokeHelper(0x1e, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
	return result;
}

long CScanner::ClearOutput()
{
	long result;
	InvokeHelper(0x1f, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
	return result;
}

long CScanner::DirectIO(long lCommand, long* plData, BSTR* pstrString)
{
	long result;
	static BYTE parms[] =
		VTS_I4 VTS_PI4 VTS_PBSTR;
	InvokeHelper(0x20, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		lCommand, plData, pstrString);
	return result;
}

long CScanner::CheckHealth(long lLevel)
{
	long result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x21, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		lLevel);
	return result;
}

long CScanner::ClaimDevice(long lTimeout)
{
	long result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x22, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		lTimeout);
	return result;
}

long CScanner::ReleaseDevice()
{
	long result;
	InvokeHelper(0x23, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
	return result;
}

long CScanner::CloseDevice()
{
	long result;
	InvokeHelper(0x24, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
	return result;
}

void CScanner::AboutBox()
{
	InvokeHelper(0xfffffdd8, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}
