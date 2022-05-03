/*
 * Author: Nikolas George
 * Purpose: Project 1
 */
 //User Libraries

#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <set>
#include <string>
#include <time.h>
#include <algorithm>

bool printGame(int failedTries, std::string wordToGuess, std::set<char> playerGuesses, int score);
void printMessage(std::string message, bool printTop = true, bool printBottom = true);
void drawHangman(int guessCount = 0);
void printLetters(std::set<char> guessed, char from, char to);
void printAvailableLetters(std::set<char> guessed);
bool printWordAndCheckWin(std::string word, std::set<char> guessed);