/*
 * Author: Nikolas George
 * Purpose: Project 1
 */

#pragma once

//User Libraries

#include <iostream>
#include <stack>
#include <set>
#include <fstream>
#include <string>
#include <time.h>
#include <algorithm>

// This enum allows the code to take input from the user on what word difficulty they want
enum class WordDifficulty
{
	Normal,
	Hard
};

// This class allows the code to use a list for selecting the words from different word text files
class WordList
{
	std::stack<std::string> allWords;
	WordDifficulty lastWordDifficulty;

public:

	// This is the command that selects the word from the list
	void loadWords(WordDifficulty wordDifficulty);

	// This starts the choose the next word once the previous word was already selected
	std::string nextWord();
};
