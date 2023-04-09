//
// Created by diogo on 15/03/2023.
//

#ifndef PROJETODA_READDATA_H
#define PROJETODA_READDATA_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iterator>
#include "../graph/Graph.h"

using namespace std;


/**
 * @brief Class for reading and storing data from CSV files into a graph data structure.
 */
class ReadData {
private:

    Graph graph; /**< Graph data structure to store the read data. */

public:

    /**
     * @brief Constructor for the ReadData class.
     */
    ReadData();

    /**
     * @brief Read station data from a CSV file and populate the graph.
     * @param filename Name of the CSV file containing station data.
     */
    void readStationsCSV(const string& filename);

    /**
     * @brief Read network data from a CSV file and populate the graph.
     * @param filename Name of the CSV file containing network data.
     */
    void readNetworkCSV(const string& filename);

    /**
     * @brief Get the graph containing the read data.
     * @return Constant reference to the graph containing the read data.
     */
    const Graph &getGraph() const;

};

#endif //PROJETODA_READDATA_H
