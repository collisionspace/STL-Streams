//
// Created by James Slone on 10/28/16.
//

#include "States.h"

void States::gameLoop() {
    vector<Patient> patients;
    Utilities::read(&patients);
    PriorityQueue().addAllPatientsToPriorityQueue(&patients);
    //priority_queue<Patient> p = PriorityQueue().getPq();
    /*for (unsigned long i = 0; i < patients.size(); ++i) {
        pq.push(patients.at(i));
    }
    while (!pq.empty()) {
        Patient patient = pq.top();
        cout << patient.getPriority() << endl;
        pq.pop();
    }*/

    while(!States::isIsUserFinished()) {
        States::setIsUserFinished(true);
        cout << UserInput::readInput() << endl;
    }
}

bool States::isIsUserFinished() const {
    return isUserFinished;
}

void States::setIsUserFinished(bool isUserFinished) {
    States::isUserFinished = isUserFinished;
}
