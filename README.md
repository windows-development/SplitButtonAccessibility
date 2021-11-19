# IExpandCollapseProvider sample app (MFC Win32)

https://github.com/microsoft/axe-windows/issues/653

![Image](https://github.com/windows-development/SplitButtonAccessibility/blob/master/misc/ui.png?raw=true)

A split button is a win32 button control with BS_SPLITBUTTON style. Such a split button natively implements InvokeProvider, and IExpandCollapseProvider
interfaces. This control has window of its own.

When split button is part of a tool bar (child of a toolbar), it doesn't implement these.
Such a split button which is a child of a toolbar is does not has a window of its own.
Accessibility insights complains that the required interfaces are not present.

This sample app has been created to represent such a scenario - a split button which doesn't have any of these interfaces implemented by default.
Although this sample uses native win32 split button (which already has these implemented), it is intended to represent the split button which
is a child of a win32 toolbar. The child button was present in a separate application I was working on. Initially Accessibility insight only complained about
IExpandCollapseProvider missing. When I implemented this interface, I started getting a new error - "A split button must not support both the Invoke and Toggle patterns".
The error text is ambiguous. It led me to believe that my control is implementing both IInvokeProvider, and IToggleProvider interfaces. Debugging through source code of
accessibility insights, and AXE (https://github.com/microsoft/axe-windows) I realizes that my control doesn't implemented either.

Thus either of the following should be the case:

1. The error is a false positive
2. The error perhaps is intended to imply that while a control should not imeplement both, it should implement at least one. If so, the error string should explicitly state this - "A split button must not support both the Invoke and Toggle patterns, but should support at least one".

I had created a new issue with AXE, and a sampe app was requested. This is the required app.
https://github.com/microsoft/axe-windows/issues/653

## Code overview:
1. CMySplitButton is the class which derives from CSplitButton, and subclasses the control IDC_BUTTON_SPLIT (shown as "Split Btn" in dialog).
2. uiaSplitButtonProvider is the class which implements automation provider interfaces. This class only implements IRawElementProviderSimple, and IExpandCollapseProvider. It doesn't support IInvokeProvider, nor does it support IToggleProvider. This is intentional to simulate the scenario I was seeing.
3. AccessibilityInsightsResults solution folder contains results of running accessibility insights on this sample app. ExpandCollapse.a11ytest file contains results of running the tool after IExpandCollapse was implemented.

Note that in this sample app reference counting etc. is not done.

## Build, and run

This can be compiled with Visual Studio 2022. It will require MFC libraries.
Compiled binaries will be in `x64\Debug`
