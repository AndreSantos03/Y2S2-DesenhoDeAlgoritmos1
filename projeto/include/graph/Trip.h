//
// Created by diogo on 16/03/2023.
//

#ifndef PROJETODA_TRIP_H
#define PROJETODA_TRIP_H

#include <iostream>
#include <vector>

using namespace std;

class Trip{
public:

    Trip(string destination, double capacity, string service);

    const string &getDestination() const;

    void setDestination(const string &destination);

    double getCapacity() const;

    void setCapacity(double capacity);

    const string &getService() const;

    void setService(const string &service);

private:
    string destination;
    double capacity;
    string service;
};

#endif //PROJETODA_TRIP_H
