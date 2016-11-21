//
// Created by James Slone on 10/28/16.
//

#include "PriorityQueue.h"

void PriorityQueue::addAllPatientsToPriorityQueue(vector<Patient> *patients) {
    for(int i; i < patients->size(); i++) {
        PriorityQueue::addPatientToPriorityQueue(patients->at(i));
    }
}

void PriorityQueue::addPatientToPriorityQueue(Patient patient) {
    pq.push(patient);
}

void PriorityQueue::setPq(const priority_queue<Patient, vector<Patient>, Priority> &pq) {
    PriorityQueue::pq = pq;
}

priority_queue<Patient, vector<Patient>, Priority> PriorityQueue::getPq() {
    return pq;
}
