/*
 * Author: Nikolas George
 * Purpose: Project 1
 */
//User Libraries
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <time.h>
#include <algorithm>
#include "Scoreboard.h"
#include "Printing.h"

using namespace std;

enum GameState { Running, Won, Lost };

string loadRandomWord(string path)// Logic for choosing a random word
{
	int lineCount = 0;
	string word;
	vector<string> v;
	ifstream reader(path);
	if (reader.is_open())
	{
		while (std::getline(reader, word))
		{
			v.push_back(word);
		}
		int randomLine = rand() % v.size();
		// Words from 1 - 200 List
		word = v.at(randomLine);

		reader.close();
		std::transform(word.begin(), word.end(), word.begin(),
			[](unsigned char c) { return std::toupper(c); }
		);
		return word;
	}
}
int calcFailedTries(string word, string guessed) // Logic for the player answering incorrectly
{
	int failedTries = 0;
	for (int i = 0; i < guessed.length(); i++)
	{
		if (word.find(guessed[i]) == string::npos) 
			failedTries++;
	}
	return failedTries;
}


void playGame() // should return score
{
	srand(time(0)); // Logic for tracking game time
	string playerGuesses;
	string wordToGuess;
	wordToGuess = loadRandomWord("hardWords.txt"); // Logic for loading the random word from a set list
	int failedTries = 0;
	GameState state = GameState::Running;
	do
	{
		bool won = printGame(failedTries, wordToGuess, playerGuesses);
		if (won)
		{
			state = GameState::Won;
			break;
		}

		char W;
		cout << ">"; cin >> W;
		W = std::toupper(W);
		if (playerGuesses.find(W) == string::npos)
			playerGuesses += W;

		failedTries = calcFailedTries(wordToGuess, playerGuesses);

		if (failedTries >= 9)
		{
			state = GameState::Lost;
		}

	} while (state == GameState::Running);

	if (state == GameState::Won) // Logic for the player has won and reset
	{
		system("cls");
		printMessage("HANG MAN");
		drawHangman(failedTries);
		printMessage("YOU WON!");
		printMessage("The word was " + wordToGuess);
	}

	else // Logic for player losing
	{
		system("cls");
		printMessage("HANG MAN");
		drawHangman(failedTries);
		printMessage("GAME OVER");
		printMessage("The word was " + wordToGuess);
		cout << '\x07' << endl;
	}

	system("pause");
}

int main()
{
	Scoreboard scoreboard;

	while (true)
	{
		playGame(); // TODO return score
		// scoreboard.maybeRecordNewScore(score)
	}

	return 0;
}