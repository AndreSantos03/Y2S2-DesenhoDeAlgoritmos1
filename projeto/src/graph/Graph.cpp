//
// Created by diogo on 16/03/2023.
//

#include "../../include/graph/Graph.h"
#include "../../include/graph/Station_Trip.h"

void Graph::addEdge(Station *src, Station *dest,const string &service, double capacity) {

    src->addEdge(dest, capacity, service);
    dest->addEdge(src, capacity, service);


}

const unordered_map<string, Station *> Graph::getStations() const {
    return stations;
}

Station* Graph::getStation(const string &basicString) {
    return stations[basicString];
}


void Graph::addStations(Station *station) {
    stations[station->getName()] = station;
}

void Graph::addLines(const string &lineName, Station *station) {
    lines[lineName].push_back(station);
}


const unordered_map<string, vector<Station *>> &Graph::getLines() const {
    return lines;
}

Station *Graph::findStation(const string& src) {
    for (const auto &station: stations) {
        if (station.first == src) {
            return station.second;
        }
    }
    return nullptr;
}

