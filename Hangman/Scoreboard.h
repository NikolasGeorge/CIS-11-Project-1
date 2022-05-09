/*
 * Author: Nikolas George
 * Purpose: Project 1
 */

#pragma once

//User Libraries

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <time.h>
#include <algorithm>
#include <list>

struct Score
{
	std::string name;
	int score;
};


class Scoreboard
{
	std::list<Score> scores;
	std::queue<std::string> gameOverMessages;

public:
	// Scoreboard constructor
	Scoreboard();

	// Scoreboard deconstructor
	~Scoreboard();

	// return if not good score; Print prompt, take initials, add to scoreboard
	void recordNewScore(int score); 

	// ...
	void printScores();
};