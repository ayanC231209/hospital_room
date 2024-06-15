#ifndef PATIENT_H
#define PATIENT_H

#include <string>

using namespace std;

class Patient {
public:
    Patient(const string& name = "", int id = 0);

    const string& getName() const;
    int getId() const;

private:
    string name;
    int id;
};

#endif // PATIENT_H
