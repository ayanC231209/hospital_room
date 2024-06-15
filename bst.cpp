#include "bst.h"
#include <stdexcept>

BST::BST() : root(nullptr) {}

BST::~BST() {
    destroy(root);
}

void BST::insert(const Patient& patient, int roomNumber) {
    insert(root, patient, roomNumber);
}

bool BST::find(int patientId, int& roomNumber, string& name) const {
    return find(root, patientId, roomNumber, name);
}

void BST::remove(int patientId) {
    remove(root, patientId);
}

void BST::display() const {
    display(root);
}

void BST::insert(Node*& node, const Patient& patient, int roomNumber) {
    if (node == nullptr) {
        node = new Node(patient, roomNumber);
    } else if (patient.getId() < node->patient.getId()) {
        insert(node->left, patient, roomNumber);
    } else if (patient.getId() > node->patient.getId()) {
        insert(node->right, patient, roomNumber);
    } else {
        throw invalid_argument("Patient with the same ID already exists.");
    }
}

bool BST::find(Node* node, int patientId, int& roomNumber, string& name) const {
    if (node == nullptr) {
        return false;
    } else if (patientId < node->patient.getId()) {
        return find(node->left, patientId, roomNumber, name);
    } else if (patientId > node->patient.getId()) {
        return find(node->right, patientId, roomNumber, name);
    } else {
        roomNumber = node->roomNumber;
        name = node->patient.getName();
        return true;
    }
}

void BST::remove(Node*& node, int patientId) {
    if (node == nullptr) {
        return;
    } else if (patientId < node->patient.getId()) {
        remove(node->left, patientId);
    } else if (patientId > node->patient.getId()) {
        remove(node->right, patientId);
    } else {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        } else if (node->left == nullptr) {
            Node* temp = node;
            node = node->right;
            delete temp;
        } else if (node->right == nullptr) {
            Node* temp = node;
            node = node->left;
            delete temp;
        } else {
            Node* temp = findMin(node->right);
            node->patient = temp->patient;
            node->roomNumber = temp->roomNumber;
            remove(node->right, temp->patient.getId());
        }
    }
}

BST::Node* BST::findMin(Node* node) const {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

void BST::destroy(Node* node) {
    if (node != nullptr) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

void BST::display(Node* node) const {
    if (node != nullptr) {
        display(node->left);
        cout << "Patient Name: " << node->patient.getName()
             << ", ID: " << node->patient.getId()
             << ", Room Number: " << node->roomNumber << endl;
        display(node->right);
    }
}

vector<int> BST::getOccupiedRooms() const {
    vector<int> rooms;
    getOccupiedRooms(root, rooms);
    return rooms;
}

void BST::getOccupiedRooms(Node* node, vector<int>& rooms) const {
    if (node != nullptr) {
        getOccupiedRooms(node->left, rooms);
        rooms.push_back(node->roomNumber);
        getOccupiedRooms(node->right, rooms);
    }
}
