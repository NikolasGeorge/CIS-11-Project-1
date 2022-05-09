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

// This enum allows us to see the current game state of the game of hangman 
// and run code based on gamestate

enum GameState 
{ 
	Running, 
	Won, 
	Lost 
};

// This enum allows the code to choose a difficulty for the game
enum class GameDifficulty 
{ 
	Easy, 
	Normal, 
	Hard 
};

// This code uses another itr to look at the failed tries of the player 
// and adhjust the game board accordingly

int calcFailedTries(string word, std::set<char> guessed)
{
	// Logic for the player answering incorrectly
	int failedTries = 0;
	for (auto itr = guessed.begin(); itr != guessed.end(); itr++)
	{
		if (word.find(*itr) == string::npos)
			failedTries++;
	}
	return failedTries;
}

// This code is the running state of the game 
// and will break upon wining or losing for the player

bool playRound(string wordToGuess, int score)
{
	// should return if player won
	set<char> playerGuesses;
	int failedTries = 0;
	GameState state = GameState::Running;
	do
	{
		// This should change the game mode to win if the word has been guessed
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

		// This code will load lost if the failed tries are 9 or higher
		failedTries = calcFailedTries(wordToGuess, playerGuesses);

		if (failedTries >= 9)
		{
			state = GameState::Lost;
		}

	} while (state == GameState::Running);

	if (state == GameState::Won)
	{
		// Logic for the player has won and reset
		system("cls");
		// Logic for adding the score before the player goes into the next game
		printMessage("Current Score: " + to_string(score + 1));
		// Logic for tracking failed tries
		drawHangman(failedTries);
		// Display message YOU WON! on win
		printMessage("YOU WON!");
		printMessage("The word was " + wordToGuess);
	}

	else 
	{
		// Logic for player losing
		system("cls");
		// This uses the BELL SOUND from Windows 10 to alert the player they have lost
		cout << '\x07';
		// Logic for keeping the score up to date
		printMessage("Current Score: " + to_string(score));
		// Keep track of failed tries
		drawHangman(failedTries);
		// User failed display GAME OVER
		printMessage("GAME OVER");
		// Show the current word to the Player
		printMessage("The word was " + wordToGuess);

	}

	// return if player won
	system("pause");
	return state == GameState::Won;
}

// The logic of the game running itself with Hangman 
// as the current menu option selected

int playGame()
{
	// We set the word difficulty to what the user has chosen

	WordDifficulty wordDifficulty;
	bool difficultyPicked = false;
	do
	{
		// logic for clearing the screen and give the user the options
		system("cls");
		printMessage("Pick word difficulty");
		printMessage("Choose (N) Normal or (H) Hard");

		// Use of a toupper to make the choice match the code
		char G;
		cout << ">"; cin >> G;
		G = std::toupper(G);

		// Logic for choosing Normal
		if (G == 'N')
		{
			wordDifficulty = WordDifficulty::Normal;
			difficultyPicked = true;
		}
		// Logic for choosing Hard
		else if (G == 'H')
		{
			wordDifficulty = WordDifficulty::Hard;
			difficultyPicked = true;
		}

	}

	// When the difficulty has been picked we run further logic
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
	// Logic for tracking game time
	srand(time(0)); 
	Scoreboard* scoreboard = new Scoreboard();

	while (true)
	{
		// Menu choice option
		char choice;

		// Main menu is fully displayed and ready to take user input
		system("cls");
		printMessage("Main Menu");
		printMessage("P to play Hangman");
		printMessage("L to see leaderboard");
		printMessage("Q to Quit");
		printMessage("Quit the game to save score");
		
		//toupper to take user input and match with code
		cout << ">"; cin >> choice;
		choice = toupper(choice);

		// P will play hangman
		if (choice == 'P') {
			int score = playGame();
			scoreboard->recordNewScore(score);
		}

		// L will show the leader board from the users text file
		else if (choice == 'L')
		{
			scoreboard->printScores();
			system("pause");
		}

		// Q will quit the game while saving
		else if (choice == 'Q')
		{
			system("cls");
			printMessage("Game has been saved");
			printMessage("Thank you for playing");
			return 0;
		}

		// any other input will not be recognized and load back to the main menu
		else
		{
			cout << "Input not recognized. Please try again." << endl;
		}
	}

	delete scoreboard;

	return 0;
}