//
// Created by James Slone on 10/28/16.
//

#include "States.h"

UserInput uInput = UserInput();
void States::gameLoop() {
    vector<Patient> treatedPatients;
    priority_queue<Patient, vector<Patient>, Priority> pQueue;
    srand (time(NULL));

    while(!States::isIsUserFinished()) {
        string input = uInput.readInput();
        if (stoi(input) == 11) { States::setIsUserFinished(true); }
        uInput.options(input, &treatedPatients, &pQueue);
        if (treatedPatients.size() > 0) {
            cout << treatedPatients.at(treatedPatients.size()-1).getFirstName() << endl;
            cout << treatedPatients.at(treatedPatients.size()-1).isTreated() << endl;
        }
    }
}

bool States::isIsUserFinished() const {
    return isUserFinished;
}

void States::setIsUserFinished(bool isUserFinished) {
    States::isUserFinished = isUserFinished;
}
