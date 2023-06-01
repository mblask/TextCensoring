#include "textCensoringApp.h"

void RunTextCensoringApp() {

	bool isRunning = true;

	std::cout << "*******************************" << std::endl;
	std::cout << "********* Text Filter *********" << std::endl;
	std::cout << "*******************************" << std::endl;
	std::cout << std::endl;

	TextFilter filter;
	std::string border;
	std::vector<std::string> censoredWords;

	while (isRunning) {
		std::cout << "Type in the number of the desired operation:" << std::endl;
		std::cout << "1) Enter a text to filter" << std::endl;
		std::cout << "2) Check censored words" << std::endl;
		std::cout << "3) Add censored word(s)" << std::endl;
		std::cout << "4) Remove censored word(s)" << std::endl;
		std::cout << "Type in 0 to exit the application" << std::endl;
		std::cout << std::endl;

		std::string enteredText;
		std::string input;
		int choice = 0;

		std::cout << "Your choice:" << std::endl;
		std::cin >> choice;

		std::cout << std::endl;


		switch (choice)
		{
		case 0:
			std::cout << "Exit application" << std::endl;
			isRunning = false;
			break;

		case 1:
			std::cout << "Enter a text to filter" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::getline(std::cin, enteredText);

			std::cout << std::endl;
			for (char x : enteredText)
				border.push_back('-');

			filter.Filter(enteredText);

			std::cout << border << std::endl;
			std::cout << "Filtered text:" << std::endl;
			std::cout << enteredText << std::endl;
			std::cout << border << std::endl;
			break;

		case 2:
			std::cout << "Censored words:" << std::endl;
			censoredWords.clear();
			censoredWords = filter.GetCensoredWords();

			if (censoredWords.size() == 0)
			{
				std::cout << "*There are currently no censored words.*" << std::endl;
				break;
			}

			for (int i = 0; i < censoredWords.size(); i++) {
				std::cout << censoredWords.at(i);
				if (i != censoredWords.size() - 1)
					std::cout << ", ";
			}
			std::cout << std::endl;
			break;

		case 3:
			std::cout << "Add censored words" << std::endl;
			std::cout << "If you are finished with adding, enter 0" << std::endl;

			while (input.compare("0") != 0) {

				if (input == "") {
					std::cin >> input;
					continue;
				}

				filter.AddCensoredWords(input);
				std::cin >> input;
			}

			break;

		case 4:
			std::cout << "Remove censored words" << std::endl;

			if (filter.GetCensoredWords().size() == 0)
			{
				std::cout << "*There are no words to remove!*" << std::endl;
				break;
			}

			std::cout << "If you are finished with removing, enter 0" << std::endl;

			while (input.compare("0") != 0) {

				if (input == "") {
					std::cin >> input;
					continue;
				}

				filter.RemoveCensoredWords(input);
				std::cin >> input;
			}

			break;
		default:
			std::cout << "*Invalid input! Enter again!*" << std::endl;
			break;
		}

		std::cout << std::endl;
	}
}