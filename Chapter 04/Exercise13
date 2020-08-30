//
//  main.cpp
//  Excercise13
//
//  Created by Aidan Dougherty on 8/21/20.
//  Copyright © 2020 Aidan Dougherty. All rights reserved.
//
/*
    Excercise 13: Create a program to find all the prime numbers between 1 and 100. There
    is a classic method for doing this, called the “Sieve of Eratosthenes.” If
    you don’t know that method, get on the web and look it up. Write your
    program using this method.
 */

/*
    This program uses the Sieve of Eratosthenes to compute prime numbers.
    It prompts the user for a positive integer between
 */


#include <iostream>
#include "../../../std_lib_facilities.h"

//  This function finds and prints prime numbers up to (not including) a given limit.
void findPrimes(int upper_limit) {
    bool primes[upper_limit];   //  store whether the indexed value (corresponds to a number) is prime
    for (int i = 0; i <= upper_limit; ++i) {
        //  Populate the array with true values to begin
        primes[i] = true;
    }
    //  If a number is a multiple of a prime (starting with 2), then set it's prime status to "false"
    //  then, continue to the next prime number (remaining trues) and repeat
    for (int i = 2; i <= sqrt(upper_limit); ++i) {
        if (primes[i] == true) {
            for (int j = 2*i; j < upper_limit; j += i) {
                primes[j] = false;
            }
        }
    }
    //  Print out the prime numbers separated by a space.
    for (int i = 2; i < upper_limit; ++i) {
        if (primes[i] == true) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main(void) {
    int prime_limit = 0;
    char ans = 'y';
    cout << "This is the Sieve of Eratosthenes -- It computes all the prime numbers by iteratively omitting multiples of primes." << endl;
    cout << "Enter a positive integer (greater than 1) up to which I'll give you all the prime numbers before it." << endl;;
    cout << "So that I don't go computing forever, please limit your input to no greater than 100,000: " << endl;
    //  As long as user wants to (accept all non-'n' responses as "yes, continue"), and they've inputted a positive integer...
    while (ans != 'n' && cin >> prime_limit) {
        if (prime_limit <= 1) { //  User entered improper character or number less than 2
            cout << "It must be a positive integer greater than 1!" << endl;
            cin.clear();
            continue;
        } else if (prime_limit > 100000) {  //  User entered too large a number
            cout << "That's too large, are you trying to kill me?!" << endl;
            cin.clear();
            continue;
        } else {    //  The number is valid!
            findPrimes(prime_limit);
            cout << "Continue? (y/n): ";
            cin >> ans;
        }
    }
    return 0;
}
