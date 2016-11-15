//
// Created by James Slone on 10/28/16.
//

#include "States.h"

UserInput uInput = UserInput();
void States::gameLoop() {
    vector<Patient> patients;
    priority_queue<Patient, vector<Patient>, Priority> pQueue;
    /*for (unsigned long i = 0; i < patients.size(); ++i) {
        p.push(patients.at(i));
    }
    while (!p.empty()) {
        Patient patient = p.top();
        cout << patient.getPriority() << endl;
        p.pop();
    }*/

    while(!States::isIsUserFinished()) {
        string input = uInput.readInput();
        if (stoi(input) == 11) { States::setIsUserFinished(true); }
        uInput.options(input, &patients, &pQueue);
        cout << "\n\n\n\n top poop " << pQueue.size() << endl;
    }
}

bool States::isIsUserFinished() const {
    return isUserFinished;
}

void States::setIsUserFinished(bool isUserFinished) {
    States::isUserFinished = isUserFinished;
}
