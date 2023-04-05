//
// Created by diogo on 16/03/2023.
//

#include "../../include/graph/Graph.h"
#include "../../include/graph/Station_Trip.h"

void Graph::addEdge(Station *src, Station *dest, string &service, double capacity) {

    src->addEdge(dest, capacity, service);
    dest->addEdge(src, capacity, service);

    srcStation.addAdj(trip);

}

const unordered_map<string, Station> &Graph::getStations() const {
    return stations;
}

void Graph::addStations(const string& name, const Station& station) {
    stations[name] = station;
}