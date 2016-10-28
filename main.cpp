#include <iostream>
#include <vector>
#include <queue>
#include "Patient.h"
#include "Utilities.h"
using namespace std;
struct Priority {
    bool operator()(Patient const & p1, Patient const & p2) {
        return p1.getPriority() > p2.getPriority();
    }
};
int main() {
    vector<Patient> patients;
    Utilities::read(&patients);
    std::priority_queue<Patient, std::vector<Patient>, Priority> pq;
    for (unsigned long i = 0; i < patients.size(); ++i) {
        pq.push(patients.at(i));
    }
    while (!pq.empty()) {
        Patient patient = pq.top();
        cout << patient.getPriority() << endl;
        pq.pop();
    }
    return 0;
}