#include "patients.h"

Patient::Patient(const string& name, int id)
    : name(name), id(id) {}

const string& Patient::getName() const {
    return name;
}

int Patient::getId() const {
    return id;
}
