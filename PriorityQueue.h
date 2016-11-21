//
// Created by James Slone on 10/28/16.
//

#ifndef SLONE_PROJECT3_PRIORITYQUEUE_H
#define SLONE_PROJECT3_PRIORITYQUEUE_H

#include <iostream>
#include <queue>
#include "Patient.h"

struct Priority {
    bool operator()(Patient const & p1, Patient const & p2) {
        return p1.getPriority() > p2.getPriority();
    }
};
class PriorityQueue {
private:
    priority_queue<Patient, vector<Patient>, Priority> pq;
public:
    priority_queue<Patient, vector<Patient>, Priority> getPq();
    void setPq(const priority_queue<Patient, vector<Patient>, Priority> &pq);
    void addAllPatientsToPriorityQueue(vector<Patient> *patients);
    void addPatientToPriorityQueue(Patient patient);
};


#endif //SLONE_PROJECT3_PRIORITYQUEUE_H
