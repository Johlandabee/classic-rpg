#include "Utils.h"

void Utils::checkStatus(int status, string errorMessage, bool nuke) {
	if (status == 0) {
		status = GetLastError();
		Logger::instance()->log(errorMessage, Logger::MsgPrfxError, _status);

		if (nuke) {
			exit(_status);
		}
	}
}
