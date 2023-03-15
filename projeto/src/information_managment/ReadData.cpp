//
// Created by diogo on 15/03/2023.
//

#include "../../include/information_managment/ReadData.h"


ReadData::ReadData() {

    readNetworkCSV("../project/data/airlines.csv");
    readStationsCSV("../project/data/airports.csv");

}