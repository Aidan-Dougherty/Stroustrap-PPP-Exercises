//
//  main.cpp
//  Exercise07
//
//  Created by Aidan Dougherty on 8/26/20.
//  Copyright © 2020 Aidan Dougherty. All rights reserved.
//
/*
 Quadratic equations are of the form
a ⋅ x + b ⋅ x + c = 2 0
To solve these, one uses the quadratic formula:
x =
-b ± sqrt(b^2 - 4ac)/2a

=
−  − 2 4
2
There is a problem, though: if b 2–4ac is less than zero, then it will fail.
Write a program that can calculate x for a quadratic equation. Create a
function that prints out the roots of a quadratic equation, given a, b, c.
When the program detects an equation with no real roots, have it print
out a message. How do you know that your results are plausible? Can
you check that they are correct?
 
 x^2 + 2x + 1
 */

#include "../../../std_lib_facilities.h"

void findRoots(double a, double b, double c, double& first_root, double& second_root)
//  finds the roots using the quadratic formula
//  pre-conditions: doesn't yield an imaginary root, and a != 0
{
    if ((b*b) - 4*a*c < 0) {
        error("No real roots!");
    } else if (a == 0) {
        error("'a' can't be zero -- that's a linear equation!");
    } else {
        first_root = ((-b) + (sqrt(b*b - 4*a*c)))/(2*a);
        second_root = ((-b) - (sqrt(b*b - 4*a*c)))/(2*a);
        cout << "The roots are: " << first_root << " and " << second_root << endl;
    }
}

void getCoefficients(double& a, double& b, double& c)
//  ask user for coefficients of a quadratic equation
//  pre-cond: a, b, c all doubles separated by space
{
    cout << "Give me the three coefficients of a quadratic equation and I'll give you the roots!" << endl;
    cin >> a >> b >> c;
    if (cin.fail()) {
        error("I can't process those numbers!");
    }
}

bool askCheckRoots(char answer) {
    cout << "Would you like to check the roots? (y/n): ";
    cin >> answer;
    if (answer == 'y') {
        return true;
    } else if (answer == 'n') {
        return false;
    } else {
        cout << "Please type 'y' or 'n' only!" << endl;
        return askCheckRoots(answer);
    }
}

void checkRoot(double a, double b, double c, double root)
//
{
    double result = a*root*root + b*root + c;
    cout << "When x = " << root << ", then the equation becomes:\n";
    cout << a * root * root << " + (" << b * root << ") + (" << c << ")\n";
    cout << "Which is equal to " << result << endl;
    if (result == 0) {
        cout << "The root checks out!\n" << endl;
    } else {
        cout << "Bad root!\n" << endl;
    }
}

int main(void) {
    double a, b, c, first_root, second_root;
    char ans_cont_finding = 'y';
    
    while (ans_cont_finding != 'n') {
        try {
            getCoefficients(a, b, c);
            findRoots(a, b, c, first_root, second_root);
            
            char ans_check_roots = 'a';
            if (askCheckRoots(ans_check_roots)) {
                cout << "\nFor the equation: " << a << "x^2 + (" << b << "x) + (" << c << ") = 0," << endl;
                checkRoot(a, b, c, first_root);
                checkRoot(a, b, c, second_root);
            }
        } catch (exception& e) {
            cerr << "error: " << e.what() << '\n';
            return 1;
        } catch (...) {
            cout << "Unknown error..." << endl;
            return 2;
        }
        cout << "Would you like to keep finding roots? (y/n): ";
        cin >> ans_cont_finding;
        
        //  To ensure user behaves, they must respond 'y' or 'n'. yes/no will work too
        while (ans_cont_finding != 'y' && ans_cont_finding != 'n') {
            cout << "You must type either 'y' or 'n'!\n";
            cin >> ans_cont_finding;
            cin.clear();    //  Necessary for when going back to calculate more roots
        }
    }
    
    return 0;
}
