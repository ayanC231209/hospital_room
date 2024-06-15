#ifndef ROOM_RESERVATION_H
#define ROOM_RESERVATION_H

#include "patients.h"
#include "bst.h"
#include <vector>
#include <unordered_set>

using namespace std;

class RoomReservation {
public:
    RoomReservation(const vector<int>& rooms);
    void addReservation(const string& name, int id, int roomNumber);
    void removeReservation(int patientId);
    void findReservation(int patientId) const;
    void displayAllReservations() const;
    void displayAvailableRooms() const;
    void displayOccupiedRooms() const;

private:
    BST reservationTree;
    unordered_set<int> availableRooms;
    void initializeAvailableRooms(const vector<int>& rooms);
};

#endif // ROOM_RESERVATION_H
