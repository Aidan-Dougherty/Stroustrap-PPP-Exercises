//
//  main.cpp
//  Drill
//
//  Created by Aidan Dougherty on 8/17/20.
//  Copyright © 2020 Aidan Dougherty. All rights reserved.
//

#include <iostream>
#include "../../../std_lib_facilities.h"

double convertToMeters(double size, string unit);



int main() {
    vector<double> numbers;
    double small_num = 0, large_num = 0, num_sum = 0, temp_num;
    int num_count = 0;
    bool end_char_detected = false;
    string temp;
    //  vector<double> numbers;
    while(!end_char_detected)
    {
        cout << "Give me a number and a unit (cm, m, in, ft): ";
        cin >> temp_num >> temp;
        if (!cin.fail())    //  Then we have a number
        {
            //  If the unit is not valid then get new input
            if (temp != "m" && temp != "cm" && temp != "in" && temp != "ft") {
                cout << "Invalid input!" << endl;
                //  However, if the character inputted was the terminal character, then end program
                if (temp == "|") {
                    end_char_detected = true;
                }
                continue;
            }
            else {  //  It's a valid unit
                double temp_num_meters = convertToMeters(temp_num, temp);
                cout << "You entered: " << temp_num << " " << temp;
                if (temp_num_meters >= large_num) {
                    large_num = temp_num_meters;
                    cout << ", the largest so far.";
                }
                if (temp_num_meters <= small_num) {
                    small_num = temp_num_meters;
                    cout << ", the smallest so far.";
                }
                cout << endl;
                
                //  Keep track of sum, count, and store in vector for sorting.
                num_sum += temp_num_meters;
                ++num_count;
                numbers.push_back(temp_num_meters);
            }
        }
        else {  //  Non-numerical input
            cout << "Invalid input! Type a number followed by '|' to quit." << endl;
            cin.clear();
            cin.ignore();
            continue;
        }
    }
    sort(numbers.begin(), numbers.end());
    for (double x : numbers) {
        cout << x << " ";
    }
    if (num_count != 0) {
        cout << "Smallest: " << numbers[0] << ", Largest: " << large_num << "\nTotal count: " << num_count << ", Total sum: " << num_sum << endl; }
    return 0;
}

double convertToMeters(double size, string unit)
{
    if (unit == "cm") {
        size *= 0.01;
    } else if (unit == "in") {
        size *= (2.54/100);
    } else if (unit == "ft") {
        size *= (12 * 2.54/100);
    }
    else {}
    
    return size;
}
