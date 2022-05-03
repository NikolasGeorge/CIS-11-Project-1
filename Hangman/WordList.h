/*
 * Author: Nikolas George
 * Purpose: Project 1
 */

#pragma once

#include <iostream>
#include <list>
#include <set>
#include <fstream>
#include <string>
#include <time.h>
#include <algorithm>

 //User Libraries

enum class WordDifficulty
{
	Normal,
	Hard
};

class WordList
{
	std::list<std::string> allWords;

public:
	// ....
	void loadWords(WordDifficulty wordDifficulty);

	// ...
	std::string nextWord();
};

