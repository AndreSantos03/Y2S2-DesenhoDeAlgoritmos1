#ifndef PROJETODA_STATION_TRIP_H
#define PROJETODA_STATION_TRIP_H


#include <iostream>
#include <list>
#include <unordered_set>
#include <vector>


using namespace std;

class Trip;

/**
 * @brief Class representing a train station.
 */

class Station{
public:

    /**
     * @brief Default constructor for the Station class.
     */
    Station();

    /**
    * @brief Adds an edge to the adjacency list of the station.
    *
    * This function adds a directed edge from the current station to the destination station,
    * with the given capacity and service type.
    *
    * @param dest Pointer to the destination station.
    * @param capacity Capacity of the edge.
    * @param service Service type of the edge.
    */
    void addEdge(Station *dest, double capacity, const string &service);

    /**
     * @brief Retrieves the name of the Station.
     *
     * @return A constant reference to the string representing the name of the Station.
     */
    [[nodiscard]] const string &getName() const;

    /**
     * @brief Retrieves the district of the Station.
     *
     * @return A constant reference to the string representing the district of the Station.
     */
    [[nodiscard]] const string &getDistrict() const;

    /**
     * @brief Retrieves the municipality of the Station.
     *
     * @return A constant reference to the string representing the municipality of the Station.
     */
    [[nodiscard]] const string &getMunicipality() const;

    /**
     * @brief Retrieves the township of the Station.
     *
     * @return A constant reference to the string representing the township of the Station.
     */
    [[nodiscard]] const string &getTownship() const;

    /**
     * @brief Retrieves the line of the Station.
     *
     * @return A constant reference to the string representing the line of the Station.
     */
    [[nodiscard]] const string &getLine() const;

    /**
     * @brief Retrieves the edges (outgoing) from the Station.
     *
     * @return A constant vector reference to the list of outgoing edges from the Station.
     */
    [[nodiscard]] const vector<Trip *> &getEdge() const;

    /**
     * @brief Retrieves the incoming edges to the Station.
     *
     * @return A vector reference to the list of incoming edges to the Station.
     */
    vector<Trip *> &getIncoming();

    /**
     * @brief Checks if the Station has been visited.
     *
     * @return `true` if the Station has been visited, `false` otherwise.
     */
    [[nodiscard]] bool isVisited() const;

    /**
     * @brief Sets the visited status of the Station.
     *
     * @param visited_ The visited status of the Station.
     */
    void setVisited(bool visited_);

    /**
     * @brief Retrieves the path to the Station from the source Station.
     *
     * @return A constant pointer to the Trip object representing the path to the Station from the source Station.
     */
    [[nodiscard]] Trip *getPath() const;

    /**
     * @brief Sets the path to the Station from the source Station.
     *
     * @param path_ Pointer to the Trip object representing the path to the Station from the source Station.
     */
    void setPath(Trip *path_);

    /**
     * @brief Removes an edge from the Station's adjacency list.
     *
     * This function removes the edge from the current Station to the given destination Station
     * from the adjacency list.
     *
     * @param destination Pointer to the destination Station.
     */
    void removeEdge(Station *destination);

    /**
     * @brief Parametrized constructor for Station class.
     * @param name Name of the station.
     * @param district District of the station.
     * @param municipality Municipality of the station.
     * @param township Township of the station.
     * @param line Line of the station.
     */
    Station(string name, string district, string municipality, string township, string line);

private:
    /**
    * @brief Name of the station.
    */
    string name;

    /**
    * @brief District of the station.
    */
    string district;

    /**
    * @brief Municipality of the station.
    */
    string municipality;

    /**
    * @brief Township of the station.
    */
    string township;

    /**
    * @brief Line of the station.
    */
    string line;

    /**
    * @brief Outgoing edges of the station.
    */
    vector<Trip*> edges;

    /**
    * @brief Visited status of the station during graph traversal.
    */
    bool visited = false;

    /**
    * @brief Path of the station during graph traversal.
    */
    Trip *path = nullptr;

    /**
    * @brief Incoming edges of the station.
    */
    vector<Trip *> incoming;


};

/**
 * @brief Class representing a trip between two stations.
 */
class Trip{
public:

    /**
     * @brief Constructor for the Trip class.
     * @param sourceStation Pointer to the source station.
     * @param destinationStation Pointer to the destination station.
     * @param capacity Capacity of the trip.
     * @param service Service type of the trip (e.g. "STANDARD", "ALFA PENDULAR").
     */
    Trip(Station *sourceStation, Station *destinationStation, double capacity, string service);

    /**
     * @brief Get the capacity of the trip.
     * @return Capacity of the trip.
     */
    [[nodiscard]] double getCapacity() const;

    /**
     * @brief Set the capacity of the trip.
     * @param capacity Capacity of the trip.
     */
    void setCapacity(double capaci);

    /**
     * @brief Get the service type of the trip.
     * @return Service type of the trip.
     */
    [[nodiscard]] const string &getService() const;

    /**
     * @brief Set the service type of the trip.
     * @param service Service type of the trip.
     */
    void setService(const string &servic);

    /**
     * @brief Get the source station of the trip.
     * @return Pointer to the source station.
     */
    [[nodiscard]] Station *getSourceStation() const;

    /**
     * @brief Set the source station of the trip.
     * @param sourceStation Pointer to the source station.
     */
    void setSourceStation(Station *sourceStation_);

    /**
     * @brief Get the destination station of the trip.
     * @return Pointer to the destination station.
     */
    [[nodiscard]] Station *getDestinationStation() const;

    /**
     * @brief Set the destination station of the trip.
     * @param destinationStation Pointer to the destination station.
     */
    void setDestinationStation(Station *destinationStation_);

    /**
     * @brief Get the reverse trip of the current trip.
     * @return Pointer to the reverse trip.
     */
    [[nodiscard]] Trip *getReverse() const;

    /**
     * @brief Set the reverse trip of the current trip.
     * @param reverse Pointer to the reverse trip.
     */
    void setReverse(Trip *reverse_);

    /**
     * @brief Get the flow of the trip.
     * @return Flow of the trip.
     */
    [[nodiscard]] int getFlow() const;

    /**
     * @brief Set the flow of the trip.
     * @param flow Flow of the trip.
     */
    void setFlow(int flow_);

private:
    Station *sourceStation; /**< Pointer to the source station. */
    Station *destinationStation; /**< Pointer to the destination station. */
    double capacity; /**< Capacity of the trip. */
    int flow = 0; /**< Flow of the trip. */
    string service; /**< Service type of the trip. */
    Trip *reverse = nullptr; /**< Pointer to the reverse trip. */
};



#endif //PROJETODA_STATION_TRIP_H
