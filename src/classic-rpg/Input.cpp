#include "h/Input.h"
#include <Windows.h>
#include "h/Logger.h"

Input::Input()
{
	bindings_ = common::Dictionary<Actions, Keys>();
}


Input::~Input()
{
}

bool Input::isAction(Actions action) {
	if(!bindings_.containsKey(action)) {
		Logger::instance()->log("Action {ACTION_NAME} is not bound to any key", Logger::MsgPrfxWarning);
		return false;
	}

	if(GetKeyState(bindings_[action]) & 0x8000) {
		return true;
	}

	return false;
}

void Input::bind(Actions action, Keys key) {
	if(bindings_.containsKey(action)) {
		Logger::instance()->log("Action {ACTION_NAME} is alredy bound to a key", Logger::MsgPrfxWarning);
		return;
	}

	bindings_.add(action, key);
}

void Input::unbind(Actions action) {
	bindings_.remove(action);
}
