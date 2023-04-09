#ifndef PROJETODA_MENU_H
#define PROJETODA_MENU_H

#include "graph/Graph.h"
#include "../include/Utils.h"
#include "information_managment/ReadData.h"

/**
 * @brief Class representing the main menu of the application.
 *
 * The `Menu` class is responsible for displaying the main menu options and handling user input.
 * It contains functions for displaying various information related to the graph and performing
 * different operations on the graph, such as finding maximum flow, shortest path, pairs with
 * maximum capacity, larger budgets, and maximum trains, among others.
 */
class Menu {
public:
    /**
     * @brief Default constructor for the `Menu` class.
     */
    Menu();

    /**
     * @brief Displays the main menu.
     */
    void display();

private:
    Graph graph;      // Graph object representing the network
    ReadData data;    // ReadData object for reading data from CSV files

    /**
     * @brief Displays information about a specific station.
     */
    void displayStationInformation();

    /**
     * @brief Displays information about a station based on its name.
     *
     * @param name Name of the station.
     */
    void displayStationInformationName(const string& name);

    /**
     * @brief Displays stations whose name contains a specific character.
     *
     * @param character Character to search for in station names.
     */
    void displayStationsWithChar(const string& character);

    /**
     * @brief Displays the maximum flow in the network.
     */
    void displayMaxFlow();

    /**
     * @brief Displays the shortest path between two stations.
     */
    void displayShortestPath();

    /**
     * @brief Displays pairs of stations with maximum capacity between them.
     */
    void displayPairsWithMaximumCapacity();

    /**
     * @brief Displays stations with larger budgets.
     */
    void displayLargerBudgets();

    /**
     * @brief Displays stations with maximum number of trains.
     */
    void displayMaxTrains();

    /**
     * @brief Displays a test function for debugging or testing purposes.
     */
    void displayTest();
};


#endif //PROJETODA_MENU_H
