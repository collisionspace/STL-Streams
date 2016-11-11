//
// Created by James Slone on 10/28/16.
//

#include "UserInput.h"
#include "PriorityQueue.h"
#include "Utilities.h"

string UserInput::readInput() {
    string input;
    inputOptions();
    getline (cin, input);
    return input;
}

priority_queue<Patient, vector<Patient>, Priority> UserInput::options(string input, vector<Patient> *patients, priority_queue<Patient, vector<Patient>, Priority> pQueue) {
    switch(std::stoi(input)) {
        case 1: //add patient to system
        case 2: //treat patient in priority order
        case 3: //print patients info
        case 4: //print report of treated patients
        case 5: //print next patient to be treated
        case 6: //print report of all patients waiting in priority queue
        case 7: //single command to treat all patients
        case 8: //print out all patients by doctor
        case 9: //print out a guide on each command the system offers. (-help)
        case 10: {//bulk add patients into the system from a file
            Utilities::read(*&patients);
            PriorityQueue().addAllPatientsToPriorityQueue(*&patients);
            pQueue = PriorityQueue().getPq();
        }
        case 11: //I want all operations of the system to be logged to a file that I can specify
        default: cout << "default" << endl;
    }
    return pQueue;
}

void UserInput::inputOptions() {
    cout <<  "Welcome! Please select a number: " << endl;
    for(int i = 0; i < 10; i++) {
        cout << i << " - " << userOptions[i] << endl;
    }
}