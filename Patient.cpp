//
// Created by James Slone on 10/28/16.
//

#include <iostream>
#include "Patient.h"


int Patient::idCount = 0;
Patient::Patient(const string &firstName, const string &middleName, const string &lastName, const string &suffix,
                 const vector<string> &ailments, const string &doctor, bool treated, int priority) : id(++idCount), firstName(
        firstName), middleName(middleName), lastName(lastName), suffix(suffix), ailments(ailments), doctor(doctor),
                                                                                                    treated(treated),
                                                                                                    priority(
                                                                                                            priority) {}

const string &Patient::getFirstName() const {
    return firstName;
}

void Patient::setFirstName(const string &firstName) {
    Patient::firstName = firstName;
}

const string &Patient::getMiddleName() const {
    return middleName;
}

void Patient::setMiddleName(const string &middleName) {
    Patient::middleName = middleName;
}

const string &Patient::getLastName() const {
    return lastName;
}

void Patient::setLastName(const string &lastName) {
    Patient::lastName = lastName;
}

const string &Patient::getSuffix() const {
    return suffix;
}

void Patient::setSuffix(const string &suffix) {
    Patient::suffix = suffix;
}

const vector<string> &Patient::getAilment() const {
    return ailments;
}

void Patient::setAilment(const vector<string> &ailment) {
    Patient::ailments = ailment;
}

const string &Patient::getDoctor() const {
    return doctor;
}

void Patient::setDoctor(const string &doctor) {
    Patient::doctor = doctor;
}

bool Patient::isTreated() const {
    return treated;
}

void Patient::setTreated(bool treated) {
    Patient::treated = treated;
}

int Patient::getPriority() const {
    return priority;
}

void Patient::setPriority(int priority) {
    Patient::priority = priority;
}

int Patient::getID() const {
    return id;
}

void Patient::outputPatient() const {
    cout << "Patient id: " << id << endl;
    cout << "First Name: " << firstName << endl;
    cout << "Middle Name: " << middleName << endl;
    cout << "Last Name: " << lastName << endl;
    cout << "Suffix: " << suffix << endl;
    for(string const &ailment : ailments) {
        cout << "Ailment: " << ailment << endl;
    }
    cout << "Doctor: " << doctor << endl;
    cout << "Treated: " << treated << endl;
    cout << "Priority: " << priority << "\n\n" << endl;
}