//
// Created by James Slone on 10/28/16.
//

#ifndef SLONE_PROJECT3_USERINPUT_H
#define SLONE_PROJECT3_USERINPUT_H

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include "Patient.h"
#include "PriorityQueue.h"

#define ADD_PATIENT "Add patient to the system"
#define TREAT_PATIENT "Treat the next patient that is in priority"
#define PRINT_PATIENT_INFO "Print patient info"
#define PRINT_TREAT_PATIENTS "Print report of treated patients"
#define NEXT_PATIENT "Next patient to be treated"
#define ALL_PATIENTS_IN_QUEUE "Print report of all the patients in queue"
#define TREAT_ALL_PATIENTS "Treats all the patients"
#define ALL_PATIENTS_BY_DOCTOR "Print out all patients by doctor"
#define HELP "Allows user to find out more information about each command"
#define ADD_PATIENTS_VIA_FILE "Bulk adds patients into the system from a file"
using namespace std;

class UserInput {
private:
    const string userOptions[10] = {ADD_PATIENT, TREAT_PATIENT, PRINT_PATIENT_INFO, PRINT_TREAT_PATIENTS, NEXT_PATIENT, ALL_PATIENTS_IN_QUEUE, TREAT_ALL_PATIENTS, ALL_PATIENTS_BY_DOCTOR, HELP, ADD_PATIENTS_VIA_FILE};
public:
    string readInput();
    static priority_queue<Patient, vector<Patient>, Priority> options(string, vector<Patient> *patients, priority_queue<Patient, vector<Patient>, Priority>);
    void inputOptions();
};


#endif //SLONE_PROJECT3_USERINPUT_H
