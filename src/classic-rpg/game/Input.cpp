#include "Input.h"
#include "Logger.h"
#include <iostream>
#include <sstream>

using namespace Common;
using namespace Engine;

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

BOOLEAN Input::isFocus() const {
	return focus;
}

void Input::bind(Actions action, Keys key, unsigned const int timeout) {
	if (bindings.containsKey(action)) {
		auto ss = stringstream();
		ss << "Action " << action << " is already bound to a key";
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
	bind(PlayerInteract, static_cast<Keys>(config.getIntValue("PlayerInteract", 32)));
	bind(PlayerMoveDown, static_cast<Keys>(config.getIntValue("PlayerMoveDown", 83)));
	bind(PlayerMoveLeft, static_cast<Keys>(config.getIntValue("PlayerMoveLeft", 65)));
	bind(PlayerMoveRight, static_cast<Keys>(config.getIntValue("PlayerMoveUp", 68)));
	bind(PlayerMoveUp, static_cast<Keys>(config.getIntValue("PlayerMoveUp", 87)));
}

void Input::processEvents() {
	read = 0;
	events = 0;

	GetNumberOfConsoleInputEvents(this->handle, &events);
	auto process = events < EVENT_THRESHOLD ? events : EVENT_THRESHOLD;

	if (events > 0 && PeekConsoleInput(handle, input, process, &read)) {
		for (ushort i = 0; i < process; i++) {
			switch (input[i].EventType) {
				case KEY_EVENT:
					// ToDo: Key event handler
					break;
				case MOUSE_EVENT:
					// ToDo: Mouse event handler
					break;
				case FOCUS_EVENT:
					// ToDo: Inspect, doesn't work properly at the moment
					focus = input[i].Event.FocusEvent.bSetFocus;
					break;
			}
		}
		if (read < events) {
			auto ss = stringstream();
			ss << "INPUT Discarding input events (" << events - read << ")";
			Logger::instance()->log(ss.str(), Logger::MessagePrefix::MsgPrfxWarning);
		}
		FlushConsoleInputBuffer(handle);
	}
}
