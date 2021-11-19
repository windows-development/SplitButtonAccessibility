#pragma once
#include <UIAutomation.h>

class uiaSplitButtonProvider :
    public IRawElementProviderSimple,
    public IExpandCollapseProvider
{
    HWND m_hWndref;
public:
    uiaSplitButtonProvider(HWND hWndRef);
    // Inherited via IRawElementProviderSimple
    virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppvObject) override;
    virtual ULONG STDMETHODCALLTYPE AddRef(void) override;
    virtual ULONG STDMETHODCALLTYPE Release(void) override;
    virtual HRESULT STDMETHODCALLTYPE get_ProviderOptions(ProviderOptions* pRetVal) override;
    virtual HRESULT STDMETHODCALLTYPE GetPatternProvider(PATTERNID patternId, IUnknown** pRetVal) override;
    virtual HRESULT STDMETHODCALLTYPE GetPropertyValue(PROPERTYID propertyId, VARIANT* pRetVal) override;
    virtual HRESULT STDMETHODCALLTYPE get_HostRawElementProvider(IRawElementProviderSimple** pRetVal) override;

    // Inherited via IExpandCollapseProvider
    virtual HRESULT STDMETHODCALLTYPE Expand(void) override;
    virtual HRESULT STDMETHODCALLTYPE Collapse(void) override;
    virtual HRESULT STDMETHODCALLTYPE get_ExpandCollapseState(ExpandCollapseState* pRetVal) override;
};

