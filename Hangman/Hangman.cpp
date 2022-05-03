/*
 * Author: Nikolas George
 * Purpose: Project 1
 */
//User Libraries
#include <iostream>
#include <list>
#include <set>
#include <fstream>
#include <string>
#include <time.h>
#include <algorithm>
#include "Scoreboard.h"
#include "Printing.h"
#include "WordList.h"

using namespace std;

enum GameState 
{ 
	Running, 
	Won, 
	Lost 
};

enum class GameDifficulty 
{ 
	Easy, 
	Normal, 
	Hard 
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
		printMessage("Current Score: " + to_string(score + 1));
		drawHangman(failedTries);
		printMessage("YOU WON!");
		printMessage("The word was " + wordToGuess);
	}

	else // Logic for player losing
	{

		system("cls");
		cout << '\x07';
		printMessage("Current Score: " + to_string(score));
		drawHangman(failedTries);
		printMessage("GAME OVER");
		printMessage("The word was " + wordToGuess);

	}

	system("pause");
	return state == GameState::Won; // return if player won
}

int playGame()
{
	WordDifficulty wordDifficulty;
	bool difficultyPicked = false;
	do
	{
		system("cls");
		printMessage("Pick word difficulty");
		printMessage("Choose (N) Normal or (H) Hard");


		char G;
		cout << ">"; cin >> G;
		G = std::toupper(G);

		if (G == 'N')
		{
			wordDifficulty = WordDifficulty::Normal;
			difficultyPicked = true;
		}
		else if (G == 'H')
		{
			wordDifficulty = WordDifficulty::Hard;
			difficultyPicked = true;
		}

	}
	while (!difficultyPicked);

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
	srand(time(0)); // Logic for tracking game time
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