//
// Created by diogo on 15/03/2023.
//

#include "../../include/information_managment/ReadData.h"


ReadData::ReadData() {

    readStationsCSV("../projeto/data/stations.csv");
    readNetworkCSV("../projeto/data/network.csv");

}

void ReadData::readStationsCSV(const string &filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error opening file " << filename <<  endl << endl;
        return;
    }

    string line;
    getline(file, line); // skip the first line (column headers)
    while (getline(file, line)) {
        stringstream ss(line);

        string name, district, municipality, township, line;
        getline(ss, name, ',');
        getline(ss, district, ',');
        getline(ss, municipality, ',');
        getline(ss, township, ',');
        getline(ss, line, ',');

        graph.stations[name] = Station(name, district, municipality, township, line);
    }
    file.close();
}

void ReadData::readNetworkCSV(const string &filename) {
    // Open the CSV file
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl  << endl;
        return;
    }

    // Check if the file was successfully opened
    if (file.is_open()) {
        // Read the header line and ignore it
        string line;
        getline(file, line);

        // Read each line of the file
        while (getline(file, line)) {
            // Split the line by the comma delimiter
            stringstream lineStream(line);

            string src, dst, capacity, service;


            getline(lineStream, src, ',');
            getline(lineStream, dst, ',');
            getline(lineStream, capacity, ',');
            getline(lineStream, service, ',');

            // Add the edge to the graph (or just add new airline)
            graph.addTrip(src, dst, service, stod(capacity));
        }

        // Close the file
        file.close();
    }
}