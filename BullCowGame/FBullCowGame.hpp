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
struct BullCowCount
{
    int32 Bulls = 0;
    int32 Cows = 0;
};

class FBullCowGame {
public:
    FBullCowGame(); // Constructor Function
    
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    bool IsGameWon() const;
    
    void Reset(); // TODO: make a more rich return value.
    bool CheckGuessValidity(FString); // TODO: make more rich return value.
    BullCowCount SubmitGuess(FString);
    

// Ignore private for now, focus on public ^^^
private:
    // see constructor for initialization
    int32 MyCurrentTry; // compile time values(these), will be overridden by runtime values (in constructor)
    int32 MyMaxTries;
    FString MyHiddenWord;
};

#endif /* FBullCowGame_hpp */
