#pragma once
#include <afxwin.h>
#include "uiaSplitButtonProvider.h"

class CMySplitButton :
    public CSplitButton
{
    uiaSplitButtonProvider* m_splitButtonProvider;

public:
    DECLARE_MESSAGE_MAP()
    afx_msg LRESULT OnGetObject(WPARAM wParam, LPARAM lParam);
};

