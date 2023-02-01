#include "textFilter.h"

TextFilter::TextFilter(int reserveMemory) {
	_listOfWordsToCensor.reserve(reserveMemory);
}

TextFilter::TextFilter() {
	_listOfWordsToCensor.reserve(100);
}

void TextFilter::toLowerCase(std::string& string) {
	std::transform(string.begin(), string.end(), string.begin(), ::tolower);
}

bool TextFilter::containsCensoredWord(std::string censoredWord) {

	toLowerCase(censoredWord);

	for (int i = 0; i < _listOfWordsToCensor.size(); i++)
	{
		if (_listOfWordsToCensor.at(i).compare(censoredWord) == 0)
			return true;
	}

	return false;
}

void TextFilter::Filter(std::string& textToFilter) {
	std::string stringCopy;
	stringCopy.append(textToFilter);

	for (int i = 0; i < _listOfWordsToCensor.size(); i++)
	{
		toLowerCase(stringCopy);

		std::string replacement;
		for (int j = 0; j < _listOfWordsToCensor.at(i).length(); j++)
			replacement.push_back('*');

		size_t position = 0;
		while (position != std::string::npos) {
			position = stringCopy.find(_listOfWordsToCensor.at(i), position);

			if (position != -1) {
				textToFilter.replace(position, replacement.length(), replacement);
				position++;
			}
		}
	}
}

std::vector<std::string> TextFilter::GetCensoredWords() {
	return _listOfWordsToCensor;
}

void TextFilter::AddCensoredWords(std::string censoredWord) {

	if (containsCensoredWord(censoredWord)) {
		std::cout << "*Word already censored!*" << std::endl;
		return;
	}

	_listOfWordsToCensor.push_back(censoredWord);
	std::cout << "Add this: " << censoredWord << std::endl;
	std::cout << "Number of censored words: " << _listOfWordsToCensor.size() << std::endl;
}

void TextFilter::RemoveCensoredWords(std::string censoredWord) {

	toLowerCase(censoredWord);

	if (!containsCensoredWord(censoredWord)) {
		std::cout << "*There is no such word!*" << std::endl;
		return;
	}

	std::vector<std::string>::iterator it = std::find(_listOfWordsToCensor.begin(), _listOfWordsToCensor.end(), censoredWord);
	_listOfWordsToCensor.erase(it);
}