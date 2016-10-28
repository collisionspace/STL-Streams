//
// Created by James Slone on 10/28/16.
//

#include "Patient.h"

Patient::Patient(const string &firstName, const string &middleName, const string &lastName, const string &suffix,
                 const vector<string> &ailment, const string &doctor, bool treated, int priority) : firstName(
        firstName), middleName(middleName), lastName(lastName), suffix(suffix), ailment(ailment), doctor(doctor),
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
    return ailment;
}

void Patient::setAilment(const vector<string> &ailment) {
    Patient::ailment = ailment;
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
