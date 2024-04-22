#include "EVStationTree.h"
#include "StationList.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <set>

std::map<std::string, std::map<std::string, std::set<Station>>> stateCityStations;
std::map<std::string, std::set<Station>> stationsByZip;
std::map<std::string, std::map<std::string, int>> stationCountByFuelType;
std::set<std::string> fuelTypes;

void loadStationsData(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    getline(file, line); // Skip the header
    while (getline(file, line)) {
        std::stringstream ss(line);
        Station station;
        getline(ss, station.name, ',');
        getline(ss, station.address, ',');
        getline(ss, station.city, ',');
        getline(ss, station.state, ',');
        getline(ss, station.zip, ',');
        getline(ss, station.fuelType, ',');

        stateCityStations[station.state][station.city].insert(station);
        stationsByZip[station.zip].insert(station);
        stationCountByFuelType[station.fuelType][station.state]++;
        fuelTypes.insert(station.fuelType);
    }
    file.close();
}

void displayStates() {
    for (const auto& state : stateCityStations) {
        std::cout << state.first << std::endl;
    }
}

void displayCitiesFromState(const std::string& state) {
    if (stateCityStations.find(state) == stateCityStations.end()) {
        std::cout << "No cities found for this state." << std::endl;
        return;
    }
    for (const auto& city : stateCityStations[state]) {
        std::cout << city.first << std::endl;
    }
}

void displayStationsFromCity(const std::string& state, const std::string& city) {
    if (stateCityStations[state].find(city) == stateCityStations[state].end()) {
        std::cout << "No stations found for this city." << std::endl;
        return;
    }
    for (const auto& station : stateCityStations[state][city]) {
        std::cout << "Station Name: " << station.name << ", Address: " << station.address << std::endl;
    }
}

void displayFuelTypeOptions() {
    for (const auto& fuelType : fuelTypes) {
        std::cout << fuelType << std::endl;
    }
}

void displayStationCountByFuelType(const std::string& fuelType) {
    if (stationCountByFuelType.find(fuelType) == stationCountByFuelType.end()) {
        std::cout << "No stations found for this fuel type." << std::endl;
        return;
    }
    for (const auto& pair : stationCountByFuelType[fuelType]) {
        std::cout << "State: " << pair.first << ", Number of Stations: " << pair.second << std::endl;
    }
}

void displayStationsFromZip(const std::string& zip) {
    if (stationsByZip.find(zip) == stationsByZip.end()) {
        std::cout << "No stations found for this ZIP code." << std::endl;
        return;
    }
    for (const auto& station : stationsByZip[zip]) {
        std::cout << "Station Name: " << station.name << ", Address: " << station.address << std::endl;
    }
}

int main() {
    std::string filename = "../data/EV_Charging_Data.csv";
    loadStationsData(filename);

    std::string selectedState, selectedCity, selectedZip, selectedFuelType;
    int choice;

    do {
        std::cout << "Choose an option:\n"
                  << "1. Display stations by state and city\n"
                  << "2. Display station count by fuel type\n"
                  << "3. Display station details by ZIP code\n"
                  << "4. Exit\n";
        std::cin >> choice;

        switch (choice) {
            case 1:
                displayStates();
                std::cout << "Select State: ";
                std::cin >> selectedState;
                displayCitiesFromState(selectedState);
                std::cout << "Select City: ";
                std::cin >> selectedCity;
                displayStationsFromCity(selectedState, selectedCity);
                break;
            case 2:
                displayFuelTypeOptions();
                std::cout << "Select Fuel Type: ";
                std::cin >> selectedFuelType;
                displayStationCountByFuelType(selectedFuelType);
                break;
            case 3:
                std::cout << "Enter ZIP code: ";
                std::cin >> selectedZip;
                displayStationsFromZip(selectedZip);
                break;
            case 4:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
