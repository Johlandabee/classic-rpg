#pragma once
#include <windows.h>
#include <string>

#include "GameTime.h"

using namespace std;

class Renderer {
public:
	Renderer();
	~Renderer();

	void initialize();
	void setWindowTitle(string title);
	void setWindowSize(int x, int y);

	void draw(GameTime* game_time) const;

	bool isFullscreen() const;

private:
	const HANDLE hOut_ = CreateFile("CONOUT$",
	                                GENERIC_WRITE | GENERIC_READ, NULL, nullptr, OPEN_ALWAYS, NULL, nullptr);

	CONSOLE_SCREEN_BUFFER_INFOEX screenBufferInfo_;
	COORD screenBufferSize_, screenBufferPos_;
	PSMALL_RECT consoleRect_;

	CHAR_INFO charInfos_;

	string windowTitle_;

	void updateBufferInfo();
	void updateBufferSize() const;
	void toggleFullscreeen();

	bool isFullscreen_ = false;
	bool isInitialized_ = false;

	struct RES {
		int X;
		int Y;
	};

	RES resolution_;

	int charBufferSize;
};

