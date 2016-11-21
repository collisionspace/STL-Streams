//
// Created by James Slone on 10/28/16.
//

#ifndef INCLASS_PATIENT_H
#define INCLASS_PATIENT_H
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Patient {
private:
    int id;
    static int idCount;
    string firstName;
    string middleName;
    string lastName;
    string suffix;
    vector<string> ailments;
    string doctor;
    bool treated;
    int priority;
public:
    Patient(const string &firstName, const string &middleName, const string &lastName, const string &suffix,
            const vector<string> &ailment, const string &doctor, bool treated, int priority);
    const string &getFirstName() const;
    void setFirstName(const string &firstName);
    const string &getMiddleName() const;
    void setMiddleName(const string &middleName);
    const string &getLastName() const;
    void setLastName(const string &lastName);
    const string &getSuffix() const;
    void setSuffix(const string &suffix);
    const vector<string> &getAilment() const;
    void setAilment(const vector<string> &ailment);
    const string &getDoctor() const;
    void setDoctor(const string &doctor);
    bool isTreated() const;
    void setTreated(bool treated);
    int getPriority() const;
    void setPriority(int priority);
    int getID() const;
    void outputPatient() const;
    bool operator<(const Patient &rhs) const { return doctor < rhs.doctor; }
};

struct lessThan {
    inline bool operator() (const Patient& lhs, const Patient& rhs) {
        return lhs.getID() < rhs.getID();
    }
};

#endif //INCLASS_PATIENT_H
