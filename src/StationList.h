#ifndef STATIONLIST_H
#define STATIONLIST_H

#include "StationData.h"
#include <iostream>

class StationList {
private:
    struct Node {
        Station data;
        Node* next;
        Node(const Station& newData, Node* nextNode = nullptr) : data(newData), next(nextNode) {}
    };

    Node* head;

public:
    StationList() : head(nullptr) {}
    ~StationList();
    void append(const Station& data);
    void display() const;  // Display all data for debugging or other purposes
};

#endif // STATIONLIST_H
