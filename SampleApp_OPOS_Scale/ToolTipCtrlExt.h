#pragma once
#include "afxcmn.h"
#include "afxwin.h"


/**
* This is a helper class to draw tooltip text for UI controllers.
*/
class CToolTipCtrlExt : public CToolTipCtrl
{
	DECLARE_DYNAMIC(CToolTipCtrlExt)

public:
	CToolTipCtrlExt();
	virtual ~CToolTipCtrlExt();

	/**
	* Set the tooltip text for UI controllers.
	* @param display_text - The tooltip text to be desplayed.
	* @param pWInd - Reference to the UI control which the tooltip should associate with.
	*/
	void DisplayTooltipText(LPCTSTR display_text,	CWnd* pWnd);

protected:
	DECLARE_MESSAGE_MAP()
};


