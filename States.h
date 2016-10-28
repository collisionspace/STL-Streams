//
// Created by James Slone on 10/28/16.
//

#ifndef SLONE_PROJECT3_STATES_H
#define SLONE_PROJECT3_STATES_H

#include <iostream>
#include <vector>
#include <queue>
#include "Patient.h"
#include "Utilities.h"
#include "UserInput.h"
#include "PriorityQueue.h"
using namespace std;

class States {
private:
    bool isUserFinished = false;

public:
    bool isIsUserFinished() const;
    void setIsUserFinished(bool isUserFinished);
    void gameLoop();

};


#endif //SLONE_PROJECT3_STATES_H
