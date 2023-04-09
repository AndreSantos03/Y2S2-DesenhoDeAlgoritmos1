#ifndef PROJETODA_GRAPH_H
#define PROJETODA_GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <bits/stdc++.h>
#include "Station_Trip.h"
#include "../Utils.h"

using namespace std;

/**
 * @brief Class representing the graph data structure.
 *
 * This class represents a graph data structure that stores information about stations and lines.
 * It provides methods for adding and retrieving stations, adding and removing edges between stations,
 * finding shortest paths, calculating maximum flow, and retrieving top k districts and municipalities
 * with the highest maximum flow.
 */
class Graph {
public:

    /**
     * @brief Adds a station to the graph.
     *
     * This method adds a station to the graph.
     *
     * @param station Pointer to the station to be added.
     */
    void addStations(Station *station);

    /**
     * @brief Retrieves the map of stations in the graph.
     *
     * This method retrieves the map of stations in the graph.
     *
     * @return The map of stations in the graph.
     */
    unordered_map<string, Station *> getStations() const;

    /**
     * @brief Retrieves a station from the graph by name.
     *
     * This method retrieves a station from the graph by its name.
     *
     * @param basicString The name of the station to be retrieved.
     * @return Pointer to the retrieved station, or nullptr if not found.
     */
    Station *getStation(const string &basicString);

    /**
     * @brief Adds an edge between two stations with a given service and capacity.
     *
     * This static method adds an edge between two stations in the graph with a given service and capacity.
     *
     * @param src Pointer to the source station of the edge.
     * @param dest Pointer to the destination station of the edge.
     * @param service The service of the edge.
     * @param capacity The capacity of the edge.
     */
    static void addEdge(Station *src, Station *dest,const string &service, double capacity);

    /**
     * @brief Removes an edge between two stations.
     *
     * This static method removes an edge between two stations in the graph.
     *
     * @param source Pointer to the source station of the edge.
     * @param destination Pointer to the destination station of the edge.
     */
    static void removeEdge(Station *source, Station *destination);

    /**
     * @brief Retrieves the map of lines in the graph.
     *
     * This method retrieves the map of lines in the graph.
     *
     * @return The map of lines in the graph.
     */
    const unordered_map<string, vector<Station *>> &getLines() const;

    /**
     * @brief Adds a station to a line in the graph.
     *
     * This method adds a station to a line in the graph.
     *
     * @param lineName The name of the line.
     * @param station Pointer to the station to be added to the line.
     */
    void addLines(const string &lineName, Station *station);

    /**
    * @brief Finds a station in the graph by name.
    *
     * This method finds a station in the graph by its name.
    *
    * @param src The name of the station to be found.
    * @return Pointer to the found station, or nullptr if not found.
    */
    Station *findStation(const string& src);

    /**
    * @brief Performs Dijkstra's algorithm to find the shortest path between two stations.
    *
    * This method performs Dijkstra's algorithm to find the shortest path between two stations in the graph.
    *
    * @param src Pointer to the source station.
    * @param dest Pointer to the destination station.
    * @return A vector of strings representing the names of stations in the shortest path.
    */
    vector<string> dijkstra(Station *src, Station *dest);

    /**
    * @brief Calculates the maximum flow between two stations using the Edmonds-Karp algorithm.
    *
    * This method calculates the maximum flow between two stations in the graph using the Edmonds-Karp algorithm.
    *
    * @param src Pointer to the source station.
    * @param dest Pointer to the destination station.
    * @return The maximum flow between the source and destination stations.
    */
    int maxFlow(Station* src, Station* dest);

    /**
    * @brief Performs the Breadth-First Search algorithm for the Edmonds-Karp algorithm.
    *
    * This method performs the Breadth-First Search algorithm for the Edmonds-Karp algorithm
    * to find an augmenting path from the source to the destination station.
    *
    * @param src Pointer to the source station.
    * @param dest Pointer to the destination station.
    * @return True if an augmenting path is found, false otherwise.
    */
    bool bfsEdmondsKarp(Station* src, Station* dest);

    /**
    * @brief Retrieves the top k districts with the highest maximum flow.
    *
    * This method retrieves the top k districts with the highest maximum flow in the graph.
    *
    * @param k The number of top districts to retrieve.
    * @return A vector of pairs, where each pair contains the name of a district and its corresponding maximum flow.
    */
    vector<pair<string, int>> top_k_max_flow_district(int k);

    /**
    * @brief Retrieves the top k municipalities with the highest maximum flow.
    *
    * This method retrieves the top k municipalities with the highest maximum flow in the graph.
    *
    * @param k The number of top municipalities to retrieve.
    * @return A vector of pairs, where each pair contains the name of a municipality and its corresponding maximum flow.
    */
    vector<pair<string, int>> top_k_max_flow_municipality(int k);

    /**
    * @brief Calculates the maximum number of trains that can be scheduled at a station.
    *
    * This method calculates the maximum number of trains that can arrive at a train simultaneously.
    *
    * @param stationName The name of the station.
    * @return The maximum number of trains that can arrive at a train simultaneously.
    */
    int maxTrains(const string& stationName);

    /**
    * @brief Calculate the maximum concurrent trains with minimal cost for the company between two stations.
    *
    * The `minCost()` function calculates the maximum concurrent trains that can travel between two stations,
    * while minimizing the cost for the company. It takes two pointers to `Station` objects as arguments,
    * representing the source station (`src`) and the destination station (`dest`), respectively.
    *
    * @param src Pointer to the source station.
    * @param dest Pointer to the destination station.
    *
    * @return A `pair` of `int` values representing the maximum concurrent trains and the minimal cost,
    * respectively, for the company between the two stations.
    */
    pair<int, int> minCost(Station *src, Station *dest);

    /**
    * @brief Find the cost of a given trip based on its service type.
    *
    * The `findCost()` function takes a constant reference to a `Trip` object as an argument,
    * representing the trip for which the cost needs to be determined. It then retrieves the service type
    * of the trip (either "STANDARD" or "ALFA PENDULAR") and returns the corresponding cost value
    * (2 for "STANDARD" and 4 for "ALFA PENDULAR").
    *
    * @param trip The `Trip` object for which the cost needs to be determined.
    *
    * @return An `int` value representing the cost of the trip based on its service type.
    */
    static int findCost(const Trip& trip);

    private:
    /**
    * @brief The map of stations in the graph.
    *
    * The `stations` member variable is an unordered map where the keys are station names
    * and the values are pointers to `Station` objects. It represents the collection of
    * stations in the graph that are added using the `addStations()` function.
    */
    unordered_map<string, Station*> stations;

    /**
    * @brief The map of lines in the graph.
    *
    * The `lines` member variable is an unordered map where the keys are line names and
    * the values are vectors of pointers to `Station` objects. It represents the collection
    * of lines in the graph that are added using the `addLines()` function.
    */
    unordered_map<string, vector<Station*>> lines;

};

#endif //PROJETODA_GRAPH_H
