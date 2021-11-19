#include "pch.h"
#include "uiaSplitButtonProvider.h"

uiaSplitButtonProvider::uiaSplitButtonProvider(HWND hWndRef) : m_hWndref(hWndRef)
{
}

HRESULT STDMETHODCALLTYPE uiaSplitButtonProvider::QueryInterface(REFIID riid, void** ppvObject)
{
    if (riid == IID_IRawElementProviderSimple)
    {
        *ppvObject = dynamic_cast<IUnknown*>(dynamic_cast<IRawElementProviderSimple*>(this));
    }else if (riid == IID_IExpandCollapseProvider)
    {
        *ppvObject = dynamic_cast<IUnknown*>(dynamic_cast<IExpandCollapseProvider*>(this));
    }
    else
    {
        return E_NOINTERFACE;
    }
    //don't do ref counting for this sample app
    return S_OK;
}

ULONG STDMETHODCALLTYPE uiaSplitButtonProvider::AddRef(void)
{
    return 1;//don't do ref counting for this sample app
}

ULONG STDMETHODCALLTYPE uiaSplitButtonProvider::Release(void)
{
    return 1;//don't do ref counting for this sample app
}

HRESULT STDMETHODCALLTYPE uiaSplitButtonProvider::get_ProviderOptions(ProviderOptions* pRetVal)
{
    return ProviderOptions_ServerSideProvider;
}

HRESULT STDMETHODCALLTYPE uiaSplitButtonProvider::GetPatternProvider(PATTERNID patternId, IUnknown** pRetVal)
{
    if (patternId == UIA_ExpandCollapsePatternId)
    {
        *pRetVal = dynamic_cast<IUnknown*>(dynamic_cast<IExpandCollapseProvider*>(this));
    }
    return S_OK;
}

HRESULT STDMETHODCALLTYPE uiaSplitButtonProvider::GetPropertyValue(PROPERTYID propertyId, VARIANT* pRetVal)
{
    switch (propertyId)
    {
    case UIA_NamePropertyId:
        pRetVal->vt = VT_BSTR;
        pRetVal->bstrVal = SysAllocString(L"Split btn");
        break;
    case UIA_ControlTypePropertyId:
        pRetVal->vt = VT_I4;
        pRetVal->lVal = UIA_SplitButtonControlTypeId;
        break;
    case UIA_LocalizedControlTypePropertyId:
        pRetVal->vt = VT_BSTR;
        pRetVal->bstrVal = SysAllocString(L"Split button");
        break;
    case UIA_BoundingRectanglePropertyId:
    {
        pRetVal->vt = VT_R8 | VT_ARRAY;

        CRect rc;
        ::GetClientRect(m_hWndref, &rc);

        CPoint pts[2];
        CPoint& tl = pts[0]; //top left
        CPoint& br = pts[1]; //bottom right

        tl = rc.TopLeft();
        br = rc.BottomRight();

        ::MapWindowPoints(m_hWndref, NULL, pts, 2);//client to screen coords
        rc = CRect(tl, br);

        SAFEARRAY* psa = SafeArrayCreateVector(VT_R8, 0, 4);
        long index = 0;
        SafeArrayPutElement(psa, &index, &rc.left);
        index++;
        SafeArrayPutElement(psa, &index, &rc.top);
        index++;

        long width = rc.Width();
        long height = rc.Height();

        SafeArrayPutElement(psa, &index, &width);
        index++;

        SafeArrayPutElement(psa, &index, &height);
        index++;

        pRetVal->parray = psa;
    }
    break;
    default:
        break;
    }
    return S_OK;
}

HRESULT STDMETHODCALLTYPE uiaSplitButtonProvider::get_HostRawElementProvider(IRawElementProviderSimple** pRetVal)
{
    return UiaHostProviderFromHwnd(m_hWndref, pRetVal);
}

HRESULT STDMETHODCALLTYPE uiaSplitButtonProvider::Expand(void)
{
    return S_OK;//do nothing for this dummy app
}

HRESULT STDMETHODCALLTYPE uiaSplitButtonProvider::Collapse(void)
{
    return S_OK;//do nothing for this dummy app
}

HRESULT STDMETHODCALLTYPE uiaSplitButtonProvider::get_ExpandCollapseState(ExpandCollapseState* pRetVal)
{
    *pRetVal = ExpandCollapseState_Collapsed;//dummy app - always return a fixed value
    return S_OK;
}
