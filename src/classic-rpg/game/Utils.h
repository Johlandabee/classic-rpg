#include "Logger.h"
#include <windows.h>

namespace Utils
{
    inline void checkStatus(int status, string errorMessage, bool nuke) {
        if (status == 0) {
            status = GetLastError();
            Engine::Logger::instance()->log(errorMessage, Engine::Logger::MsgPrfxError, status);

            if (nuke) {
                exit(status);
            }
        }
    }
}