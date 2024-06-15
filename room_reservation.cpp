#include "room_reservation.h"
#include <iostream>

RoomReservation::RoomReservation(const vector<int>& rooms) {
    initializeAvailableRooms(rooms);
}

void RoomReservation::initializeAvailableRooms(const vector<int>& rooms) {
    for (int room : rooms) {
        availableRooms.insert(room);
    }
}

void RoomReservation::addReservation(const string& name, int id, int roomNumber) {
    if (availableRooms.find(roomNumber) == availableRooms.end()) {
        cout << "Room number " << roomNumber << " is not available." << endl;
        return;
    }
    Patient patient(name, id);
    reservationTree.insert(patient, roomNumber);
    availableRooms.erase(roomNumber);
}

void RoomReservation::removeReservation(int patientId) {
    int roomNumber;
    string name;
    if (reservationTree.find(patientId, roomNumber, name)) {
        reservationTree.remove(patientId);
        availableRooms.insert(roomNumber);
    } else {
        cout << "Patient ID " << patientId << " not found." << endl;
    }
}

void RoomReservation::findReservation(int patientId) const {
    int roomNumber;
    string name;
    if (reservationTree.find(patientId, roomNumber, name)) {
        cout << "Patient Name: " << name << ", ID: " << patientId << " has room number: " << roomNumber << endl;
    } else {
        cout << "No reservation found for patient ID: " << patientId << endl;
    }
}

void RoomReservation::displayAllReservations() const {
    reservationTree.display();
}

void RoomReservation::displayAvailableRooms() const {
    cout << "Available Rooms: ";
    for (int room : availableRooms) {
        cout << room << " ";
    }
    cout << endl;
}

void RoomReservation::displayOccupiedRooms() const {
    vector<int> occupiedRooms = reservationTree.getOccupiedRooms();
    cout << "Occupied Rooms: ";
    for (int room : occupiedRooms) {
        cout << room << " ";
    }
    cout << endl;
}
