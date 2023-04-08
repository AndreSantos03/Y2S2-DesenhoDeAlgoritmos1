#include <utility>
#include "../../include/graph/Station_Trip.h"

Station::Station(string name, string district, string municipality,
                 string township, string line) : name(std::move(name)), district(std::move(district)), municipality(std::move(municipality)), township(std::move(township)), line(std::move(line)) {}

void Station::addEdge(Station *dest, double capacity, const string &service) {
    Trip *trip = new Trip(this, dest, capacity, service);
    Trip *incomingtrip = new Trip(dest, this, capacity, service);
    edges.push_back(trip);
    dest->getIncoming().push_back(incomingtrip);
}

const string &Station::getName() const {
    return name;
}

const string &Station::getDistrict() const {
    return district;
}

const string &Station::getMunicipality() const {
    return municipality;
}

const string &Station::getTownship() const {
    return township;
}

const string &Station::getLine() const {
    return line;
}

const vector<Trip *> &Station::getEdge() const {
    return edges;
}

vector<Trip *> &Station::getIncoming() {
    return incoming;
}

bool Station::isVisited() const {
    return visited;
}

void Station::setVisited(bool visited) {
    Station::visited = visited;
}

Trip *Station::getPath() const {
    return path;
}

void Station::setPath(Trip *path) {
    Station::path = path;
}

void Station::removeEdge(Station *destination) {
    for (int i = 0; i < edges.size();i++) {
        if (edges[i]->getDestinationStation() == destination) {
            edges.erase(edges.begin() + i);
            break;
        }
    }
}

Station::Station() = default;



/*

||||||||||||| TRIP FUNCTIONS |||||||||||||

*/



Trip::Trip(Station *sourceStation, Station *destinationStation, double capacity,
           string service) : sourceStation(sourceStation), destinationStation(destinationStation), capacity(capacity), service(std::move(service)) {}

double Trip::getCapacity() const {
    return capacity;
}

void Trip::setCapacity(double capaci) {
    Trip::capacity = capaci;
}

const string &Trip::getService() const {
    return service;
}

void Trip::setService(const string &servic) {
    Trip::service = servic;
}

Station *Trip::getSourceStation() const {
    return sourceStation;
}

void Trip::setSourceStation(Station *sourceStation) {
    Trip::sourceStation = sourceStation;
}

Station *Trip::getDestinationStation() const {
    return destinationStation;
}

void Trip::setDestinationStation(Station *destinationStation) {
    Trip::destinationStation = destinationStation;
}

Trip *Trip::getReverse() const {
    return reverse;
}

void Trip::setReverse(Trip *reverse) {
    Trip::reverse = reverse;
}

int Trip::getFlow() const {
    return flow;
}

void Trip::setFlow(int flow) {
    Trip::flow = flow;
}


