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

void UserInput::options(string input, vector<Patient> *treatedPatients, priority_queue<Patient, vector<Patient>, Priority> *pQueue) {
    switch(stoi(input)) {
        case 1: {//add patient to system
            priority.addPatientToPriorityQueue(readInPatient());
            *pQueue = priority.getPq();
            break;
        }
        case 2: {//treat patient in priority order
            if (pQueue->empty()) {
                cout << "There is no patient currently in queue" << endl;
            }
            else {
                treatedPatients->push_back(treatPatient(pQueue));
            }
            break;
        }
        case 3: {//print patients info
            vector<Patient> patients = merge(treatedPatients, pQueue);
            sort(patients.begin(), patients.end(), lessThan());
            outputAllPatients(&patients);
            break;
        }
        case 4: {//print report of treated patients
            outputAllPatients(treatedPatients);
            break;
        }
        case 5: {//print next patient to be treated
            pQueue->top().outputPatient();
            break;
        }
        case 6: {//print report of all patients waiting in priority queue
            vector<Patient> p = patientsWaiting(*pQueue);
            outputAllPatients(&p);
            break;
        }
        case 7: {//single command to treat all patients
            treatAllPatients(treatedPatients, pQueue);
            break;
        }
        case 8: {//print out all patients by doctor
            outputByDoctor(treatedPatients, pQueue);
            break;
        }
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
    string input = userInput();
    bool has_only_digits = (input.find_first_not_of( "0123456789" ) == string::npos);
    int ailemntSize = has_only_digits ? stoi(input) : 0;
    vector<string> ailments;
    for(int i = 0; i < ailemntSize; i++) {
        cout << "Enter the ailment" << endl;
        ailments.push_back(userInput());
    }
    cout << "Enter doctor" << endl;
    string doctor = userInput();
    cout << "Enter treated" << endl;
    input = userInput();
    has_only_digits = (input.find_first_not_of( "0123456789" ) == string::npos);
    bool treated = has_only_digits ? stoi(input) : 0;
    cout << "Enter priority" << endl;
    input = userInput();
    has_only_digits = (input.find_first_not_of( "0123456789" ) == string::npos);
    int priority = has_only_digits ? stoi(input) : 0;
    return Patient(firstName,middleName,lastName,suffix,ailments,doctor,treated,priority);
}

void UserInput::outputAllPatients(vector<Patient> *patients) {
    for(Patient &patient : *patients) {
        patient.outputPatient();
    }
}

vector<Patient> UserInput::patientsWaiting(priority_queue<Patient, vector<Patient>, Priority> priorityQ) {
    vector<Patient> patients;
    while(!priorityQ.empty()) {
        patients.push_back(priorityQ.top());
        priorityQ.pop();
    }
    return patients;
}

void UserInput::treatAllPatients(vector<Patient> *treatedPatients, priority_queue<Patient, vector<Patient>, Priority> *pQueue) {
    while(!pQueue->empty()) {
        treatedPatients->push_back(treatPatient(pQueue));
    }
}

Patient UserInput::treatPatient(priority_queue<Patient, vector<Patient>, Priority> *pQueue) {
    Patient patient = pQueue->top();
    patient.setTreated(1);
    pQueue->pop();
    return patient;
}

void UserInput::outputByDoctor(vector<Patient> *treatedPatients, priority_queue<Patient, vector<Patient>, Priority> *pQueue) {
    vector<Patient> patients = merge(treatedPatients, pQueue);
    std::sort(patients.begin(), patients.end());
    outputAllPatients(&patients);
}

vector<Patient> UserInput::merge(vector<Patient> *treatedPatients, priority_queue<Patient, vector<Patient>, Priority> *pQueue) {
    vector<Patient> patients = patientsWaiting(*pQueue);
    for (Patient &treated : *treatedPatients) {
        patients.push_back(treated);
    }
    return patients;
}
