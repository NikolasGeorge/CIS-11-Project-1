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
#include "Scoreboard.h"

using namespace std;

enum GameState { Running, Won, Lost };

void printMessage(string message, bool printTop = true, bool printBottom = true) // Logic for building the gameboard
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
void drawHangman(int guessCount = 0) // Logic for drawing the Hangman body
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

void playGame()
{
	srand(time(0)); // Logic for tracking game time
	string playerGuesses;
	string wordToGuess;
	wordToGuess = loadRandomWord("hardWords.txt"); // Logic for loading the random word from a set list
	int failedTries = 0;
	GameState state = GameState::Running;
	do
	{
		system("cls");
		printMessage("HANG MAN");
		drawHangman(failedTries);
		printAvailableLetters(playerGuesses);
		printMessage("Guess the word");

		bool won = printWordAndCheckWin(wordToGuess, playerGuesses); // TODO split this
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

	cout << wordToGuess << endl << endl;
	drawHangman(9);
	printAvailableLetters(playerGuesses);
	if (state == GameState::Won) // Logic for the player has won and reset
	{
		printMessage("YOU WON!");
	}

	else // Logic for player losing
	{
		system("cls");
		printMessage("GAME OVER");
		cout << "The word was " << wordToGuess << '\x07' << endl << endl;
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