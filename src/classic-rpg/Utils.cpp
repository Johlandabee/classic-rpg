#include "lib/Utils.h"
#include "lib/Logger.h"
#include <windows.h>


void Utils::checkStatus(int status, string errorMessage, bool nuke) {
	if (status == 0) {
		status = GetLastError();
		Logger::instance()->log(errorMessage, Logger::MsgPrfxError, status);

		if (nuke) {
			exit(status);
		}
	}
}