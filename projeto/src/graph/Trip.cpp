//
// Created by diogo on 16/03/2023.
//

#include "../../include/graph/Trip.h"

Trip::Trip(string destination, double capacity,
           string service) : destination(destination), capacity(capacity), service(service) {}

const string &Trip::getDestination() const {
    return destination;
}

void Trip::setDestination(const string &destination) {
    Trip::destination = destination;
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
