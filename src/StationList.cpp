#include "StationList.h"

StationList::~StationList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void StationList::append(const Station& data) {
    Node* newNode = new Node(data, nullptr);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void StationList::display() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << "Station: " << current->data.name
                  << ", Address: " << current->data.address
                  << ", City: " << current->data.city
                  << ", State: " << current->data.state
                  << ", ZIP: " << current->data.zip
                  << ", Fuel Type: " << current->data.fuelType << std::endl;
        current = current->next;
    }
}
