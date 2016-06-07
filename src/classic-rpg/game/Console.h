#pragma once
#include "Camera.h"
#include "GameTime.h"
#include <string>
#include <windows.h>

using namespace std;

namespace Engine
{
    class Console {
    public:
        Console();
        ~Console();

        void setFullscreen(const bool& isFullscreen);
        void setWindowSize(const unsigned short& x, const unsigned short& y);
        void setWindowTitle(const string& title);

        string getTitle() const;

    private:
        bool isFullscreen;

        Camera camera;
        CHAR_INFO charInfos;
        CONSOLE_SCREEN_BUFFER_INFOEX screenBufferInfo;

        const HANDLE stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);

        COORD screenBufferSize_, screenBufferPos;

        int charBufferSize;

        PSMALL_RECT consoleRect;
        SMALL_RECT windowRect;
        string windowTitle_;

        void toggleFullscreeen();
        void updateBufferInfo();
        void updateBufferSize() const;
    };
}
