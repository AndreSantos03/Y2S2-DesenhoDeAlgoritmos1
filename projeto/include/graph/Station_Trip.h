#ifndef PROJETODA_STATION_TRIP_H
#define PROJETODA_STATION_TRIP_H


#include <iostream>
#include <list>
#include <unordered_set>
#include <vector>


using namespace std;

class Trip;


class Station{
public:

    Station();

    void addAdj(const Trip& trip);

    const string &getName() const;

    void setName(const string &name_);

    const string &getDistrict() const;

    void setDistrict(const string &district_);

    const string &getMunicipality() const;

    void setMunicipality(const string &municipality_);

    const string &getTownship() const;

    void setTownship(const string &township_);

    const string &getLine() const;

    void setLine(const string &line_);

    const vector<Trip> &getAdj() const;

    void setAdj(const vector<Trip> &adjency);

    Station(string name, string district, string municipality, string township, string line);

private:
    string name, district, municipality, township, line;

    vector<Trip> adj;


};



class Trip{
public:

    Trip(string sourceStation, string destinationStation, double capacity, string service);

    const string &getDestination() const;

    void setDestination(const string &destination);

    double getCapacity() const;

    void setCapacity(double capaci);

    const string &getService() const;

    void setService(const string &servic);

    const string &getSourceStation() const;

    void setSourceStation(const string &src);

    const string &getDestinationStation() const;

    void setDestinationStation(const string &dest);

private:
    string sourceStation;
    string destinationStation;
    double capacity;
    string service;
};



#endif //PROJETODA_STATION_TRIP_H
