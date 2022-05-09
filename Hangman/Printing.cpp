/*
 * Author: Nikolas George
 * Purpose: Project 1
 */

//User Libraries

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <time.h>
#include <algorithm>
#include <iterator>
#include "Printing.h"

using namespace std;

// Function for looking at the game logic for score and word
bool printGame(int failedTries, string wordToGuess, set<char> playerGuesses, int score)
{
	system("cls");
	// logic for displaying score
	printMessage("Current Score: " + to_string(score));
	// logic for displaying the hangman from failed tries
	drawHangman(failedTries);
	// logic for show what letters the user hasn't guessed
	printAvailableLetters(playerGuesses);
	// logic for displaying the guess the word message
	printMessage("Guess the word");
	// logic for checking if the players guesses has won
	return printWordAndCheckWin(wordToGuess, playerGuesses);
}

// Logic for building all the messages we use for this code 
// as well as the game board
void printMessage(string message, bool printTop, bool printBottom) 
{
	if (printTop)
	{
		cout << "+---------------------------------+" << endl;
		cout << "|";
	}
	else
	{
		cout << "|";
	}
	bool front = true;
	for (int i = message.length(); i < 33; i++)
	{
		if (front)
		{
			message = " " + message;
		}
		else
		{
			message = message + " ";
		}
		front = !front;
	}
	cout << message.c_str();

	if (printBottom)
	{
		cout << "|" << endl;
		cout << "+---------------------------------+" << endl;
	}
	else
	{
		cout << "|" << endl;
	}
}
// Logic for drawing the Hangman body
void drawHangman(int guessCount)
{
	// Logic for drawing the Hangman body 1
	// and displaying blanks with false, false
	if (guessCount >= 1)
	{
		printMessage("|", false, false);
	}

	else
	{
		printMessage("", false, false);
	}
	// Logic for drawing the Hangman body 2
	// and displaying blanks with false, false
	if (guessCount >= 2)
	{
		printMessage("|", false, false);
	}
	else
	{
		printMessage("", false, false);
	}
	// Logic for drawing the Hangman body 3
	// and displaying blanks with false, false
	if (guessCount >= 3)
	{
		printMessage("O", false, false);
	}
	else
	{
		printMessage("", false, false);
	}
	// Logic for drawing the Hangman body 4
	// and displaying blanks with false, false
	if (guessCount == 4)
	{
		printMessage("/  ", false, false);
	}
	// Logic for drawing the Hangman body 5
	// and displaying blanks with false, false
	if (guessCount == 5)
	{
		printMessage("/| ", false, false);
	}
	// Logic for drawing the Hangman body 6
	// and displaying blanks with false, false
	if (guessCount >= 6)
	{
		printMessage("/|\\", false, false);
	}

	else
	{
		printMessage("", false, false);
	}
	// Logic for drawing the Hangman body 7
	// and displaying blanks with false, false
	if (guessCount >= 7)
	{
		printMessage("|", false, false);
	}

	else
	{
		printMessage("", false, false);
	}
	// Logic for drawing the Hangman body 8
	// and displaying blanks with false, false
	if (guessCount == 8)
	{
		printMessage("/  ", false, false);
	}
	// Logic for drawing the Hangman body 9
	// and displaying blanks with false, false
	if (guessCount == 9)
	{
		printMessage("/ \\", false, false);
	}

	// Logic for drawing blanks everywhere else
	else
	{
		printMessage("", false, false);
	}

}

// Logic for player input
void printLetters(set<char> guessed, char from, char to) 
{
	string s;
	for (char i = from; i <= to; i++)
	{
		if (guessed.find(i) == guessed.end())
		{
			s += i;
		}
		else
		{
			s += " ";
		}
	}
	printMessage(s, false, false);
}

// Logic for printing the alphabet on game start
void printAvailableLetters(set<char> guessed)
{
	printMessage("Available Letters");
	printLetters(guessed, 'A', 'M');
	printLetters(guessed, 'N', 'Z');
}

// Logic for checking the players input compared to random word chosen
bool printWordAndCheckWin(string word, set<char> guessed)
{
	bool won = true;
	string s;
	for (string::iterator it = word.begin(); it != word.end(); it++)
	{
		if (guessed.find(*it) == guessed.end())
		{
			won = false;
			s += "_ ";
		}
		else
		{
			s += *it;
			s += " ";
		}
	}
	printMessage(s, false);
	return won;
}