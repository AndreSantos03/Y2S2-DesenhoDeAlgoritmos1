#ifndef PROJETODA_MENU_H
#define PROJETODA_MENU_H

#include "graph/Graph.h"
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

    void displayStationInformationName(string name);

    void displayStationsWithChar(string basicString);
};

#endif //PROJETODA_MENU_H
