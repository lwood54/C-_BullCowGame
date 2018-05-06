//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by Logan Wood on 5/6/18.
//  Copyright © 2018 Logan Wood. All rights reserved.
//

#include "FBullCowGame.hpp"
using FString = std::string;
using int32 = int;

// Defining the CONSTRUCTOR FUNCTION
FBullCowGame::FBullCowGame() { Reset(); }

// GETTERS:
int32 FBullCowGame::GetMaxTries() const {return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const {return MyCurrentTry;}


void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 8;
    MyMaxTries = MAX_TRIES;
    
    const FString HIDDEN_WORD = "planet";
    MyHiddenWord = HIDDEN_WORD;
    MyCurrentTry = 1;
    return;
}

bool FBullCowGame::IsGameWon() const
{
    return 0;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
    return 0;
}

// receives a VALID guess, increments turn, and return count
BullCowCount FBullCowGame::SubmitGuess(FString)
{
    // increment the turn number
    MyCurrentTry++;
    
    // setup a return variable
    BullCowCount BullCowCount;
    
    // loop through all letters in the guess
        // compare letters against the hidden word
    
    
    return BullCowCount;
}








