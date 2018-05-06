//
//  main.cpp
//  BullCowGame
//
//  Created by Logan Wood on 5/5/18.
//  Copyright © 2018 Logan Wood. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuess();
void PrintGuess(string Guess);

// ENTRY POINT FOR APPLICATION
int main() {
    PrintIntro();
    
    // loop for number of turns asking for guesses
    constexpr int NUMBER_OF_TURNS = 5;
    for(int i = 0; i < NUMBER_OF_TURNS; i++)
    {
        PrintGuess(GetGuess());
        cout << endl;
    }
    return 0;
}

// introduce the game
void PrintIntro()
{
    constexpr int WORD_LENGTH = 9;
    cout << "Welcome to Bulls and Cows, a fun word game.\n";
    cout << "Can you guess the " << WORD_LENGTH ;
    cout << " letter isogram I'm thinking of?\n";
    cout << endl;
    return;
}

// get a guess from the player
string GetGuess()
{
    string Guess = "";
    cout << "Enter guess: ";
    getline (cin,Guess);
    return Guess;
}

// repeat the guess back to them
void PrintGuess(string Guess)
{
    cout << "So, your guess is '" << Guess << "'?\n";
}
