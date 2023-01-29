#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class TextFilter {
public:
	TextFilter() {
		_wordsToCensor.reserve(50);
	}

private:
	std::vector<std::string> _wordsToCensor;

public:
	void Filter(std::string& textToFilter) {
		std::string stringCopy;
		stringCopy.append(textToFilter);

		for (int i = 0; i < _wordsToCensor.size(); i++)
		{
			std::transform(stringCopy.begin(), stringCopy.end(), stringCopy.begin(), ::tolower);
			//std::cout << stringCopy << std::endl;

			std::string replacement;
			for (int j = 0; j < _wordsToCensor.at(i).length(); j++)
				replacement.push_back('*');

			size_t position = 0;
			while (position != std::string::npos) {
				position = stringCopy.find(_wordsToCensor.at(i), position);
				//std::cout << position << std::endl;

				if (position != -1) {
					textToFilter.replace(position, replacement.length(), replacement);
					position++;
				}
			}
		}
	}

	std::vector<std::string> GetCensoredWords() {
		return _wordsToCensor;
	}

	/*TODO - CHECK IF THE CENSORED WORD ALREADY EXISTS IN THE VECTOR!!*/

	void AddCensoredWords(std::string censoredWord) {
		_wordsToCensor.push_back(censoredWord);
		std::cout << "Add this: " << censoredWord << std::endl;
		std::cout << "Number of censored words: " << _wordsToCensor.size() << std::endl;
	}

	/*TODO - FINALIZE THE REMOVING OF CENSORED WORDS!!*/

	void RemoveCensoredWords(std::string censoredWord) {
		std::vector<std::string>::iterator it = std::find(_wordsToCensor.begin(), _wordsToCensor.end(), censoredWord);
		_wordsToCensor.erase(it);
	}
};

int main() {

	bool isRunning = true;

	std::cout << "*******************************" << std::endl;
	std::cout << "********* Text Filter *********" << std::endl;
	std::cout << "*******************************" << std::endl;
	std::cout << std::endl;

	TextFilter filter;
	std::string border;
	std::vector<std::string> censoredWords;
	std::string enteredText;
	std::string input;

	while (isRunning) {
		std::cout << "Type in the number of the desired operation:" << std::endl;
		std::cout << "1) Enter a text to filter" << std::endl;
		std::cout << "2) Check censored words" << std::endl;
		std::cout << "3) Add censored words" << std::endl;
		/*TODO - ADD THE OPTION OF REMOVING OF CENSORED WORDS!!*/
		std::cout << "Type in 0 to exit the application" << std::endl;
		std::cout << std::endl;

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
				std::cout << "There are currently no censored words." << std::endl;
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

		default:
			std::cout << "Invalid input! Enter again!" << std::endl;
			break;
		}

		std::cout << std::endl;
	}

	return 0;
}