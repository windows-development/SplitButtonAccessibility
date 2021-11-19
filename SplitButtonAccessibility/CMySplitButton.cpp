#include "pch.h"
#include "CMySplitButton.h"
#include <UIAutomation.h>

#pragma comment (lib, "Uiautomationcore.lib")

BEGIN_MESSAGE_MAP(CMySplitButton, CSplitButton)
	ON_MESSAGE(WM_GETOBJECT, OnGetObject)
END_MESSAGE_MAP()

LRESULT CMySplitButton::OnGetObject(WPARAM wParam, LPARAM lParam)
{
	if (lParam == UiaRootObjectId)
	{
		if (m_splitButtonProvider == nullptr)
		{
			m_splitButtonProvider = new uiaSplitButtonProvider(GetSafeHwnd());
		}
		IRawElementProviderSimple* provider = dynamic_cast<IRawElementProviderSimple*>(m_splitButtonProvider);
		return UiaReturnRawElementProvider(GetSafeHwnd(), wParam, lParam, provider);
	}
	return 0;
}
