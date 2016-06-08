#pragma once
#include "Camera.h"
#include "GameTime.h"
#include "Types.h"
#include <string>
#include <windows.h>

using namespace std;

namespace Engine
{
    class Console {
    public:
        Console();
        ~Console();

        void initialize();
        void print() const;
        void setFullscreen(const bool& isFullscreen);
        void setBufferSizePx(const ushort& x, const ushort& y);
        void setWindowTitle(const string& title);

        uint getBufferWidth() const;
        uint getBufferHeight() const;
        uint getBufferSize() const;

        Camera* getCamera() const;

        string getTitle() const;

    private:
        const HANDLE hStdHandle = GetStdHandle(STD_OUTPUT_HANDLE);

        CHAR_INFO* buffer = nullptr;
        uint bufferSize = 0;

        Rectangle rectangle;
        Camera* camera = nullptr;

        string windowTitle = "BackSlash Engine - Default Game";
        uint charBufferSize = 0;

        ushort fontSizeX = 0, fontSizeY = 0;

        bool isFullscreen = false;
        bool isFontSizeSet = false;

        void allocateBuffer();
        void updateFontSize();
        void hideCursor() const;
        
    };
}
