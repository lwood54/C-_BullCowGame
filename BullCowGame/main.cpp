//
//  main.cpp
//  BullCowGame
//
//  Created by Logan Wood on 5/5/18.
//  Copyright © 2018 Logan Wood. All rights reserved.
//
/*
 	This is the console executable that makes use of the BullCowClass.
 	This acts as the view in an MVC patter, and is responsible for all
 	user interaction. For game logic, see the FBullCowGame class.
 */


#include <iostream>
#include <string>
#include "FBullCowGame.hpp"

using Ftext = std::string;
using int32 = int;

FBullCowGame BCGame; // instantiate a new game

// setup prototypes of functions
void PrintIntro();
void PlayGame();
Ftext GetGuess();
bool AskToPlayAgain();

// ENTRY POINT FOR APPLICATION
int main() {
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	}
	while(bPlayAgain);
    return 0;
}

// introduce the game
void PrintIntro()
{
    constexpr int32 WORD_LENGTH = 9;
    std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
    std::cout << "Can you guess the " << WORD_LENGTH ;
    std::cout << " letter isogram I'm thinking of?\n";
    std::cout << std::endl;
    return;
}

// set limits and structure of game
void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries << std::endl;
    // loop for number of turns asking for guesses
	// TODO: change FOR to WHILE loop once we are validating tries
    for(int32 i = 0; i < MaxTries; i++)
    {
		Ftext Guess = GetGuess(); // TODO: make loop checking valid
		
		// submit valid guess to the game
		// print number of bulls and cows
		
        std::cout << "So, it looks like your guess was: " << Guess << std::endl;
        std::cout << std::endl;
    }
	
	// TODO: summarize game
}

// get a guess from the player
Ftext GetGuess()
{
	int32 CurrentTry = BCGame.GetCurrentTry();
    Ftext Guess = "";
    std::cout << "Try " << CurrentTry << ". Enter guess: ";
    std::getline (std::cin,Guess);
    return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n)";
	Ftext Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}
