//
//  main.cpp
//  Exercise05
//
//  Created by Aidan Dougherty on 8/20/20.
//  Copyright © 2020 Aidan Dougherty. All rights reserved.
//
/*  Exercise 4.5: Write a program that performs as a very simple calculator. Your calculator
    should be able to handle the four basic math operations — add, subtract,
    multiply, and divide — on two input values. Your program should prompt
    the user to enter three arguments: two double values and a character to
    represent an operation. If the entry arguments are 35.6, 24.1, and '+', the
    program output should be The sum of 35.6 and 24.1 is 59.7. In Chapter 6
    we look at a much more sophisticated simple calculator.
 */

//


#include "../../../std_lib_facilities.h"

int main(void) {
    double lvalue = 0, rvalue = 0;
    char operation;
    cout << "Enter two values (decimals ok), separated by a basic operator (+, -, *, /):" << endl;
    cin >> lvalue >> operation >> rvalue;
    if (operation == '+') {
        cout << "= " << lvalue + rvalue << endl;
    } else if (operation == '-') {
        cout << "= " << lvalue - rvalue << endl;
    } else if (operation == '*') {
        cout << "= " << lvalue * rvalue << endl;
    } else if (operation == '/') {
        if (rvalue == 0) {
            cout << "I can't divide by 0!" << endl;
            return 1;
        }
        cout << "= " << lvalue / rvalue << endl;
    } else {
        cout << "I can't do that operation!" << endl;
    }
    return 0;
}
