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



    unordered_map<string, Station> stations;



    void addTrip(string &src, string &dest, string &service, double capacity);


    static double getDistance(double lat1, double lon1, double lat2, double lon2);


    double getDistanceAirports(const string& src, const string& dest);

    void bfs(const string& air);

    void dijkstra(const string& air, vector<string> airlinesV);

};

#endif //PROJETODA_GRAPH_H
