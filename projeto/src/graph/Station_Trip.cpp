#include "../../include/graph/Station_Trip.h"


Station::Station(string name, string district, string municipality,
                 string township, string line) : name(name), district(district), municipality(municipality), township(township), line(line){}


void Station::addAdj(const Trip& trip) {
    adj.push_back(trip);
}

const string &Station::getName() const {
    return name;
}

void Station::setName(const string &name) {
    Station::name = name;
}

const string &Station::getDistrict() const {
    return district;
}

void Station::setDistrict(const string &district) {
    Station::district = district;
}

const string &Station::getMunicipality() const {
    return municipality;
}

void Station::setMunicipality(const string &municipality) {
    Station::municipality = municipality;
}

const string &Station::getTownship() const {
    return township;
}

void Station::setTownship(const string &township) {
    Station::township = township;
}

const string &Station::getLine() const {
    return line;
}

void Station::setLine(const string &line) {
    Station::line = line;
}

const vector<Trip> &Station::getAdj() const {
    return adj;
}

void Station::setAdj(const vector<Trip> &adj) {
    Station::adj = adj;
}

Station::Station() = default;



/*

||||||||||||| TRIP FUNCTIONS |||||||||||||

*/



Trip::Trip(string sourceStation, string destinationStation, double capacity,
           string service) : sourceStation(sourceStation), destinationStation(destinationStation), capacity(capacity), service(service) {}

const string &Trip::getDestination() const {
    return destinationStation;
}

void Trip::setDestination(const string &destination) {
    Trip::destinationStation = destination;
}

double Trip::getCapacity() const {
    return capacity;
}

void Trip::setCapacity(double capacity) {
    Trip::capacity = capacity;
}

const string &Trip::getService() const {
    return service;
}

void Trip::setService(const string &service) {
    Trip::service = service;
}

const string &Trip::getSourceStation() const {
    return sourceStation;
}

void Trip::setSourceStation(const string &sourceStation) {
    Trip::sourceStation = sourceStation;
}

const string &Trip::getDestinationStation() const {
    return destinationStation;
}

void Trip::setDestinationStation(const string &destinationStation) {
    Trip::destinationStation = destinationStation;
}
