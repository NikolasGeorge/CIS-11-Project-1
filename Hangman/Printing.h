/*
 * Author: Nikolas George
 * Purpose: Project 1
 */

#pragma once

//User Libraries

#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <time.h>
#include <algorithm>


// Logic for printing the game when the user
// Requires the User to press P at the main menu
bool printGame(int failedTries, std::string wordToGuess, std::set<char> playerGuesses, int score);

// Logic for printing all messages
// With the unique border all the messages has
void printMessage(std::string message, bool printTop = true, bool printBottom = true);

// Logic for drawing the hangman
// only valid once P has been pressed at the main menu
void drawHangman(int guessCount = 0);

// Logic for displaying the alphabet to the player
// In a specifc location
void printLetters(std::set<char> guessed, char from, char to);

// Logic for taking away letters from the alphabet
// Uses the letters the players has entered and checked
void printAvailableLetters(std::set<char> guessed);

// Logic for printing the word and checking if they player has won
// If they have guessed the word needed to win
bool printWordAndCheckWin(std::string word, std::set<char> guessed);
