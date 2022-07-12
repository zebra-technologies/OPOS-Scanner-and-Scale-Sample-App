// CToolTipCtrlExt.cpp : implementation file
//
#include "stdafx.h"
//#include "pch.h"
#include "OPOSScaleSampleApp.h"
#include "ToolTipCtrlExt.h"


// CToolTipCtrlExt

IMPLEMENT_DYNAMIC(CToolTipCtrlExt, CToolTipCtrl)

CToolTipCtrlExt::CToolTipCtrlExt()
{

}

CToolTipCtrlExt::~CToolTipCtrlExt()
{
}


BEGIN_MESSAGE_MAP(CToolTipCtrlExt, CToolTipCtrl)
END_MESSAGE_MAP()

//Display the tooltip text for a given window
void CToolTipCtrlExt::DisplayTooltipText(
	LPCTSTR display_text, CWnd* pWnd)
{
	//Declare the Structure
	TOOLINFO ti;

	//Specify the tooltip text and window handle 
	//to the tool that requires tooltip
	ti.cbSize = sizeof(TOOLINFO);
	ti.lpszText = (LPWSTR)display_text;
	ti.hwnd = pWnd->GetParent()->GetSafeHwnd();
	ti.uFlags = TTF_IDISHWND | TTF_SUBCLASS;
	ti.uId = (UINT_PTR)pWnd->GetSafeHwnd();

	//Send a window message to the control's 
	//window procedure (CToolTipCtrl will take care)
	SendMessage(TTM_ADDTOOL, 0, (LPARAM)&ti);
}

