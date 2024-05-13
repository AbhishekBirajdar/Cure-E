#include "DataLoader.h"
#include <fstream>
#include <sstream>

DataLoader::DataLoader(const std::string& file) : filename(file) {}

std::vector<DataEntry> DataLoader::loadData() {
    std::vector<DataEntry> data;
    std::ifstream file(filename);
    std::string line;

    // Skip header line
    std::getline(file, line);

    // Read data line by line
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        DataEntry entry;

        std::getline(ss, entry.fuelType, ',');
        std::getline(ss, entry.stationName, ',');
        std::getline(ss, entry.streetAddress, ',');
        std::getline(ss, entry.city, ',');
        std::getline(ss, entry.state, ',');
        std::getline(ss, entry.zip, ',');
        std::getline(ss, entry.dateLastConfirmed, ',');
        std::getline(ss, entry.id, ',');
        std::getline(ss, entry.updated, ',');
        std::getline(ss, entry.ownerTypeCode, ',');
        std::getline(ss, entry.openDate, ',');
        std::getline(ss, entry.ngVehicleClass, ',');
        std::getline(ss, entry.accessCode, ',');
        std::getline(ss, entry.accessDetailCode, ',');
        std::getline(ss, entry.facilityType, ',');
        std::getline(ss, entry.cngFillTypeCode);

        data.push_back(entry);
    }

    file.close();
    return data;
}
