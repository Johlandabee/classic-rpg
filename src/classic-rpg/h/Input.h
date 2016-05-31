#pragma once
#include "Dictionary.h"
#include "Keys.h"
#include "Actions.h"
#include "Config.h"
#include <chrono>

using namespace chrono;

class Input {
public:
	Input();
	~Input();

	bool isAction(Actions action);
	void bind(Actions action, Keys key, unsigned const int timeout = 0);
	void unbind(Actions action);
	void loadBindings(const Config& config);

private:
	// Todo: Extract class
	class Binding {
		Keys key;
		system_clock::time_point lastCall;
		unsigned int timeout;

	public:
		explicit Binding(Keys key, unsigned const int timeout) {
			this->key = key;
			this->timeout = timeout;
		}
		~Binding() {
		}

		Keys getKey() const {
			return key;
		}

		bool ready() {
			if (timeout == 0 || duration_cast<milliseconds>(
				duration<double>(system_clock::now() - lastCall)).count() >= timeout) {
				lastCall = system_clock::now();
				return true;
			}

			return false;
		}
	};

	Dictionary<Actions, Binding*> bindings;
};
