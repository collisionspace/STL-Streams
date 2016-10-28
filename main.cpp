#include <iostream>
#include <vector>
#include "Patient.h"
#include "Utilities.h"
using namespace std;

int main() {
    vector<Patient> patients;
    Utilities::read(&patients);
    return 0;
}