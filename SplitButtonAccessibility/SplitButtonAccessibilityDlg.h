
// SplitButtonAccessibilityDlg.h : header file
//

#pragma once

#include "CMySplitButton.h"

// CSplitButtonAccessibilityDlg dialog
class CSplitButtonAccessibilityDlg : public CDialogEx
{
// Construction
public:
	CSplitButtonAccessibilityDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SPLITBUTTONACCESSIBILITY_DIALOG };
#endif

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
	// Control variable for IDC_BUTTON_SPLIT split button
	CMySplitButton m_splitButton;
};
