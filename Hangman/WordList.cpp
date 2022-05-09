/*
 * Author: Nikolas George
 * Purpose: Project 1
 */

 //User Libraries

#include <iostream>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <fstream>
#include <string>
#include <algorithm>
#include "WordList.h"

using namespace std;

// This code handles the text files them self
void WordList::loadWords(WordDifficulty wordDifficulty)
{
	lastWordDifficulty = wordDifficulty;

	// This code choses which text filed based on the difficulty selected
	map<WordDifficulty, string> files;
	// File for normalWords.txt
	files[WordDifficulty::Normal] = "normalWords.txt";
	// File for hardWords.txt
	files[WordDifficulty::Hard] = "hardWords.txt";

	string filename = files[wordDifficulty];

	ifstream reader(filename);
	if (!reader.is_open())
	{
		return;
	}

	std::list<std::string> wordsFromFile;
	string word;
	while (std::getline(reader, word))
	{
		wordsFromFile.push_back(word);
	}
	reader.close();

	// This code picks a certain amount of words from the text file and pushes into the stack
	for (int i = 0; i < 2; i++)
	{
		// This code chooses the random word from the word list text file
		int randomLine = rand() % wordsFromFile.size();
		auto itr = wordsFromFile.begin();
		for (int j = 0; j < randomLine; j++)
		{
			itr++;
		}
		string word = *itr;

		// This code uses to-upper to auto capitalize the word being used
		std::transform(word.begin(), word.end(), word.begin(),
			[](unsigned char c) { return std::toupper(c); }
		);

		allWords.push(word);
	}

}

// This code handles the logic for choosing a random word with a itr
string WordList::nextWord()
{
	// This code loads more words if we have used all the words in the stack
	if (allWords.empty())
	{
		loadWords(lastWordDifficulty);
	}

	string word = allWords.top();
	allWords.pop();
	return word;
}
