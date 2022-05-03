/*
 * Author: Nikolas George
 * Purpose: Project 1
 */
 //User Libraries

#pragma once

#include <iostream>
#include <fstream>
#include <string>
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

public:
	// ...
	Scoreboard();

	// ...
	~Scoreboard();

	// return if not good score; Print prompt, take initials, add to scoreboard
	void recordNewScore(int score); 

	// ...
	void printScores();
};