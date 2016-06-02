#pragma once
#include "Actions.h"
#include "Binding.h"
#include "Config.h"
#include "Dictionary.h"
#include <chrono>
#include <windows.h>

using namespace chrono;
using namespace std;

class Input {
public:
	Input();
	~Input();

	bool isAction(Actions action);
	bool isFocus() const;
	void bind(Actions action, Keys key, unsigned const int timeout = 0);
	void loadBindings(const Config& config);
	void processEvents();
	void unbind(Actions action);

private:
	static const unsigned short EVENT_THRESHOLD = 256;

	bool focus = true;
	Dictionary<Actions, Binding*> bindings;
	DWORD events = 0;
	DWORD read = 0;
	HANDLE handle = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD input[EVENT_THRESHOLD];	
};
