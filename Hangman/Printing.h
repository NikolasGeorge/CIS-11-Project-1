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

bool printGame(int failedTries, std::string wordToGuess, std::string playerGuesses);
void printMessage(std::string message, bool printTop = true, bool printBottom = true);
void drawHangman(int guessCount = 0);
void printLetters(std::string guessed, char from, char to);
void printAvailableLetters(std::string guessed);
bool printWordAndCheckWin(std::string word, std::string guessed);