#ifndef  TERLOR_HPP
#define  TERLOR_HPP

#include <windows.h>





// windows color
#ifdef _WIN64


enum  Color : WORD
{
	// Text Colors
	BLACK = 0,
	DEFAULT= FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
	DARKBLUE = FOREGROUND_BLUE,
	DARKGREEN = FOREGROUND_GREEN,
	DARKCYAN = FOREGROUND_GREEN | FOREGROUND_BLUE,
	DARKRED = FOREGROUND_RED,
	DARKMAGENTA = FOREGROUND_RED | FOREGROUND_BLUE,
	DARKYELLOW = FOREGROUND_RED | FOREGROUND_GREEN,
	DARKGRAY = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
	GRAY = FOREGROUND_INTENSITY,
	BLUE = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
	GREEN = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
	CYAN = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
	RED = FOREGROUND_INTENSITY | FOREGROUND_RED,
	MAGENTA = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
	YELLOW = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
	WHITE = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,

	// Background Colors
	BG_BLACK = 0,
	BG_DARKBLUE = BACKGROUND_BLUE,
	BG_DARKGREEN = BACKGROUND_GREEN,
	BG_DARKCYAN = BACKGROUND_GREEN | BACKGROUND_BLUE,
	BG_DARKRED = BACKGROUND_RED,
	BG_DARKMAGENTA = BACKGROUND_RED | BACKGROUND_BLUE,
	BG_DARKYELLOW = BACKGROUND_RED | BACKGROUND_GREEN,
	BG_DARKGRAY = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
	BG_GRAY = BACKGROUND_INTENSITY,
	BG_BLUE = BACKGROUND_INTENSITY | BACKGROUND_BLUE,
	BG_GREEN = BACKGROUND_INTENSITY | BACKGROUND_GREEN,
	BG_CYAN = BACKGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE,
	BG_RED = BACKGROUND_INTENSITY | BACKGROUND_RED,
	BG_MAGENTA = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE,
	BG_YELLOW = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN,
	BG_WHITE = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
};

#endif // _WIN64

// Linux Color

#ifdef __linux__


constexpr char BLACK[] = "\033[30m";
constexpr char DARKBLUE[] = "\033[34m";
constexpr char DARKGREEN[] = "\033[32m";
constexpr char DARKCYAN[] = "\033[36m";
constexpr char DARKRED[] = "\033[31m";
constexpr char DARKMAGENTA[] = "\033[35m";
constexpr char DARKYELLOW[] = "\033[33m";
constexpr char DARKGRAY[] = "\033[90m";
constexpr char GRAY[] = "\033[37m";
constexpr char BLUE[] = "\033[94m";
constexpr char GREEN[] = "\033[92m";
constexpr char CYAN[] = "\033[96m";
constexpr char RED[] = "\033[91m";
constexpr char MAGENTA[] = "\033[95m";
constexpr char YELLOW[] = "\033[93m";
constexpr char WHITE[] = "\033[97m";

// Background Colors
constexpr char BG_BLACK[] = "\033[40m";
constexpr char BG_DARKBLUE[] = "\033[44m";
constexpr char BG_DARKGREEN[] = "\033[42m";
constexpr char BG_DARKCYAN[] = "\033[46m";
constexpr char BG_DARKRED[] = "\033[41m";
constexpr char BG_DARKMAGENTA[] = "\033[45m";
constexpr char BG_DARKYELLOW[] = "\033[43m";
constexpr char BG_DARKGRAY[] = "\033[100m";
constexpr char BG_GRAY[] = "\033[47m";
constexpr char BG_BLUE[] = "\033[104m";
constexpr char BG_GREEN[] = "\033[102m";
constexpr char BG_CYAN[] = "\033[106m";
constexpr char BG_RED[] = "\033[101m";
constexpr char BG_MAGENTA[] = "\033[105m";
constexpr char BG_YELLOW[] = "\033[103m";
constexpr char BG_WHITE[] = "\033[107m";
#endif // __linux__



namespace arc
{
	#ifdef _WIN64

	// Takes in foreround Color and Backgroind color
	inline void setTextColor(WORD Color) {
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
		

	}



	#endif 


	#ifdef __linux__


	constexpr char NoClr[] = "\033[0m";

	inline  void setConsoleColor(const char* fColor,const char* bColor="\033[49m") {
		std::cout << fColor<<bColor<<
	}


	#endif // __linux__




	inline void resetColor()
	{

		#ifdef _WIN64

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color::DEFAULT);
		#endif // _WIN64

		#ifdef __linux__
		std::cout << "\033[0m";
		#endif // __linux__

		
	}
	inline void clearConsole()
	{
		#ifdef _WIN64
		system("cls");

		#endif // _WIN64
         

		#ifdef __linux__
		std::cout << "\033[2J\033[H";
		#endif // __linux__

		
	}

}



#endif // ! TERLOR_HPP

