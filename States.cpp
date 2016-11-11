//
// Created by James Slone on 10/28/16.
//

#include "States.h"

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
        States::setIsUserFinished(true);
        string input = UserInput().readInput();
        pQueue = UserInput::options(input, &patients, pQueue);
        cout << patients[0].getPriority() << endl;
        cout << "top " << pQueue.top().getDoctor() << endl;
    }
}

bool States::isIsUserFinished() const {
    return isUserFinished;
}

void States::setIsUserFinished(bool isUserFinished) {
    States::isUserFinished = isUserFinished;
}
