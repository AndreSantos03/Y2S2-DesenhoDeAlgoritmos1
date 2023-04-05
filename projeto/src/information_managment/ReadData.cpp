#include "../../include/information_managment/ReadData.h"
#include "../../include/graph/Graph.h"

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

        graph.addStations(name, Station(name, district, municipality, township, line));
    }

    file.close();
}

void ReadData::readNetworkCSV(const string &filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl << endl;
        return;
    }

    if (file.is_open()) {
        string line;
        getline(file, line);

        while (getline(file, line)) {
            stringstream lineStream(line);

            string src, dst, capacity, service;

            getline(lineStream, src, ',');
            getline(lineStream, dst, ',');
            getline(lineStream, capacity, ',');
            getline(lineStream, service, ',');

            graph.addEdge(src, dst, service, stod(capacity));
        }

        file.close();
    }
}

const Graph& ReadData::getGraph() const {
    return graph;
}
