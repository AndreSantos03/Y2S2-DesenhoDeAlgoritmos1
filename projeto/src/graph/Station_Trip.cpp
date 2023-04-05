#include <utility>

#include "../../include/graph/Station_Trip.h"


Station::Station(string name, string district, string municipality,
                 string township, string line) : name(std::move(name)), district(std::move(district)), municipality(std::move(municipality)), township(std::move(township)), line(std::move(line)){}


void Station::addAdj(const Trip& trip) {
    adj.push_back(trip);
}

const string &Station::getName() const {
    return name;
}

void Station::setName(const string &name_) {
    Station::name = name_;
}

const string &Station::getDistrict() const {
    return district;
}

void Station::setDistrict(const string &district_) {
    Station::district = district_;
}

const string &Station::getMunicipality() const {
    return municipality;
}

void Station::setMunicipality(const string &municipality_) {
    Station::municipality = municipality_;
}

const string &Station::getTownship() const {
    return township;
}

void Station::setTownship(const string &township_) {
    Station::township = township_;
}

const string &Station::getLine() const {
    return line;
}

void Station::setLine(const string &line_) {
    Station::line = line_;
}

const vector<Trip> &Station::getAdj() const {
    return adj;
}

void Station::setAdj(const vector<Trip> &adjency) {
    Station::adj = adjency;
}

Station::Station() = default;



/*

||||||||||||| TRIP FUNCTIONS |||||||||||||

*/



Trip::Trip(Station *sourceStation, Station *destinationStation, double capacity,
           string service) {
    this->sourceStation = sourceStation;
    this->destinationStation = destinationStation;
    this->capacity = capacity;
    this->service = service;
}

Station *Trip::getDestination() const {
    return destinationStation;
}

void Trip::setDestination(const string &destination) {
    Trip::destinationStation = destination;
}

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

const string &Trip::getSourceStation() const {
    return sourceStation;
}

void Trip::setSourceStation(const string &src) {
    Trip::sourceStation = src;
}

const string &Trip::getDestinationStation() const {
    return destinationStation;
}

void Trip::setDestinationStation(const string &dest) {
    Trip::destinationStation = dest;
}
