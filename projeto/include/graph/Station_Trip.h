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

    void addEdge(Station *dest, double capacity, const string &service);

    const string &getName() const;

    const string &getDistrict() const;

    const string &getMunicipality() const;

    const string &getTownship() const;

    const string &getLine() const;

    const vector<Trip *> &getEdge() const;

    vector<Trip *> &getIncoming();

    bool isVisited() const;

    void setVisited(bool visited);

    Trip *getPath() const;

    void setPath(Trip *path);

    Station(string name, string district, string municipality, string township, string line);

private:
    string name, district, municipality, township, line;

    vector<Trip*> edges;
    bool visited = false;
    Trip *path = nullptr;
    vector<Trip *> incoming;


};



class Trip{
public:

    Trip(Station *sourceStation, Station *destinationStation, double capacity, string service);

    double getCapacity() const;

    void setCapacity(double capaci);

    const string &getService() const;

    void setService(const string &servic);

    Station *getSourceStation() const;

    void setSourceStation(Station *sourceStation);

    Station *getDestinationStation() const;

    void setDestinationStation(Station *destinationStation);

    Trip *getReverse() const;

    void setReverse(Trip *reverse);

    int getFlow() const;

    void setFlow(int flow);

private:
    Station *sourceStation;
    Station *destinationStation;
    double capacity;
    int flow = 0;
    string service;
    Trip *reverse = nullptr;
};



#endif //PROJETODA_STATION_TRIP_H
