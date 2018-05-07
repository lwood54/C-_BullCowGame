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
Ftext GetValidGuess();
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
    std::cout << "\n\nWelcome to Bulls and Cows, a fun word game.\n";
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() ;
    std::cout << " letter isogram I'm thinking of?\n";
    std::cout << std::endl;
    return;
}

// set limits and structure of game
void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
    // loop asking for guesses while the game is NOT won
	// and there are still tries remaining
	while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
		Ftext Guess = GetValidGuess();
		
		// submit valid guess to the game, and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		
		// print number of bulls and cows
		std::cout << "\nBulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
	}
	
	BCGame.PrintGameSummary(BCGame.IsGameWon());
	return;
}

// loop continuously until the user gives a valid guess
Ftext GetValidGuess()
{
	Ftext Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << ". Enter guess: ";
		
		std::getline (std::cin,Guess);
		
		Status = BCGame.CheckGuessValidity(Guess);
		switch(Status) {
			case EGuessStatus::Wrong_Length:
				std::cout << "Please enter a " << BCGame.GetHiddenWordLength()
				<< " letter word.\n";
				break;
			case EGuessStatus::Not_Lowercase:
				std::cout << "Only lowercase letters can be used.\n";
				break;
			case EGuessStatus::Not_Isogram:
				std::cout << "Word can't have repeating letters.\n";
				break;
			default:
				// assume guess is valid
				break;
		}
	} while(Status != EGuessStatus::OK); // Keep looping until no errors
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "\nDo you want to play again with the same hidden word? (y/n)";
	Ftext Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}
