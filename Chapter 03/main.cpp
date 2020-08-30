//
//  main.cpp
//  Drill
//
//  Created by Aidan Dougherty on 8/13/20.
//  Copyright © 2020 Aidan Dougherty. All rights reserved.
//

#include "std_lib_facilities.h"

int main() {
    cout << "Enter the name of the person you want to write to:\n";
    string recipient;
    cin >> recipient;
    cout << "Enter the name of a mutual friend you share, followed by their gender (m,f,or n for non-binary):\n";
    char friend_gender;
    string friend_name;
    cin >> friend_name >> friend_gender;
    cout << "Enter your name:\n";
    string sender;
    cin >> sender;
    cout << "Dear " << recipient << ",\n    How are you? I am fine. I miss you. Have you seen "<< friend_name << "lately?";
    if (friend_gender == 'm') {
        cout << "If you see " << friend_name << " please ask him to call me.";
    } else  if (friend_gender == 'f') {
        cout << "If you see " << friend_name << " please ask her to call me.";
    } else {
        cout << "If you see " << friend_name << " please ask them to call me.";
    }
    cout << "\n\nSincerely, " << sender << endl;}
    return 0;
}
