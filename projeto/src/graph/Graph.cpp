//
// Created by diogo on 16/03/2023.
//

#include "../../include/graph/Graph.h"

void Graph::addTrip(string &src, string &dest, string &service, double capacity) {

    Station &srcStation = stations[src];
    Trip trip = Trip(dest, capacity, service);

    srcStation.addAdj(trip);

}
