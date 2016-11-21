//
// Created by James Slone on 10/28/16.
//

#include "Utilities.h"

vector<string> Utilities::split(string line) {
    std::vector<std::string> array;
    std::size_t pos = 0, found;
    while((found = line.find_first_of(SPLIT_CHAR, pos)) != std::string::npos) {
        array.push_back(line.substr(pos, found - pos));
        pos = found+1;
    }
    array.push_back(line.substr(pos));
    return array;
}

void Utilities::read(vector<Patient> *patients, string path) {
    std::ifstream infile(path);
    std::string line;
    typedef std::multimap<string, string> mapType1;
    mapType1 patientMap;

    while (std::getline(infile, line)) {
        if(line != EMPTY_STR) {
            vector<string> patientParse = Utilities::split(line);
            patientMap.insert(mapType1::value_type(patientParse[0], patientParse[1]));
        }
        else {
            patients->push_back(createPatient(&patientMap));
        }
    }
    patients->push_back(createPatient(&patientMap));
}

Patient Utilities::createPatient(std::multimap<string, string> *patientMap) {
    std::vector<string> ailments;

    //gets all the ailments from the said patient and puts it into a vector of strings
    for (multimap<string,string>::iterator it= patientMap->begin(); it != patientMap->end(); ++it) {
        if(it->first == KEY_AILMENT) {
            ailments.push_back(it->second);
        }
    }
    string doctor = patientMap->find(KEY_DOCTOR)->second;
    string firstName = patientMap->find(KEY_FIRST_NAME)->second;
    string lastName = patientMap->find(KEY_LAST_NAME)->second;
    string middleName = patientMap->find(KEY_MIDDLE_NAME)->second;
    int priority = stoi(patientMap->find(KEY_PRIORITY)->second);
    string suffix = patientMap->find(KEY_SUFFIX)->second;
    bool treated = stoi(patientMap->find(KEY_TREATED)->second);
    patientMap->clear();
    return Patient(firstName,middleName,lastName,suffix,ailments,doctor,treated,priority);
}