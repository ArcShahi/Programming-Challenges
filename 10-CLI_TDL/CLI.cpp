#include "CLI.hpp"

namespace tdl
{
	std::vector<std::string>lists{};



	void mainMenu()
	{

		arc::setTextColor(Color::BG_CYAN);
		std::cout << "=====================================\n" <<
			"*************************************\n" <<
			"                                     \n" <<
			"               CLI-TDL               \n" <<
			"                                     \n" <<
			"*************************************\n" <<
			"==========================ArcShahi===\n\n\n";
		arc::resetColor();
		std::cout << " Press Enter Key to Continue...\n";
		std::cin.get();
		arc::clearConsole();


		// Take Input

		short   opSel{};
		bool optionLoop{ true };

		while (optionLoop)
		{
			arc::setTextColor(Color::BG_WHITE);
			std::cout << "Type an Option \n";
			arc::resetColor();
			arc::setTextColor(Color::GRAY);
			std::cout << "___________________________________\n\n\n\n";

			arc::setTextColor(Color::GREEN);
			std::cout << "1. Add Tasks\n";

			arc::setTextColor(Color::CYAN);
			std::cout << "2. View All Tasks\n";

			arc::setTextColor(Color::RED);
			std::cout << "3. Delete Tasks\n";

			arc::setTextColor(Color::YELLOW);
			std::cout << "4. Exit\n\n";

			arc::setTextColor(Color::GRAY);
			std::cout<<"___________________________________\n\n\n\n";


			std::cin >> opSel;
			std::cin.ignore(100, '\n');
			arc::resetColor();
			arc::clearConsole();

			switch (opSel)
			{
			case 1:
				addTask();
				break;
			case 2:
				viewList();
				break;
			case 3:
				removeTask();
				break;
			case 4:
				std::cout << "Good Bye >_<...\n\n";
				optionLoop = false;
				std::exit(0);
				break;

			default:
				arc::setTextColor(Color::RED);
				std::cout << "INVALID OPTION TYPED x_x\n\n";
				arc::resetColor();
				break;
			}
		}
	}

	void addTask()
	{
		std::string tasks{};
		bool AddTaskLoop{ true };

		arc::setTextColor(Color::WHITE);
		arc::setTextColor(Color::BG_GREEN);
		std::cout << "Enter Tasks -- , [ Type ':q' to Quit !! ]\n";
		arc::resetColor();
		std::cout << "________________________________________\n\n\n\n";
		
		//std::cout << Color::teal;

		while (AddTaskLoop)
		{


			std::getline(std::cin >> std::ws, tasks);
			if (tasks == ":q")
			{
				arc::clearConsole();
				mainMenu();
			}

			tdl::lists.emplace_back(tasks);

		}
		arc::resetColor();
	}

	void removeTask()
	{

		int delNum{};
		bool running{ true };

		while (running)
		{
			arc::setTextColor(Color::BG_RED);
			std::cout << "Type the Task Number to Delete\n";
			std::cout << "______________________________\n\n\n\n";
			arc::resetColor();

			std::cin >> delNum;
			std::cin.ignore(100, '\n');
			arc::clearConsole();

			if (delNum > std::ssize(tdl::lists) || delNum < 1)
			{
				arc::setTextColor(Color::RED);
				std::cout << "Invalid Task Typed\n";
				arc::resetColor();
			}
			else
			{
				tdl::lists.erase(tdl::lists.begin() + delNum - 1);
				std::cout << "TASK DELETED ;)\n";
				arc::resetColor();
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				std::cout << "Press Any key to Continue...\n";
				std::cin.get();
				arc::clearConsole();

				running = false;
			}


		}
	}

	void viewList()
	{

		arc::setTextColor(Color::BG_CYAN);
		std::cout << "=====List View====\n\n\n";
		arc::resetColor();

		for (auto i = 0; i < std::ssize(tdl::lists); i++)
		{
			
			std::cout << '\n'<<i + 1 << "> " << tdl::lists[i] << "\n";
			arc::setTextColor(Color::GRAY);
			std::cout << "___________________________________\n";
			arc::resetColor();
		}
		arc::resetColor();

		std::cout << "\n\n\nPress Enter to Exit Viewing Mode\n\n\n";
		std::cin.get();
		arc::clearConsole();

	}
}





