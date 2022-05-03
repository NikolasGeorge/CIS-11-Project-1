/*
 * Author: Nikolas George
 * Purpose: Project 1
 */
 //User Libraries
#include <iostream>
#include <list>
#include <set>
#include <map>
#include <fstream>
#include <string>
#include <algorithm>
#include "WordList.h"

using namespace std;

void WordList::loadWords(WordDifficulty wordDifficulty)
{
	
	map<WordDifficulty, string> files;
	files[WordDifficulty::Normal] = "normalWords.txt";
	files[WordDifficulty::Hard] = "hardWords.txt";

	string filename = files[wordDifficulty];

	ifstream reader(filename);
	if (reader.is_open())
	{
		string word;
		while (std::getline(reader, word))
		{
			allWords.push_back(word);
		}
		reader.close();
	}
}

string WordList::nextWord()
{
	int randomLine = rand() % allWords.size();
	auto itr = allWords.begin();
	for (int i = 0; i < randomLine; i++)
	{
		itr++;
	}

	string word = *itr;
	std::transform(word.begin(), word.end(), word.begin(),
		[](unsigned char c) { return std::toupper(c); }
	);
	return word;
}
