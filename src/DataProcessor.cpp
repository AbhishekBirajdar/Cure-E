#include "DataProcessor.h"
#include <iostream>
#include <algorithm>

void DataProcessor::listStationsInState(const std::vector<DataEntry>& data, const std::string& state) {
    std::cout << "Stations in " << state << ":\n";
    for (const auto& entry : data) {
        if (entry.state == state) {
            std::cout << "Station Name: " << entry.stationName << ", Address: " << entry.streetAddress << ", City: " << entry.city << std::endl;
        }
    }
}

void DataProcessor::listStationsOpenedInYear(const std::vector<DataEntry>& data, int year) {
    std::cout << "Stations opened in " << year << ":\n";
    for (const auto& entry : data) {
        // Extract year from openDate field
        std::string::size_type pos = entry.openDate.find_last_of('/');
        if (pos != std::string::npos && entry.openDate.length() >= 5) {
            int entryYear = std::stoi(entry.openDate.substr(pos + 1));
            if (entryYear == year) {
                std::cout << "Station Name: " << entry.stationName << ", Address: " << entry.streetAddress << ", City: " << entry.city << std::endl;
            }
        }
    }
}

int DataProcessor::countStationsWithFuelType(const std::vector<DataEntry>& data, const std::string& fuelType) {
    int count = 0;
    for (const auto& entry : data) {
        if (entry.fuelType == fuelType) {
            count++;
        }
    }
    return count;
}

void DataProcessor::listStationsByZip(const std::vector<DataEntry>& data, const std::string& zipCode) {
    std::cout << "Stations in ZIP code " << zipCode << ":\n";
    for (const auto& entry : data) {
        if (entry.zip == zipCode) {
            std::cout << "Station Name: " << entry.stationName << ", Address: " << entry.streetAddress << ", City: " << entry.city << std::endl;
        }
    }
}

void DataProcessor::countPublicPrivateStations(const std::vector<DataEntry>& data, const std::string& state) {
    int publicCount = 0;
    int privateCount = 0;
    for (const auto& entry : data) {
        if (entry.state == state) {
            if (entry.accessCode == "public") {
                publicCount++;
            } else if (entry.accessCode == "private") {
                privateCount++;
            }
        }
    }
    std::cout << "Public stations in " << state << ": " << publicCount << ", Private stations: " << privateCount << std::endl;
}
