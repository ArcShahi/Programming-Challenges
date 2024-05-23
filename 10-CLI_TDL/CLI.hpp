#ifndef CLI_HPP
#define CLI_HPP


#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include "Terlor.hpp"

namespace tdl
{

	void mainMenu();
	
	void addTask();
	void removeTask();
	void viewList();
	/*void tabSpace();
	void newLine();*/

	extern std::vector < std::string> lists;
	 
}


#endif
