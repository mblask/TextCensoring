#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class TextFilter {
public:
	TextFilter();
	TextFilter(int memoryReserve);

private:
	std::vector<std::string> _listOfWordsToCensor;
	void toLowerCase(std::string& string);
	bool containsCensoredWord(std::string censoredWord);

public:
	void Filter(std::string& textToFilter);
	std::vector<std::string> GetCensoredWords();
	void AddCensoredWords(std::string censoredWord);
	void RemoveCensoredWords(std::string censoredWord);
};