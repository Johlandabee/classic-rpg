﻿enum Keys {
	GAME_A = 0x41, //A key
	GAME_ACCEPT = 0x1E, //IME accept
	GAME_ADD = 0x6B, //Add key
	GAME_APPS = 0x5D, //Applications key (Natural keyboard)
	GAME_ATTN = 0xF6, //Attn key
	GAME_B = 0x42, //B key
	GAME_BACK = 0x08, //BACKSPACE key
	GAME_BROWSER_BACK = 0xA6, //Browser Back key
	GAME_BROWSER_FAVORITES = 0xAB, //Browser Favorites key
	GAME_BROWSER_FORWARD = 0xA7, //Browser Forward key
	GAME_BROWSER_HOME = 0xAC, //Browser Start and Home key
	GAME_BROWSER_REFRESH = 0xA8, //Browser Refresh key
	GAME_BROWSER_SEARCH = 0xAA, //Browser Search key
	GAME_BROWSER_STOP = 0xA9, //Browser Stop key
	GAME_C = 0x43, //C key
	GAME_CANCEL = 0x03, //Control-break processing
	GAME_CAPITAL = 0x14, //CAPS LOCK key
	GAME_CLEAR = 0x0C, //CLEAR key
	GAME_CONTROL = 0x11, //CTRL key
	GAME_CONVERT = 0x1C, //IME convert
	GAME_CRSEL = 0xF7, //CrSel key
	GAME_D = 0x44, //D key
	GAME_DECIMAL = 0x6E, //Decimal key
	GAME_DELETE = 0x2E, //DEL key
	GAME_DIVIDE = 0x6F, //Divide key
	GAME_DOWN = 0x28, //DOWN ARROW key
	GAME_E = 0x45, //E key
	GAME_END = 0x23, //END key
	GAME_EREOF = 0xF9, //Erase EOF key
	GAME_ESCAPE = 0x1B, //ESC key
	GAME_EXECUTE = 0x2B, //EXECUTE key
	GAME_EXSEL = 0xF8, //ExSel key
	GAME_F = 0x46, //F key
	GAME_F1 = 0x70, //F1 key
	GAME_F10 = 0x79, //F10 key
	GAME_F11 = 0x7A, //F11 key
	GAME_F12 = 0x7B, //F12 key
	GAME_F13 = 0x7C, //F13 key
	GAME_F14 = 0x7D, //F14 key
	GAME_F15 = 0x7E, //F15 key
	GAME_F16 = 0x7F, //F16 key
	GAME_F17 = 0x80, //F17 key
	GAME_F18 = 0x81, //F18 key
	GAME_F19 = 0x82, //F19 key
	GAME_F2 = 0x71, //F2 key
	GAME_F20 = 0x83, //F20 key
	GAME_F21 = 0x84, //F21 key
	GAME_F22 = 0x85, //F22 key
	GAME_F23 = 0x86, //F23 key
	GAME_F24 = 0x87, //F24 key
	GAME_F3 = 0x72, //F3 key
	GAME_F4 = 0x73, //F4 key
	GAME_F5 = 0x74, //F5 key
	GAME_F6 = 0x75, //F6 key
	GAME_F7 = 0x76, //F7 key
	GAME_F8 = 0x77, //F8 key
	GAME_F9 = 0x78, //F9 key
	GAME_FINAL = 0x18, //IME final mode
	GAME_G = 0x47, //G key
	GAME_H = 0x48, //H key
	GAME_HANGUEL = 0x15, //IME Hanguel mode (maintained for compatibility; use VK_HANGUL)
	GAME_HANGUL = 0x15, //IME Hangul mode
	GAME_HANJA = 0x19, //IME Hanja mode
	GAME_HELP = 0x2F, //HELP key
	GAME_HOME = 0x24, //HOME key
	GAME_I = 0x49, //I key
	GAME_INSERT = 0x2D, //INS key
	GAME_J = 0x4A, //J key
	GAME_JUNJA = 0x17, //IME Junja mode
	GAME_K = 0x4B, //K key
	GAME_KANA = 0x15, //IME Kana mode
	GAME_KANJI = 0x19, //IME Kanji mode
	GAME_L = 0x4C, //L key
	GAME_LAUNCH_APP1 = 0xB6, //Start Application 1 key
	GAME_LAUNCH_APP2 = 0xB7, //Start Application 2 key- = 0xB8-B9 Reserved
	GAME_LAUNCH_MAIL = 0xB4, //Start Mail key
	GAME_LAUNCH_MEDIA_SELECT = 0xB5, //Select Media key
	GAME_LBUTTON = 0x01, //Left mouse button
	GAME_LCONTROL = 0xA2, //Left CONTROL key
	GAME_LEFT = 0x25, //LEFT ARROW key
	GAME_LMENU = 0xA4, //Left MENU key
	GAME_LSHIFT = 0xA0, //Left SHIFT key
	GAME_LWIN = 0x5B, //Left Windows key (Natural keyboard)
	GAME_M = 0x4D, //M key
	GAME_MBUTTON = 0x04, //Middle mouse button (three-button mouse)
	GAME_MEDIA_NEXT_TRACK = 0xB0, //Next Track key
	GAME_MEDIA_PLAY_PAUSE = 0xB3, //Play/Pause Media key
	GAME_MEDIA_PREV_TRACK = 0xB1, //Previous Track key
	GAME_MEDIA_STOP = 0xB2, //Stop Media key
	GAME_MENU = 0x12, //ALT key
	GAME_MODECHANGE = 0x1F, //IME mode change request
	GAME_MULTIPLY = 0x6A, //Multiply key
	GAME_N = 0x4E, //N key
	GAME_NEXT = 0x22, //PAGE DOWN key
	GAME_NONAME = 0xFC, //Reserved
	GAME_NONCONVERT = 0x1D, //IME nonconvert
	GAME_NUMBER0 = 0x30, //0 key
	GAME_NUMBER1 = 0x31, //1 key
	GAME_NUMBER2 = 0x32, //2 key
	GAME_NUMBER3 = 0x33, //3 key
	GAME_NUMBER4 = 0x34, //4 key
	GAME_NUMBER5 = 0x35, //5 key
	GAME_NUMBER6 = 0x36, //6 key
	GAME_NUMBER7 = 0x37, //7 key
	GAME_NUMBER8 = 0x38, //8 key
	GAME_NUMBER9 = 0x39, //9 key
	GAME_NUMLOCK = 0x90, //NUM LOCK key
	GAME_NUMPAD0 = 0x60, //Numeric keypad 0 key
	GAME_NUMPAD1 = 0x61, //Numeric keypad 1 key
	GAME_NUMPAD2 = 0x62, //Numeric keypad 2 key
	GAME_NUMPAD3 = 0x63, //Numeric keypad 3 key
	GAME_NUMPAD4 = 0x64, //Numeric keypad 4 key
	GAME_NUMPAD5 = 0x65, //Numeric keypad 5 key
	GAME_NUMPAD6 = 0x66, //Numeric keypad 6 key
	GAME_NUMPAD7 = 0x67, //Numeric keypad 7 key
	GAME_NUMPAD8 = 0x68, //Numeric keypad 8 key
	GAME_NUMPAD9 = 0x69, //Numeric keypad 9 key
	GAME_O = 0x4F, //O key
	GAME_OEM_1 = 0xBA, //Used for miscellaneous characters; it can vary by keyboard.For the US standard keyboard, the ';:' key
	GAME_OEM_102 = 0xE2, //Either the angle bracket key or the backslash key on the RT 102-key keyboard
	GAME_OEM_2 = 0xBF, //Used for miscellaneous characters; it can vary by keyboard. For the US standard keyboard, the '/?' key
	GAME_OEM_3 = 0xC0, //Used for miscellaneous characters; it can vary by keyboard. For the US standard keyboard, the '`~' key
	GAME_OEM_4 = 0xDB, //Used for miscellaneous characters; it can vary by keyboard. For the US standard keyboard, the '[{' key
	GAME_OEM_5 = 0xDC, //Used for miscellaneous characters; it can vary by keyboard. For the US standard keyboard, the '\|' key
	GAME_OEM_6 = 0xDD, //Used for miscellaneous characters; it can vary by keyboard. For the US standard keyboard, the ']}' key
	GAME_OEM_7 = 0xDE, //Used for miscellaneous characters; it can vary by keyboard. For the US standard keyboard, the 'single-quote/double-quote' key
	GAME_OEM_8 = 0xDF, //Used for miscellaneous characters; it can vary by keyboard.
	GAME_OEM_CLEAR = 0xFE, //Clear key
	GAME_OEM_COMMA = 0xBC, //For any country/region, the ',' key
	GAME_OEM_MINUS = 0xBD, //For any country/region, the '-' key
	GAME_OEM_PERIOD = 0xBE, //For any country/region, the '.' key
	GAME_OEM_PLUS = 0xBB, //For any country/region, the '+' key
	GAME_OEM_SPECIFIC_0 = 0x92, //OEM specific
	GAME_OEM_SPECIFIC_1 = 0x93, //OEM specific
	GAME_OEM_SPECIFIC_2 = 0x94, //OEM specific
	GAME_OEM_SPECIFIC_3 = 0x95, //OEM specific
	GAME_OEM_SPECIFIC_4 = 0x96, //OEM specific
	GAME_OEM_SPECIFIC_5 = 0xE1, //OEM specific
	GAME_OEM_SPECIFIC_6 = 0xE3, //OEM specific
	GAME_OEM_SPECIFIC_7 = 0xE4, //OEM specific
	GAME_OEM_SPECIFIC_8 = 0xE6, //OEM specific
	GAME_OEM_SPECIFIC_9 = 0xE8, //OEM specific
	GAME_P = 0x50, //P key
	GAME_PA1 = 0xFD, //PA1 key
	GAME_PACKET = 0xE7, /*
						* Used to pass Unicode characters as if they were keystrokes.
						* The VK_PACKET key is the low word of a 32-bit Virtual Key value
						* used for non-keyboard input methods.
						* For more information, see Remark in KEYBDINPUT, SendInput, WM_KEYDOWN, and WM_KEYUP
						*/
	GAME_PAUSE = 0x13, //PAUSE key
	GAME_PLAY = 0xFA, //Play key
	GAME_PRINT = 0x2A, //PRINT key
	GAME_PRIOR = 0x21, //PAGE UP key
	GAME_PROCESSKEY = 0xE5, //IME PROCESS key
	GAME_Q = 0x51, //Q key
	GAME_R = 0x52, //R key
	GAME_RBUTTON = 0x02, //Right mouse button
	GAME_RCONTROL = 0xA3, //Right CONTROL key
	GAME_RETURN = 0x0D, //ENTER key
	GAME_RIGHT = 0x27, //RIGHT ARROW key
	GAME_RMENU = 0xA5, //Right MENU key
	GAME_RSHIFT = 0xA1, //Right SHIFT key
	GAME_RWIN = 0x5C, //Right Windows key (Natural keyboard)
	GAME_S = 0x53, //S key
	GAME_SCROLL = 0x91, //SCROLL LOCK key
	GAME_SELECT = 0x29, //SELECT key
	GAME_SEPARATOR = 0x6C, //Separator key
	GAME_SHIFT = 0x10, //SHIFT key
	GAME_SLEEP = 0x5F, //Computer Sleep key
	GAME_SNAPSHOT = 0x2C, //PRINT SCREEN key
	GAME_SPACE = 0x20, //SPACEBAR
	GAME_SUBTRACT = 0x6D, //Subtract key
	GAME_T = 0x54, //T key
	GAME_TAB = 0x09, //TAB key
	GAME_U = 0x55, //U key
	GAME_UP = 0x26, //UP ARROW key
	GAME_V = 0x56, //V key
	GAME_VOLUME_DOWN = 0xAE, //Volume Down key
	GAME_VOLUME_MUTE = 0xAD, //Volume Mute key
	GAME_VOLUME_UP = 0xAF, //Volume Up key
	GAME_W = 0x57, //W key
	GAME_X = 0x58, //X key
	GAME_XBUTTON1 = 0x05, //X1 mouse button
	GAME_XBUTTON2 = 0x06, //X2 mouse button
	GAME_Y = 0x59, //Y key
	GAME_Z = 0x5A, //Z key
	GAME_ZOOM = 0xFB, //Zoom key
	NOT_ASSINGED
};