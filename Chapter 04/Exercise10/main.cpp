//
//  main.cpp
//  Excercise10
//
//  Created by Aidan Dougherty on 8/20/20.
//  Copyright © 2020 Aidan Dougherty. All rights reserved.
//
/*
    Write a program that plays the game “Rock, Paper, Scissors.” If you are not
    familiar with the game do some research (e.g., on the web using Google).
    Research is a common task for programmers. Use a switch-statement to
    solve this exercise. Also, the machine should give random answers (i.e.,
    select the next rock, paper, or scissors randomly). Real randomness is too
    hard to provide just now, so just build a vector with a sequence of values
    to be used as “the next value.” If you build the vector into the program,
    it will always play the same game, so maybe you should let the user enter
    some values. Try variations to make it less easy for the user to guess
    which move the machine will make next.
 */

//
#include "../../../std_lib_facilities.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

string winner(int);

int main(void) {
    //  To get random numbers, seed a random value (using time)
    srand(time(NULL));
    char ans = 'y';
    while (ans != 'n') {
        char user_choice, comp_choice;
        //  Pick a random number between 0 and 2 -- this will mean rock, paper, or scissors
        int comp_rand_num = rand() % 3;
        string result;
        
        cout << "Let's play Rock Paper Scissors!" << endl;
        cout << "Type rock (r), paper (p), or scissors (s): ";
        cin >> user_choice;
        
        //  Computer either chose rock, paper, or scissors.
        switch (comp_rand_num) {
            case 0:
                comp_choice = 'r';
                cout << "The computer chose rock. ";
                break;
            case 1:
                comp_choice = 'p';
                cout << "The computer chose paper. ";
                break;
            case 2:
                comp_choice = 's';
                cout << "The computer chose scissors. ";
                break;
            default:
                comp_choice = 'r';
                break;
        }
        
        //  Whatever user inputted, calculate result!
        cout << "You chose ";
        switch (user_choice) {
            case 'r':
                cout << "rock. ";
                switch (comp_choice) {
                    case 'r':
                        result = "It's a tie!";
                        break;
                    case 'p':
                        result = "You lost!";
                        break;
                    case 's':
                        result = "You won!";
                        break;
                }
                break;
            case 'p':
                cout << "paper. ";
                switch (comp_choice) {
                    case 'r':
                        result = "You won!";
                        break;
                    case 'p':
                        result = "It's a tie!";
                        break;
                    case 's':
                        result = "You lost!";
                        break;
                }
                break;
            case 's':
                cout << "scissors. ";
                switch (comp_choice) {
                    case 'r':
                        result = "You lost!";
                        break;
                    case 'p':
                        result = "You won!";
                        break;
                    case 's':
                        result = "It's a tie!";
                        break;
                }
                break;
            default:
                cout << "an invalid character! ('r', 'p', or 's'). ";
                result = "Try again!";
                break;
        }
        cout << result << endl;
        cout << "Continue? (y/n): ";
        cin >> ans;
        cout << endl;
    }
    return 0;
}
