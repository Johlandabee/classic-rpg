#pragma once
#include <windows.h>
#include <iostream>
class InputHook {
public:
	InputHook();
	~InputHook();
	HHOOK setHook(HOOKPROC lpfn);
	bool unHook(HHOOK hhk);
	static LRESULT CALLBACK hookCallback(int nCode, WPARAM wParam, LPARAM lParam);

private:
	HOOKPROC m_proc;
    static HHOOK m_hookId;
};