#include "h/Input.h"
#include <Windows.h>
#include "h/Logger.h"
#include <sstream>

Input::Input() {
	bindings = common::Dictionary<Actions, Keys>();
}

Input::~Input() {
}

bool Input::isAction(Actions action) {
	if (!bindings.containsKey(action)) {
		return false;
	}

	if (GetKeyState(bindings[action]) & 0x8000) {
		return true;
	}

	return false;
}

void Input::bind(Actions action, Keys key) {
	if (bindings.containsKey(action)) {
		auto ss = stringstream();
		ss << "Action " << action << " is alredy bound to a key";
		Logger::instance()->log(ss.str(), Logger::MsgPrfxWarning);
		return;
	}

	bindings.add(action, key);
}

void Input::unbind(Actions action) {
	bindings.remove(action);
}