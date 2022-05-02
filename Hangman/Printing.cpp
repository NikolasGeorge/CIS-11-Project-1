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
#include "Printing.h"

using namespace std;

bool printGame(int failedTries, string wordToGuess, string playerGuesses)
{
	system("cls");
	printMessage("HANG MAN");
	drawHangman(failedTries);
	printAvailableLetters(playerGuesses);
	printMessage("Guess the word");
	return printWordAndCheckWin(wordToGuess, playerGuesses);
}

void printMessage(string message, bool printTop, bool printBottom) // Logic for building the gameboard
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
void drawHangman(int guessCount) // Logic for drawing the Hangman body
{
	if (guessCount >= 1)
	{
		printMessage("|", false, false);
	}
	else
	{
		printMessage("", false, false);
	}
	if (guessCount >= 2)
	{
		printMessage("|", false, false);
	}
	else
	{
		printMessage("", false, false);
	}
	if (guessCount >= 3)
	{
		printMessage("O", false, false);
	}
	else
	{
		printMessage("", false, false);
	}
	if (guessCount == 4)
	{
		printMessage("/  ", false, false);
	}
	if (guessCount == 5)
	{
		printMessage("/| ", false, false);
	}
	if (guessCount >= 6)
	{
		printMessage("/|\\", false, false);
	}
	else
	{
		printMessage("", false, false);
	}
	if (guessCount >= 7)
	{
		printMessage("|", false, false);
	}
	else
	{
		printMessage("", false, false);
	}
	if (guessCount == 8)
	{
		printMessage("/  ", false, false);
	}
	if (guessCount == 9)
	{
		printMessage("/ \\", false, false);
	}
	else
	{
		printMessage("", false, false);
	}

}

void printLetters(string guessed, char from, char to) // Logic for player input
{
	string s;
	for (char i = from; i <= to; i++)
	{
		if (guessed.find(i) == string::npos)
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

void printAvailableLetters(string guessed) // Logic for printing the alphabet
{
	printMessage("Available Letters");
	printLetters(guessed, 'A', 'M');
	printLetters(guessed, 'N', 'Z');
}

bool printWordAndCheckWin(string word, string guessed) // Logic for checking the players input compared to random word chosen
{
	bool won = true;
	string s;
	for (int i = 0; i < word.length(); i++)
	{
		if (guessed.find(word[i]) == string::npos)
		{
			won = false;
			s += "_ ";
		}
		else
		{
			s += word[i];
			s += " ";
		}
	}
	printMessage(s, false);
	return won;
}