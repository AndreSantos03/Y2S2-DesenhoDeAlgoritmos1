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
#include <bits/stdc++.h>
#include "Station_Trip.h"
#include "../Utils.h"


using namespace std;

class Graph {
public:

    void addStations(Station *station);

    unordered_map<string, Station *> getStations() const;

    Station *getStation(const string &basicString);

    static void addEdge(Station *src, Station *dest,const string &service, double capacity);

    static void removeEdge(Station *source, Station *destination);

    const unordered_map<string, vector<Station *>> &getLines() const;

    void addLines(const string &lineName, Station *station);

    Station *findStation(const string& src);

    vector<string> dijkstra(Station *src, Station *dest);

    int maxFlow(Station* src, Station* dest);

    bool bfsEdmondsKarp(Station* src, Station* dest);

    vector<pair<string, int>> top_k_max_flow_district(int k);

    vector<pair<string, int>> top_k_max_flow_municipality(int k);

    int maxTrains(const string& stationName);

    pair<int, int> minCost(Station *src, Station *dest);

    static int findCost(const Trip& trip);

private:

    unordered_map<string, Station*> stations;
    unordered_map<string, vector<Station*>> lines;

};

#endif //PROJETODA_GRAPH_H
