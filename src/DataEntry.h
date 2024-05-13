#ifndef DATAENTRY_H
#define DATAENTRY_H

#include <string>

struct DataEntry {
    std::string fuelType;
    std::string stationName;
    std::string streetAddress;
    std::string city;
    std::string state;
    std::string zip;
    std::string ngFillTypeCode;
    std::string dateLastConfirmed;
    std::string id;
    std::string updated;
    std::string ownerTypeCode;
    std::string openDate;
    std::string ngVehicleClass;
    std::string accessCode;
    std::string accessDetailCode;
    std::string facilityType;
    std::string cngFillTypeCode;
};

#endif // DATAENTRY_H
