#include "h/InputHook.h"

HHOOK InputHook::m_hookId = NULL;

InputHook::InputHook(){
	InputHook::m_proc = (HOOKPROC)InputHook::hookCallback;
	InputHook::m_hookId = setHook(m_proc);
}

InputHook::~InputHook() {
	InputHook::unHook(InputHook::m_hookId);
}

HHOOK InputHook::setHook(HOOKPROC lpfn){
	HWND hwnd = GetConsoleWindow();

#ifdef _WIN64
	HINSTANCE hmod = (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE);
#else
	HINSTANCE hmod = (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE);
#endif
   	return SetWindowsHookEx(WH_KEYBOARD_LL, lpfn, hmod, 0);
}

bool InputHook::unHook(HHOOK hhk) {
	return UnhookWindowsHookEx(hhk);
}

LRESULT CALLBACK InputHook::hookCallback(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode >= 0 && wParam == WM_KEYDOWN)
	{
		std::cout << "test";
	}

	if (nCode >= 0 && wParam == WM_KEYUP)
	{
		// lParam is the Key pressed
	}

	return CallNextHookEx(InputHook::m_hookId, nCode, wParam, lParam);
}

