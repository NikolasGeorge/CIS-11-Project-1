/*
 * Author: Nikolas George
 * Purpose: Project 1
 */
//User Libraries
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <fstream>
#include <string>
#include <time.h>
#include <algorithm>
#include "Scoreboard.h"
#include "Printing.h"

using namespace std;

enum GameState 
{ 
	Running, 
	Won, 
	Lost 
};

enum class WordDifficulty 
{ 
	Normal, 
	Hard 
};

enum class GameDifficulty 
{ 
	Easy, 
	Normal, 
	Hard 
};

class WordList
{
	list<string> allWords;

public:
	void loadWords(WordDifficulty wordDifficulty)
	{
		string filename;
		if (wordDifficulty == WordDifficulty::Hard)
		{
			filename = "hardWords.txt";
		}
		else {
			filename = "normalWords.txt";
		}

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

	string nextWord()
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
};

int calcFailedTries(string word, std::set<char> guessed) // Logic for the player answering incorrectly
{
	int failedTries = 0;
	for (auto itr = guessed.begin(); itr != guessed.end(); itr++)
	{
		if (word.find(*itr) == string::npos)
			failedTries++;
	}
	return failedTries;
}


bool playRound(string wordToGuess, int score) // should return if player won
{
	srand(time(0)); // Logic for tracking game time
	set<char> playerGuesses;
	int failedTries = 0;
	GameState state = GameState::Running;
	do
	{
		bool won = printGame(failedTries, wordToGuess, playerGuesses, score);
		if (won)
		{
			state = GameState::Won;
			break;
		}

		char W;
		cout << ">"; cin >> W;
		W = std::toupper(W);
		if (playerGuesses.find(W) == playerGuesses.end())
			playerGuesses.insert(W);

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
	return state == GameState::Won; // return if player won
}

int playGame()
{
	// TODO get difficulty from user
	WordDifficulty wordDifficulty = WordDifficulty::Hard;

	WordList wordList;
	wordList.loadWords(wordDifficulty);
	int score = 0;
	// Logic for loading the random word from a set list
	while (playRound(wordList.nextWord(), score))
	{
		score++;
	}
	return score;
}

int main()
{
	Scoreboard scoreboard;

	while (true)
	{
		
		char choice;
		system("cls");
		printMessage("Main Menu");
		printMessage("P to play Hangman");
		printMessage("L to see leaderboard");
		printMessage("Q to Quit");
		
		cout << ">"; cin >> choice;
		choice = toupper(choice);

		if (choice == 'P') {
			int score = playGame();
			scoreboard.recordNewScore(score);
		}

		else if (choice == 'L')
		{
			scoreboard.printScores();
			system("pause");
		}
		else if (choice == 'Q')
		{
			system("cls");
			return 0;
		}

		else
		{
			cout << "Input not recognized. Please try again." << endl;
		}
	}
	return 0;
}