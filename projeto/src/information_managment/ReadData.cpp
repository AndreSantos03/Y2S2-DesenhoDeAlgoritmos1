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

    string fileLine;
    getline(file, fileLine); // skip the first line (column headers)

    while (getline(file, fileLine)) {
        stringstream ss(fileLine);

        string name, district, municipality, township, line;
        getline(ss, name, ',');
        getline(ss, district, ',');
        getline(ss, municipality, ',');
        getline(ss, township, ',');
        getline(ss, line, '\n');
        auto *station = new Station(name, district, municipality, township, line);
        graph.addStations(station);
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

            string src, dest, capacity, service;

            getline(lineStream, src, ',');
            getline(lineStream, dest, ',');
            getline(lineStream, capacity, ',');
            getline(lineStream, service, ',');

            Station *srcStation = graph.getStation(src);
            Station *destStation = graph.getStation(dest);
            graph.addEdge(srcStation, destStation, service, stod(capacity));
            graph.addLines(srcStation->getLine(), srcStation);
        }

        file.close();
    }
}

const Graph& ReadData::getGraph() const {
    return graph;
}
