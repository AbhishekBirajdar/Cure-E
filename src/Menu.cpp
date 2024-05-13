// In Menu.cpp
#include "Menu.h"
#include "DataProcessor.h"
#include <iostream>
#include <iomanip> // Include for std::setw

void Menu::showMainMenu() {
    std::cout << "\033[1;36m"; // Set text color to cyan
    std::cout << R"(
            |      |  -----------------
            |      |         | 
            |      |         | 
            |------|         |
            |      |         | 
            |      |         |
            |      |   --------------




    )" << std::endl;
    std::cout << "\033[0m"; // Reset text color
    std::cout << "            Welcome to the Fuel Station Information System!\n\n         ";
    std::cout << "                     Main Menu:\n                  ";
    std::cout << "      \033[1;32m1. List stations in a state\033[0m\n"                     ; // Set text color to green
    std::cout << "                     \033[1;33m2. List stations opened in a year\033[0m\n"                     ; // Set text color to yellow
    std::cout << "                     \033[1;34m3. Count stations with fuel type ELEC\033[0m\n"                     ; // Set text color to blue
    std::cout << "                     \033[1;35m4. List stations by ZIP code\033[0m\n"                     ; // Set text color to magenta
    std::cout << "                     \033[1;36m5. Count public and private stations in a state\033[0m\n                     "; // Set text color to cyan
    std::cout << "                     \033[1;31m6. Exit\033[0m\n"                     ; // Set text color to red
    std::cout << "Choose an option: ";
}

void Menu::processMainMenuOption(const std::vector<DataEntry>& data, int option) {
    switch (option) {
        case 1: {
            std::string state;
            std::cout << "Enter state abbreviation (e.g., NY, CA): ";
            std::cin >> state;
            DataProcessor::listStationsInState(data, state);
            break;
        }
        case 2: {
            int year;
            std::cout << "Enter the year: ";
            std::cin >> year;
            DataProcessor::listStationsOpenedInYear(data, year);
            break;
        }
        case 3: {
            int count = DataProcessor::countStationsWithFuelType(data, "ELEC");
            std::cout << "Total stations with fuel type ELEC: " << count << std::endl;
            break;
        }
        case 4: {
            std::string zip;
            std::cout << "Enter ZIP code: ";
            std::cin >> zip;
            DataProcessor::listStationsByZip(data, zip);
            break;
        }
        case 5: {
            std::string state;
            std::cout << "Enter state abbreviation (e.g., NY, CA): ";
            std::cin >> state;
            DataProcessor::countPublicPrivateStations(data, state);
            break;
        }
        case 6:
            std::cout << "Exiting the program.\n";
            break;
        default:
            std::cout << "Invalid option. Please try again.\n";
    }
}
