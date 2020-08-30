//
//  main.cpp
//  Excercise06
//
//  Created by Aidan Dougherty on 8/20/20.
//  Copyright © 2020 Aidan Dougherty. All rights reserved.
//
/*
    Make a vector holding the ten string values "zero", "one", . . . "nine".
    Use that in a program that converts a digit to its corresponding
    spelled-out value; e.g., the input 7 gives the output seven. Have the same
    program, using the same input loop, convert spelled-out numbers into
    their digit form; e.g., the input seven gives the output 7.
 */


#include "../../../std_lib_facilities.h"

void init_numbers(vector<string> &number)
{
    number.push_back("zero");
    number.push_back("one");
    number.push_back("two");
    number.push_back("three");
    number.push_back("four");
    number.push_back("five");
    number.push_back("six");
    number.push_back("seven");
    number.push_back("eight");
    number.push_back("nine");
}

void get_user_num(vector<string> &number) {
    int val = 10;
    cout << "Enter either a lowercase single digit number, or its english spelling -- I'll give you the other:" << endl;
    if (cin >> val) {
        cout << "Spelled out the number " << val << " is " << number[val] << endl;
    } else {
        cin.clear();
        
        string user_num;
        cin >> user_num;
        
        for (int i = 0; i < number.size(); ++i) {
            if (user_num == number[i]) {
                cout << "The number " << user_num << " as a digit is " << i << endl;
                return;
            }
        }   //  If make it through without returning, then user inputted wrong number
        cout << "That's not a lowercase single-digit number!" << endl;
    }
}

int main(void) {
    vector<string> eng_numbers; //  eng_number[i] is the i'th number in english.
    init_numbers(eng_numbers);  //  set vector to hold numerical words
    
    //  keep track of whether user would like to keep going or not
    char ans = 'y';
    while (ans != 'n') {
        get_user_num(eng_numbers);
        cout << "Continue? (y/n): ";
        cin >> ans;
    }
    return 0;
}
