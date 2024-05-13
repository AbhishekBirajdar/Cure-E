#ifndef MENU_H
#define MENU_H

#include <vector>
#include "DataEntry.h"

class Menu {
public:
    static void showMainMenu();
    static void processMainMenuOption(const std::vector<DataEntry>& data, int option);
    static void processSubMenuOption(const std::vector<DataEntry>& data, int option);
};

#endif // MENU_H
