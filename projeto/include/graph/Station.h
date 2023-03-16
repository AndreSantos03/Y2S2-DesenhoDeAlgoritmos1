//
// Created by diogo on 16/03/2023.
//

#ifndef PROJETODA_STATION_H
#define PROJETODA_STATION_H

#include <iostream>
#include <list>
#include <unordered_set>
#include "Trip.h"

using namespace std;


class Station{
public:

    Station();

    void addAdj(const Trip& trip);

    const string &getName() const;

    void setName(const string &name);

    const string &getDistrict() const;

    void setDistrict(const string &district);

    const string &getMunicipality() const;

    void setMunicipality(const string &municipality);

    const string &getTownship() const;

    void setTownship(const string &township);

    const string &getLine() const;

    void setLine(const string &line);

    const vector<Trip> &getAdj() const;

    void setAdj(const vector<Trip> &adj);

    Station(string name, string district, string municipality, string township, string line);

private:
    string name, district, municipality, township, line;

    vector<Trip> adj;


};

#endif //PROJETODA_STATION_H
