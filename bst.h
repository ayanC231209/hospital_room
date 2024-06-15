#ifndef BST_H
#define BST_H

#include "patients.h"
#include <iostream>
#include <vector>

using namespace std;

class BST {
public:
    BST();
    ~BST();
    void insert(const Patient& patient, int roomNumber);
    bool find(int patientId, int& roomNumber, string& name) const;
    void remove(int patientId);
    void display() const;
    vector<int> getOccupiedRooms() const;

private:
    struct Node {
        Patient patient;
        int roomNumber;
        Node* left;
        Node* right;
        Node(const Patient& p, int room, Node* l = nullptr, Node* r = nullptr)
            : patient(p), roomNumber(room), left(l), right(r) {}
    };

    Node* root;

    void insert(Node*& node, const Patient& patient, int roomNumber);
    bool find(Node* node, int patientId, int& roomNumber, string& name) const;
    void remove(Node*& node, int patientId);
    Node* findMin(Node* node) const;
    void destroy(Node* node);
    void display(Node* node) const;
    void getOccupiedRooms(Node* node, vector<int>& rooms) const;
};

#endif // BST_H
