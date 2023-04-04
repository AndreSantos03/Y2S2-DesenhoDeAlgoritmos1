//
// Created by diogo on 16/03/2023.
//

#include "../../include/graph/Graph.h"

void Graph::addTrip(string &src, string &dest, string &service, double capacity) {

    Station &srcStation = stations[src];
    Trip trip = Trip(src,dest, capacity, service);

    srcStation.addAdj(trip);

}

const unordered_map<string, Station> &Graph::getStations() const {
    return stations;
}

void Graph::addStations(const string& name, const Station& station) {
    stations[name] = station;
}