#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H

#include <vector>
#include "DataEntry.h"

class DataProcessor {
public:
    static void listStationsInState(const std::vector<DataEntry>& data, const std::string& state);
    static void listStationsOpenedInYear(const std::vector<DataEntry>& data, int year);
    static int countStationsWithFuelType(const std::vector<DataEntry>& data, const std::string& fuelType);
    static void listStationsByZip(const std::vector<DataEntry>& data, const std::string& zipCode);
    static void countPublicPrivateStations(const std::vector<DataEntry>& data, const std::string& state);
};

#endif // DATAPROCESSOR_H
