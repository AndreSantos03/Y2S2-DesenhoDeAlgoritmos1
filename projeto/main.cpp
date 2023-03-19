#include <iostream>
#include "include/graph/Graph.h"
#include "include/information_managment/ReadData.h"

void displayGraphInfo(const Graph& graph) {
    // Iterate over all stations in the graph
    for (const auto& station : graph.stations) {
        cout << "Station: " << station.second.getName() << endl;
        cout << "District: " << station.second.getDistrict() << endl;
        cout << "Municipality: " << station.second.getMunicipality() << endl;
        cout << "Township: " << station.second.getTownship() << endl;
        cout << "Line: " << station.second.getLine() << endl;

        // Iterate over all edges (connections) of this station
        for (const auto& edge : station.second.getAdj()) {
            cout << "   -> Connects to: " << edge.getDestination() << endl;
            cout << "      Capacity: " << edge.getCapacity() << endl;
            cout << "      Service: " << edge.getService() << endl;
        }
        cout << endl;
    }
}

int main() {
    ReadData data;
    displayGraphInfo(data.getGraph());
    return 0;
}
