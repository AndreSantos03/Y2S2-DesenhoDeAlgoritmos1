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
#include "../Utils.h"


using namespace std;

class Graph {
public:

    void addStations(Station *station);

    const unordered_map<string, Station *> getStations() const;

    Station *getStation(const string &basicString);

    void addEdge(Station *src, Station *dest,const string &service, double capacity);

    const unordered_map<string, vector<Station *>> &getLines() const;

    void addLines(const string &lineName, Station *station);

    Station *findStation(const string& src);

    vector<string> dijkstra(Station *src, Station *dest);

    int maxFlow(Station* src, Station* dest);

    bool bfsEdmondsKarp(Station* src, Station* dest);

private:

    unordered_map<string, Station*> stations;
    unordered_map<string, vector<Station*>> lines;

};

#endif //PROJETODA_GRAPH_H
