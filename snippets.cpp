	/*
	_conSize = { i, i };
	_conCoord = {};
	_conRect = new _SMALL_RECT{ 0,0,i,i };;
	_chInfo[i*i];

	for (int j = 0; j < (i*i); j++)
	{
		_chInfo[j].Char.AsciiChar = 219;
		_chInfo[j].Attributes = FOREGROUND_GREEN;
	}
	*/

		// ToDo: All the things

/*	CONSOLE_FONT_INFOEX fontInfo;
	CONSOLE_CURSOR_INFO cursorInfo;
	CONSOLE_SCREEN_BUFFER_INFOEX screenBufferInfo;

	fontInfo.cbSize = sizeof(fontInfo);
	screenBufferInfo.cbSize = sizeof(screenBufferInfo);

	GetConsoleScreenBufferInfoEx(stdHandle, &screenBufferInfo);
	GetCurrentConsoleFontEx(stdHandle, false, &fontInfo);
	GetConsoleCursorInfo(stdHandle, &cursorInfo);

	cursorInfo.bVisible = false;

	windowRect.Bottom = y / fontInfo.dwFontSize.Y;
	windowRect.Left = 0;
	windowRect.Right = x / fontInfo.dwFontSize.X;
	windowRect.Top = 0;

	screenBufferInfo.dwSize.X = windowRect.Right + 1;
	screenBufferInfo.dwSize.Y = windowRect.Bottom + 1;

	SetConsoleScreenBufferInfoEx(stdHandle, &screenBufferInfo);
	SetConsoleCursorInfo(stdHandle, &cursorInfo);

	SetConsoleWindowInfo(stdHandle, true, &windowRect);*/

	//DWORD flags = 0;
	//GetConsoleMode(stdHandle, &flags);

	//flags &= ~ENABLE_MOUSE_INPUT;

	//auto status = SetConsoleMode(stdHandle, flags);

	//auto error = GetLastError();

	//int i = 1;
	/*
	COORD newScreenBufferDimensions;

	HWND windowHandle = GetConsoleWindow();

	LONG lStyle = GetWindowLong(windowHandle, GWL_STYLE);

	lStyle &= ~(WS_CAPTION | WS_THICKFRAME | WS_MINIMIZE | WS_MAXIMIZE | WS_SYSMENU);
	SetWindowLong(windowHandle, GWL_STYLE, lStyle);

	LONG lExStyle = GetWindowLong(windowHandle, GWL_EXSTYLE);
	LONG savelExStyle = lExStyle;
	lExStyle &= ~(WS_EX_DLGMODALFRAME | WS_EX_CLIENTEDGE | WS_EX_STATICEDGE);
	SetWindowLong(windowHandle, GWL_EXSTYLE, lExStyle);

	//SetWindowPos(windowHandle, HWND_TOP, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), SWP_FRAMECHANGED| SWP_SHOWWINDOW);

	*/