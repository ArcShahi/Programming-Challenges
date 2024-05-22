#ifndef COLORS_HPP
#define COLORS_HPP


#include <windows.h>


//x86 Windows
#ifdef _WIN32

namespace x86
{

	enum ConsoleColor : WORD
	{
		// Text Colors
		BLACK = 0,

		GREEN = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
		CYAN = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
		RED = FOREGROUND_INTENSITY | FOREGROUND_RED,



	};

	static void setConsoleColor(WORD color) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	}
}

#endif

// x64 Windows
#ifdef _WIN64

namespace x64
{
	enum ConsoleColor : WORD
	{
		// Text Colors
		BLACK = 0,

		GREEN = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
		CYAN = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
		RED = FOREGROUND_INTENSITY | FOREGROUND_RED,



	};

	static void setConsoleColor(WORD color) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	}

}

#endif // _WIN64

// Only for Linux

#ifdef __linux__

namespace Linux
{

	constexpr char GREEN[] = "\033[92m";
	constexpr char CYAN[] = "\033[96m";
	constexpr char RED[] = "\033[91m";

	constexpr char BLACK[] = "\033[30m";

	static void setTerminalColor(const char* color) {
		std::cout << color;
	}

}


#endif // __linux__


constexpr char NoClr[] = "\033[0m";





#endif // COLORS_HPP
