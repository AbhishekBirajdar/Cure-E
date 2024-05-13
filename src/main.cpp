#include "Menu.h"
#include "DataLoader.h"
#include <iostream>
#include <limits> // Include for std::numeric_limits

int main() {
    std::string filename = "alt_fuel_stations.csv"; // Specify the name of your CSV file here

    DataLoader dataLoader(filename); // Create an instance of DataLoader with the filename
    std::vector<DataEntry> data = dataLoader.loadData(); // Call the loadData method on the DataLoader instance

    int option;
    do {
        Menu::showMainMenu();
        std::cin >> option;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\033[1;31mInvalid input. Please enter a valid option.\033[0m\n";
            continue; // Continue the loop to display the menu again
        }
        Menu::processMainMenuOption(data, option);
    } while (option != 6);

    return 0;
}
