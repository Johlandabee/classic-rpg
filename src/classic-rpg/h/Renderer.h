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
	void setWindowSize(short x, short y);

	void draw(GameTime* game_time) const;

	string title() const;

	bool isFullscreen = false;

private:
	const HANDLE handle_ = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFOEX screenBufferInfo_;
	COORD screenBufferSize_, screenBufferPos_;
	PSMALL_RECT consoleRect_;

	CHAR_INFO charInfos_;

	string windowTitle_;

	void updateBufferInfo();
	void updateBufferSize() const;
	void toggleFullscreeen();

	bool isInitialized_ = false;

	SMALL_RECT windowRect_;

	int charBufferSize;
};
