#pragma once
#include <string>
#include "Logger.h"

class Utils{
public:
	static void Utils::checkStatus(string errorMessage, int status, bool nuke = true);
}