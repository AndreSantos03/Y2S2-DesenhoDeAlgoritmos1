#ifndef PROJETODA_MENU_H
#define PROJETODA_MENU_H

#include "graph/Graph.h"
#include "../include/Utils.h"
#include "information_managment/ReadData.h"

class Menu {
public:
    Menu();
    void display();

private:
    Graph graph;
    ReadData data;

    void displayGraphInfo() const;

    void displayStationInformation();

    void displayStationInformationName(const string& name);

    void displayStationsWithChar(const string& basicString);

    void displayMaxFlow();

    void displayShortestPath();
};

#endif //PROJETODA_MENU_H
