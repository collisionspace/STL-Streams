//
// Created by James Slone on 10/28/16.
//

#include "UserInput.h"
#include "PriorityQueue.h"
#include "Utilities.h"

PriorityQueue priority = PriorityQueue();

string UserInput::readInput() {
    string input;
    inputOptions();
    getline (cin, input);
    return input;
}

string UserInput::userInput() {
    string input;
    getline (cin, input);
    return input;
}

void UserInput::options(string input, vector<Patient> *patients, priority_queue<Patient, vector<Patient>, Priority> *pQueue) {
    switch(stoi(input)) {
        case 1: {//add patient to system
            priority.addPatientToPriorityQueue(readInPatient());
            *pQueue = priority.getPq();
            break;
        }
        case 2: //treat patient in priority order
        case 3: //print patients info
        case 4: //print report of treated patients
        case 5: //print next patient to be treated
        case 6: //print report of all patients waiting in priority queue
        case 7: //single command to treat all patients
        case 8: //print out all patients by doctor
        case 9: //print out a guide on each command the system offers. (-help)
        case 10: {//bulk add patients into the system from a file
            vector<Patient> patie;
            Utilities::read(&patie);
            priority.addAllPatientsToPriorityQueue(&patie);
            *pQueue = priority.getPq();
            break;
        }
        case 11: //I want all operations of the system to be logged to a file that I can specify
        default: {
            cout << "default" << endl;
            break;
        }
    }
}

void UserInput::inputOptions() {
    cout <<  "Welcome! Please select a number: " << endl;
    for(int i = 0; i < Option_Size; i++) {
        cout << i+1 << " - " << userOptions[i] << endl;
    }
}

Patient UserInput::readInPatient() {
    cout << "Enter first name" << endl;
    string firstName = userInput();
    cout << "Enter middle name" << endl;
    string middleName = userInput();
    cout << "Enter last name" << endl;
    string lastName = userInput();
    cout << "Enter suffix" << endl;
    string suffix = userInput();
    cout << "Enter the amount of ailments" << endl;
    int ailemntSize = isdigit(userInput()) ? stoi(userInput()) : 0;
    vector<string> ailments;
    for(int i = 0; i < ailemntSize; i++) {
        cout << "Enter the ailment" << endl;
        ailments.push_back(userInput());
    }
    cout << "Enter doctor" << endl;
    string doctor = userInput();
    cout << "Enter treated" << endl;
    bool treated = isdigit(userInput()) ? stoi(userInput()) : 0;
    cout << "Enter priority" << endl;
    int priority = stoi(userInput());
    return Patient(firstName,middleName,lastName,suffix,ailments,doctor,treated,priority);
}