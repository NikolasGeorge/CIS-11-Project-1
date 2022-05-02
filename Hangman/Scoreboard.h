#pragma once

class Scoreboard
{
	// TODO some private container for score

public:

	// Scoreboard();
	// ~Scoreboard();

	bool maybeRecordNewScore(int score); // return if not good score; Print prompt, take initials, add to scoreboard

	void printScoreboard();
};