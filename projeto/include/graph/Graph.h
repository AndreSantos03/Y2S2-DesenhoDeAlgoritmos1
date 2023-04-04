//
// Created by diogo on 16/03/2023.
//

#ifndef PROJETODA_GRAPH_H
#define PROJETODA_GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include "Station_Trip.h"


using namespace std;

class Graph {
public:

    const unordered_map<string, Station> &getStations() const;

    void addStations(const string& name, const Station& station);

    void addTrip(string &src, string &dest, string &service, double capacity);

private:

    unordered_map<string, Station> stations;

};

#endif //PROJETODA_GRAPH_H
