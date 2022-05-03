/*
 * Author: Nikolas George
 * Purpose: Project 1
 */
 //User Libraries

#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <time.h>
#include <algorithm>

class Scoreboard
{
	// TODO some private container for score

public:

	 //Scoreboard();
	 //~Scoreboard();

	void recordNewScore(int score); // return if not good score; Print prompt, take initials, add to scoreboard

	void printScores();
};