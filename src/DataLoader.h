#ifndef DATALOADER_H
#define DATALOADER_H

#include <string>
#include <vector>
#include "DataEntry.h"

class DataLoader {
public:
    DataLoader(const std::string& file); // Constructor declaration

    std::vector<DataEntry> loadData(); // Method declaration

private:
    std::string filename; // Member variable declaration
};

#endif // DATALOADER_H
