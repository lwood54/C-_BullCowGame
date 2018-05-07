//
//  FBullCowGame.hpp
//  BullCowGame
//
//  Created by Logan Wood on 5/6/18.
//  Copyright © 2018 Logan Wood. All rights reserved.

#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp

#include <stdio.h>
#include <string>

using FString = std::string;
using int32 = int;

// all values initialized to zero
struct FBullCowCount
{
    int32 Bulls = 0;
    int32 Cows = 0;
};

enum class EGuessStatus
{
    Invalid_Status,
    OK,
    Not_Isogram,
    Wrong_Length,
    Not_Lowercase
};

class FBullCowGame {
public:
    FBullCowGame(); // Constructor Function
    
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    int32 GetHiddenWordLength() const;
    bool IsGameWon() const;
    
    EGuessStatus CheckGuessValidity(FString Guess) const;
    void PrintGameSummary(bool GameWon) const;
    
    void Reset(); // TODO: make a more rich return value.
    FBullCowCount SubmitValidGuess(FString Guess);
    
    

// Ignore private for now, focus on public ^^^
private:
    // see constructor for initialization
    int32 MyCurrentTry; // compile time values(these), will be overridden by runtime values (in constructor)
    int32 MyMaxTries;
    FString MyHiddenWord;
    bool bGameIsWon;
    bool IsIsogram(FString) const;
};

#endif /* FBullCowGame_hpp */
