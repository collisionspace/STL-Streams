//
// Created by James Slone on 10/28/16.
//

#ifndef INCLASS_UTILITIES_H
#define INCLASS_UTILITIES_H


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include "Patient.h"

#define TXT_PATH "/Users/slonej3/Desktop/projects/school/402/assignment3/patients.txt"
#define SPLIT_CHAR ':'
#define EMPTY_STR ""
#define KEY_FIRST_NAME "firstName"
#define KEY_MIDDLE_NAME "middleName"
#define KEY_LAST_NAME "lastName"
#define KEY_SUFFIX "suffix"
#define KEY_AILMENT "ailment"
#define KEY_DOCTOR "doctor"
#define KEY_TREATED "treated"
#define KEY_PRIORITY "priority"
using namespace std;

class Utilities {
public:
    static vector<string> split(string line);
    static void read(vector<Patient> *patients, string);
    static Patient createPatient(std::multimap<string, string> *patientMap);
};


#endif //INCLASS_UTILITIES_H
