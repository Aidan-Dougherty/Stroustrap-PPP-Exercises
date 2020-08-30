//
//  main.cpp
//  Exercise08
//
//  Created by Aidan Dougherty on 8/27/20.
//  Copyright © 2020 Aidan Dougherty. All rights reserved.
//
/*
 Write a program that reads and stores a series of integers and then computes
the sum of the first N integers. First ask for N, then read the values
into a vector, then calculate the sum of the first N values. For example:
“Please enter the number of values you want to sum:”
3
“Please enter some integers (press '|' to stop):”
12 23 13 24 15 |
“The sum of the fi rst 3 numbers ( 12 23 13 ) is 48.”
 Handle all inputs. For example, make sure to give an error message if the
user asks for a sum of more numbers than there are in the vector.
 
 */

#include "../../../std_lib_facilities.h"

int getSumLimit(void)
{
    //  Pre-conditions: user_limit > 0 and is an integer
    //  Post-conditions: user_limit > 0 and is integer
    int user_limit = -1;
    cout << "Please enter the number of values you want to sum: " << endl;
    cin >> user_limit;
    if (user_limit < 0) {
        error ("You must enter a positive non-zero number!\n");
    }
    if (!cin.fail()) {
        return user_limit;
    } else {
        error("You must enter an integer!\n");
        return -1;  //  must return so that the compiler doesn't complain
    }
}

vector<int> getUserNumbers(void)
{
    //  Pre-conditions: user enters numbers or other characters. Non-numeric chars terminate input
    //  Post-conditions: An integer populated vector, might be empty
    vector<int> numbers;
    int user_number;
    cout << "Please enter some integers (press '|' to stop): ";
    while (cin >> user_number)
    {
        numbers.push_back(user_number);
    }
    return numbers;
}

int findSum(vector<int> numbers, int user_limit)
{
    int user_sum = 0;
    if (user_limit > numbers.size()) {
        error("The vector isn't big enough!");
    }
    for (int i = 0; i < user_limit; ++i) {
        user_sum += numbers[i];
    }
    return user_sum;
}

int main(void) {
    vector<int> numbers;
    try {
        int user_limit = getSumLimit();
        vector<int> numbers = getUserNumbers();
        int sum = findSum(numbers, user_limit);
        cout << "The sum of the first " << user_limit << " number(s) is " << sum << endl;
        return 0;
    } catch (exception& e) {
        cerr << "error: " << e.what() << endl;
        return 1;
    } catch (...) {
        cout << "Unknown error...";
        return 2;
    }
}
