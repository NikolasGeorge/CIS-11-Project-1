/*
 * Author: Nikolas George
 * Purpose: Project 1
 */


#pragma once

#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <time.h>
#include <algorithm>
 //User Libraries


// ssss
bool printGame(int failedTries, std::string wordToGuess, std::set<char> playerGuesses, int score);

// sssss
void printMessage(std::string message, bool printTop = true, bool printBottom = true);

// sssss
void drawHangman(int guessCount = 0);

void printLetters(std::set<char> guessed, char from, char to);

void printAvailableLetters(std::set<char> guessed);

bool printWordAndCheckWin(std::string word, std::set<char> guessed);
