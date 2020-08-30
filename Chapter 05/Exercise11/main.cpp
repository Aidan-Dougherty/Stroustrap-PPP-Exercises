//
//  main.cpp
//  Exercise11
//
//  Created by Aidan Dougherty on 8/29/20.
//  Copyright © 2020 Aidan Dougherty. All rights reserved.
//

/*
 Write a program that writes out the first so many values of the Fibonacci
series, that is, the series that starts with 1 1 2 3 5 8 13 21 34. The next
number of the series is the sum of the two previous ones. Find the largest
Fibonacci number that fits in an int.
 
 My solution uses a simple recursive algorithm to compute the Fibonacci numbers, and
 stores them in a vector up to the user_limit (this way the program is more modular)
 */

#include "../../../std_lib_facilities.h"

int fib(int n)
//  Pre-conditions: n is positive integer
//  Post-conditions: n is the n'th fibonacci number (0 being the 0th, 1 the 1st ... )
{
    //  Base case: 0'th is 0, 1st is 1.
   if (n <= 1)
      return n;
    //  Recursively solve the n'th fibonacci number
   return fib(n-1) + fib(n-2);
}

int getLimit(void)
{
    //  Pre-conditions: user input is positive integer
    //  post-condition: the fibonacci limit is a positive integer
    int user_limit;
    cout << "Give me an integer, and I'll tell you the largest fibonacci number that is less than it!" << endl;
    //  Ensure user inputs positive integer
    if(cin >> user_limit && user_limit > 0) {
        return user_limit;
    }
    else {
        error("You must give a positive integer");
    }
    return 3;
}

int main(void) {
    try {
        int user_limit = getLimit();
        vector<int> fib_nums;
        
        cout << "The Fibonacci sequence up until " << user_limit << " is the following: " << endl;
        
        for (int i = 0; i < user_limit; ++i) {
            int current_fib_num = fib(i);   //  calculate it once
            if (current_fib_num < user_limit) {
                cout << current_fib_num << " ";
                fib_nums.push_back(current_fib_num);    //  An easy way to print the last fibonacci number
            } else break;
        }
        //  Print the largest Fibonacci number -- which is the last one computed
        cout << "\nThe largest Fibonacci number that fits into " << user_limit << " is " << fib_nums.back() << endl;
        return 0;
    } catch (exception& e) {
        cerr << e.what() << endl;
        return 1;
    } catch (...) {
        cerr << "Unknown error." << endl;
        return 2;
    }
}
