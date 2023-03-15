//
// Created by diogo on 15/03/2023.
//

#ifndef PROJETODA_READDATA_H
#define PROJETODA_READDATA_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iterator>
//#include "../graph/Graph.h"

using namespace std;

class ReadData {
public:
    ReadData();

    void readNetworkCSV(const string& filename);

    void readStationsCSV(const string& filename);

};

#endif //PROJETODA_READDATA_H
