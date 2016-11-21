//
// Created by James Slone on 10/28/16.
//

#ifndef SLONE_PROJECT3_USERINPUT_H
#define SLONE_PROJECT3_USERINPUT_H

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "Patient.h"
#include "PriorityQueue.h"
#include "Logger.h"

#define ADD_PATIENT "Add patient to the system"
#define ADD_PATIENT_HELP "Add a patient to the system by entering info the system prompts you for."
#define TREAT_PATIENT "Treat the next patient that is in priority"
#define TREAT_PATIENT_HELP "This will treat the next patient that is in the priority queue and then place the person in the treated section"
#define PRINT_PATIENT_INFO "Print patient info"
#define PRINT_PATIENT_INFO_HELP "Print all the patients that are either currently in the queue or have been treated"
#define PRINT_TREAT_PATIENTS "Print report of treated patients"
#define PRINT_TREAT_PATIENTS_HELP "Prints a report of all the treated patients so far"
#define NEXT_PATIENT "Next patient to be treated"
#define NEXT_PATIENT_HELP "This will print out the patient that is next to be treated"
#define ALL_PATIENTS_IN_QUEUE "Print report of all the patients in queue"
#define ALL_PATIENTS_IN_QUEUE_HELP "Prints out an report of every single patient that is currently in queue"
#define TREAT_ALL_PATIENTS "Treats all the patients"
#define TREAT_ALL_PATIENTS_HELP "Treats all the patients that are currently waiting in the queue"
#define ALL_PATIENTS_BY_DOCTOR "Print out all patients by doctor"
#define ALL_PATIENTS_BY_DOCTOR_HELP "Prints out all the patients by alphabetical order of their doctor"
#define HELP "Find out more information about each command"
#define HELP_HELPS "Gives more info about what every command does"
#define ADD_PATIENTS_VIA_FILE "Bulk adds patients into the system from a file"
#define ADD_PATIENTS_VIA_FILE_HELP "Adds multiple patients all at once from a txt file that the user supplies and this will store all the patients in the queue"
#define QUIT "Quit"
#define Option_Size 11

using namespace std;

class UserInput {
private:
    const string userOptions[Option_Size] = {ADD_PATIENT, TREAT_PATIENT, PRINT_PATIENT_INFO, PRINT_TREAT_PATIENTS, NEXT_PATIENT, ALL_PATIENTS_IN_QUEUE, TREAT_ALL_PATIENTS, ALL_PATIENTS_BY_DOCTOR, HELP, ADD_PATIENTS_VIA_FILE, QUIT};
    const string helpPrompt[Option_Size-1] = {ADD_PATIENT_HELP, TREAT_PATIENT_HELP, PRINT_PATIENT_INFO_HELP, PRINT_TREAT_PATIENTS_HELP, NEXT_PATIENT_HELP, ALL_PATIENTS_IN_QUEUE_HELP, TREAT_ALL_PATIENTS_HELP, ALL_PATIENTS_BY_DOCTOR_HELP, HELP_HELPS, ADD_PATIENTS_VIA_FILE_HELP};
public:
    string readInput();
    string userInput();
    void options(string, vector<Patient> *treatedPatients, priority_queue<Patient, vector<Patient>, Priority> *pQueue);
    void inputOptions();
    Patient readInPatient();
    void outputAllPatients(vector<Patient> *patients);
    vector<Patient> patientsWaiting(priority_queue<Patient, vector<Patient>, Priority> pQueue);
    void treatAllPatients(vector<Patient> *treatedPatients, priority_queue<Patient, vector<Patient>, Priority> *priorityQ);
    Patient treatPatient(priority_queue<Patient, vector<Patient>, Priority> *priorityQ);
    void outputByDoctor(vector<Patient> *treatedPatients, priority_queue<Patient, vector<Patient>, Priority> *pQueue);
    vector<Patient> merge(vector<Patient> *treatedPatients, priority_queue<Patient, vector<Patient>, Priority> *pQueue);
    void help();
};


#endif //SLONE_PROJECT3_USERINPUT_H
