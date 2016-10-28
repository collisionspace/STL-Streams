//
// Created by James Slone on 10/28/16.
//

#include <sstream>
#include "UserInput.h"

string UserInput::readInput() {
    string input;
    cout << "What's your name? ";
    getline (cin, input);
    return input;
}
