#pragma once
#include "Dictionary.h"
#include "Keys.h"
#include "Actions.h"

class Input {
public:
	Input();
	~Input();

	bool isAction(Actions action);

	void bind(Actions action, Keys key);
	void unbind(Actions action);

private:
	common::Dictionary<Actions, Keys> bindings_;
};
