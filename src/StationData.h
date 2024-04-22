#ifndef STATIONDATA_H
#define STATIONDATA_H

#include <string>

struct Station {
    std::string name;
    std::string address;
    std::string city;
    std::string state;
    std::string zip;
    std::string fuelType;

    // Define operator < for sorting within sets
    bool operator<(const Station& other) const {
        return name < other.name;  // Sort primarily by name
    }
};

#endif // STATIONDATA_H
