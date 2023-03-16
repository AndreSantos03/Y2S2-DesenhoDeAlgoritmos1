//
// Created by diogo on 16/03/2023.
//

#include "../../include/graph/Station.h"

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