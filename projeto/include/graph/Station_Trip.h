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



class Trip{
public:

    Trip(string sourceStation, string destinationStation, double capacity, string service);

    const string &getDestination() const;

    void setDestination(const string &destination);

    double getCapacity() const;

    void setCapacity(double capacity);

    const string &getService() const;

    void setService(const string &service);

    const string &getSourceStation() const;

    void setSourceStation(const string &sourceStation);

    const string &getDestinationStation() const;

    void setDestinationStation(const string &destinationStation);

private:
    string sourceStation;
    string destinationStation;
    double capacity;
    string service;
};



#endif //PROJETODA_STATION_TRIP_H
