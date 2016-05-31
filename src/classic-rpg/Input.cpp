#include "h/Input.h"
#include "h/Logger.h"
#include <sstream>
#include <windows.h>

Input::Input() {
	bindings = Dictionary<Actions, Binding*>();
}

Input::~Input() {
}

bool Input::isAction(Actions action) {
	if (!bindings.containsKey(action)) {
		return false;
	}

	if (GetKeyState(bindings[action]->getKey()) & 0x8000 && bindings[action]->ready()) {
		return true;
	}

	return false;
}

void Input::bind(Actions action, Keys key, unsigned const int timeout) {
	if (bindings.containsKey(action)) {
		auto ss = stringstream();
		ss << "Action " << action << " is alredy bound to a key";
		Logger::instance()->log(ss.str(), Logger::MsgPrfxWarning);
		return;
	}

	bindings.add(action, new Binding(key, timeout));
}

void Input::unbind(Actions action) {
	bindings.remove(action);
}

void Input::loadBindings(const Config& config) {
	bind(EngineShutDown, static_cast<Keys>(config.getIntValue("EngineShutDown", 27)));
	bind(EngineTogglePerfInfo, static_cast<Keys>(config.getIntValue("EngineTogglePerfInfo", 112)), 150);
	bind(PlayerMoveUp, static_cast<Keys>(config.getIntValue("PlayerMoveUp", 87)));
	bind(PlayerMoveDown, static_cast<Keys>(config.getIntValue("PlayerMoveDown", 83)));
	bind(PlayerMoveLeft, static_cast<Keys>(config.getIntValue("PlayerMoveLeft", 65)));
	bind(PlayerMoveRight, static_cast<Keys>(config.getIntValue("PlayerMoveUp", 68)));
	bind(PlayerInteract, static_cast<Keys>(config.getIntValue("PlayerInteract", 32)));
}
