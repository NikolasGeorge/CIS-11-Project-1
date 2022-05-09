/*
 * Author: Nikolas George
 * Purpose: Project 1
 */

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <time.h>
#include <algorithm>
#include <iterator>
#include "Scoreboard.h"
#include "Printing.h"

 //User Libraries

using namespace std;

// Read a Score from an istream
istream& operator>> (istream& is, Score& score) {
	is >> score.name >> score.score;
	return is;
}

// Print a Score to a ostream
ostream& operator<<(ostream& os, const Score& score) {
	os << score.name << " " << score.score;
	return os;
}


Scoreboard::Scoreboard()
{
	// load scores from file-
	// and display in a specific order
	ifstream reader("scoreBoard.txt");
	if (reader.is_open())
	{
		string name;
		int score;

		istream_iterator<Score> scoreItr(reader);

		while (scoreItr != istream_iterator<Score>())
		{
			scores.push_back(*scoreItr);
			scoreItr++;
		}

		// Close reader when we are done
		reader.close();

	}

	// Code for the computer to pick from and taunt the player
	gameOverMessages.push("Try again!");
	gameOverMessages.push("Wow you lost?");
	gameOverMessages.push("Wasn't the word obvious?");
	gameOverMessages.push("Losing? That's cringe bro.");
	gameOverMessages.push("Who's keeping score anyway?");
	gameOverMessages.push("Don't quit your day job.");
	gameOverMessages.push("Cringe.");
	gameOverMessages.push("HAHAHAHAHAH!");
	gameOverMessages.push("IQ lower than the room temperature in Alaska.");
	gameOverMessages.push("Your rent or mortgage is going up for that.");
	gameOverMessages.push("I should have just Segfaulted from watching you.");
	gameOverMessages.push("I hope your code gets linker errors.");
	gameOverMessages.push("You're a third rate player with a fourth rate vocabulary");
	gameOverMessages.push("Don't play again. Just don't.");
	gameOverMessages.push("According to all known laws of aviation, there is no way a bee should be able to fly.");
	gameOverMessages.push("AHHHHHHHHHHHHHHHHH");
	gameOverMessages.push("We need to see the compiler as the enemy.");
	gameOverMessages.push("Did better than the average Valorant player.");
	gameOverMessages.push("Stop");
	gameOverMessages.push("Go eat a can of beans.");

}

Scoreboard::~Scoreboard()
{
	// Save scores to a text file
	ofstream outfile("scoreBoard.txt");
	if (outfile.is_open())
	{
		ostream_iterator<Score> outfileItr(outfile, "\n");

		// We use another itr for displaying the scores
		for (auto itr = scores.begin(); itr != scores.end(); itr++)
		{
			*outfileItr = *itr;
		}

		// When the leader-board has exited we go back to the main menu
		outfile.close();
	}

}

void Scoreboard::recordNewScore(int score)
{
	system("cls");

	// This code prints a game over message
	string gameOverMessage = gameOverMessages.front();
	gameOverMessages.pop();
	gameOverMessages.push(gameOverMessage);
	printMessage(gameOverMessage);


	// Logic for storing player Score
	Score nameAndScore;

	nameAndScore.score = score;

	// Logic for storing player name
	string playerName;

	// Record user name for storing score
	printMessage("Enter your first name: ");
	cin >> playerName;
	// Record score for game over
	nameAndScore.name = playerName;
	scores.push_back(nameAndScore);	

	printScores();
	system("pause");
}

void Scoreboard::printScores()
{
	// Sort all scores-
	// With a specifc pattern
	scores.sort([](const Score& a, const Score& b) {
			return a.score > b.score;
		});

	// Print all scores when user-
	// Presses L at main menu
	system("cls");
	// Display message High Scores:
	printMessage("High Scores:");
	for (auto itr = scores.begin(); itr != scores.end(); itr++)
	{
		printMessage(itr->name + ": " + to_string(itr->score));
	}
}