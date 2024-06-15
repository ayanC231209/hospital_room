#include "room_reservation.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void displayMenu() {
    cout << "Hospital Room Reservation System\n";
    cout << "1. Add Reservation\n";
    cout << "2. Remove Reservation\n";
    cout << "3. Find Reservation\n";
    cout << "4. Display All Reservations\n";
    cout << "5. Display Available Rooms\n";
    cout << "6. Display Occupied Rooms\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    vector<int> rooms = {101, 102, 103, 104, 105}; // Example room numbers
    RoomReservation system(rooms);

    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                int id, roomNumber;
                cout << "Enter Patient Name: ";
                cin.ignore(); // to clear the newline character from the input buffer
                getline(cin, name);
                cout << "Enter Patient ID: ";
                cin >> id;
                cout << "Enter Room Number: ";
                cin >> roomNumber;
                system.addReservation(name, id, roomNumber);
                break;
            }
            case 2: {
                int id;
                cout << "Enter Patient ID to remove: ";
                cin >> id;
                system.removeReservation(id);
                break;
            }
            case 3: {
                int id;
                cout << "Enter Patient ID to find: ";
                cin >> id;
                system.findReservation(id);
                break;
            }
            case 4:
                system.displayAllReservations();
                break;
            case 5:
                system.displayAvailableRooms();
                break;
            case 6:
                system.displayOccupiedRooms();
                break;
            case 7:
                cout << "Exiting the system." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
