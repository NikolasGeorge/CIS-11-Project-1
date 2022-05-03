/*
 * Author: Nikolas George
 * Purpose: Project 1
 */
 //User Libraries

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <algorithm>
#include "Scoreboard.h"
#include "Printing.h"

using namespace std;

Scoreboard::Scoreboard()
{
	// load scores from file
	ifstream reader("scoreBoard.txt");
	if (reader.is_open())
	{
		string name;
		int score;

		while (reader >> name >> score)
		{
			Score nameAndScore;

			nameAndScore.name = name;

			nameAndScore.score = score;

			scores.push_back(nameAndScore);

		}
		reader.close();

	}

}

Scoreboard::~Scoreboard()
{
	// save scores to file
	ofstream outfile("scoreBoard.txt");
	if (outfile.is_open())
	{
		for (auto itr = scores.begin(); itr != scores.end(); itr++)
		{
			outfile << itr->name;

			outfile << " ";
			outfile << itr->score;
			outfile << "\n";
		}

		outfile.close();

	}

}

void Scoreboard::recordNewScore(int score)
{
	Score nameAndScore;

	nameAndScore.score = score;

	string playerName;
	//printMessage(to_string (score));
	//printMessage("Current Score: " + to_string(score));

	printMessage("Enter your first name: ");
	cin >> playerName;
	nameAndScore.name = playerName;
	scores.push_back(nameAndScore);	// record score


}

void Scoreboard::printScores()
{
	// sort all scores
	scores.sort([](const Score& a, const Score& b) {
			return a.score > b.score;
		});

	// print all scores
	system("cls");
	printMessage("High Scores:");
	for (auto itr = scores.begin(); itr != scores.end(); itr++)
	{
		printMessage(itr->name + ": " + to_string(itr->score));
	}
}