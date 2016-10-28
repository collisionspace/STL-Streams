//
// Created by James Slone on 10/28/16.
//

#include "Utilities.h"

vector<string> Utilities::split(string line) {
    std::vector<std::string> array;
    std::size_t pos = 0, found;
    while((found = line.find_first_of(':', pos)) != std::string::npos) {
        array.push_back(line.substr(pos, found - pos));
        pos = found+1;
    }
    array.push_back(line.substr(pos));
    return array;
}

void Utilities::read(vector<Patient> *patients) {
    std::ifstream infile(TXT_PATH);
    std::string line;
    typedef std::multimap<string, string> mapType1;
    mapType1 patientMap;

    while (std::getline(infile, line)) {
        if(line != "") {
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
    for (multimap<string,string>::iterator it= patientMap->begin(); it != patientMap->end(); ++it) {
        if(it->first == "ailment") {
            ailments.push_back(it->second);
        }
    }
    string doctor = patientMap->find("doctor")->second;
    string firstName = patientMap->find("firstName")->second;
    string lastName = patientMap->find("lastName")->second;
    string middleName = patientMap->find("middleName")->second;
    int priority = stoi(patientMap->find("priority")->second);
    string suffix = patientMap->find("suffix")->second;
    bool treated = stoi(patientMap->find("treated")->second);
    patientMap->clear();
    return Patient(firstName,middleName,lastName,suffix,ailments,doctor,treated,priority);
}