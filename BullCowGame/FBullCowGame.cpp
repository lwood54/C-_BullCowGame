//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by Logan Wood on 5/6/18.
//  Copyright © 2018 Logan Wood. All rights reserved.
//

#include "FBullCowGame.hpp"
#include <iostream>
#include <map>
#define TMap std::map

using FString = std::string;
using int32 = int;

// Defining the CONSTRUCTOR FUNCTION
FBullCowGame::FBullCowGame() { Reset(); }

// GETTERS:
int32 FBullCowGame::GetMaxTries() const {return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const {return MyCurrentTry;}
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }


// resets all values, also used at start of game
void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 8;
    const FString HIDDEN_WORD = "planet";
    
    MyMaxTries = MAX_TRIES;
    MyHiddenWord = HIDDEN_WORD;
    MyCurrentTry = 1;
    bGameIsWon = false;
    return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
    if (!IsIsogram(Guess)) // if the guess isn't an isogram
    {
        return EGuessStatus::Not_Isogram;
    }
    else if(false) // if the guess isn't all lowercase
    {
        return EGuessStatus::Not_Lowercase; // TODO: write function
    }
    else if(Guess.length() != GetHiddenWordLength()) // if the guess length is wrong length
    {
        return EGuessStatus::Wrong_Length;
    }
    else
    {
        return EGuessStatus::OK;
    }
}





// receives a VALID guess, increments turn, and return count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
    MyCurrentTry++;
    FBullCowCount BullCowCount;
    int32 WordLength = static_cast<int>(MyHiddenWord.length()); // assuming same length as guess

    // loop through all letters in the guess
    for(int32 i = 0; i < WordLength; i++)
    {
        // compare letters against the hidden word
        for(int32 j = 0; j < WordLength; j++)
        {
            if(MyHiddenWord[i] == Guess[j])
            {
                if(i == j)
                {
                    BullCowCount.Bulls++;
                }
                else
                {
                    BullCowCount.Cows++;
                }
            }
        }
        
    }
    if(BullCowCount.Bulls == WordLength) {
        bGameIsWon = true;
    }
    return BullCowCount;
}

void FBullCowGame::PrintGameSummary(bool GameWon) const
{
    if(GameWon) {
        std::cout << "Congrats, you won!!!\n";
    } else {
        std::cout << "Sorry, better luck next time.\n";
    }
}

bool FBullCowGame::IsIsogram(FString Word) const
{
    // treat 0 and 1 letter words as isograms
    if(Word.length() <= 1) { return true; }
    
    // setup our map
    TMap<char, bool> LetterSeen;
    for(auto Letter : Word) // for all letters of the word
    {
        Letter = tolower(Letter); // handle mixed case
        if(LetterSeen[Letter]) { // if the letter is in the map
            return false; // we do NOT have an isogram
        } else {
            LetterSeen[Letter] = true; // add the letter to the map as seen
        }
    }
    return true; // for example in cases where \0 is entered
}






