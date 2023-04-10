#include "../include/Menu.h"


#include <string>


using namespace std;

Menu::Menu() {
    data = ReadData();
    graph = data.getGraph();
}

void Menu::display() {
    int choice;
    do {
        cout << "---------------------------------> MENU <-------------------------------------\n"
             << "1. Specific Station Information\n"
             << "2. Maximum number of trains that can simultaneously travel between two stations\n"
             << "3. Shortest path between two stations\n"
             << "4. Display the pair of stations that needs trains\n"
             << "5. Top-k municipalities/districts with highest budget needs\n"
             << "6. Max number of trains that can arrive at a station simultaneously\n"
             << "7. Maximum concurrent trains with minimal cost for the company between two stations\n"
             << "8. Maximum number of trains with reduced connectivity\n"
             << "9. Quit\n"
             << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        cout << endl;

        if (cin.fail()) {
            cout << "Invalid choice, please try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore remaining input
            continue;
        }


        switch (choice) {
            case 1:
                displayStationInformation();
                break;
            case 2:
                displayMaxFlow();
                break;
            case 3:
                displayShortestPath();
                break;
            case 4:
                displayPairsWithMaximumCapacity();
                break;
            case 5:
                displayLargerBudgets();
                break;
            case 6:
                displayMaxTrains();
                break;
            case 7:
                displayMinCost();
                break;
            case 8:
                displayMaxFlowWithFailure();
                break;
            case 9:
                cout << "Quitting...\n" << endl;
                break;

            default:
                cout << "Invalid choice, please try again.\n";
                break;
        }
    } while (choice != 9);
}

void Menu::displayStationInformation() {

    int choice;
    do {
        cout << "1. Display station information within a given name\n"
             << "2. Display all stations in a specific district, municipality, or line\n"
             << "3. Back\n"
             << "4. Quit\n"
             << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        cout << endl;

        if (cin.fail()) {
            cout << "Invalid choice, please try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        string stationName;
        string input_char;
        switch (choice) {
            case 1:
                cout << "Enter the Station name: ";
                getline(cin >> ws, stationName);
                cout << endl;
                displayStationInformationName(stationName);
                break;
            case 2:
                cout << "Enter the letter corresponding to the category of stations you want to display: (d for district, m for municipality, or l for line): ";
                getline(cin >> ws, input_char);
                cout << endl;
                displayStationsWithChar(input_char);

                break;
            case 3:
                cout << "Going to Main Menu...\n";
                cout << endl;
                cout << endl;
                break;
            case 4:
                cout << "Quitting...\n" << endl;
                exit(0);
            default:
                cout << "Invalid choice, please try again.\n";
                break;
        }
    } while (choice != 3);
}

void Menu::displayStationInformationName(const string& name) {
    bool flag = false;
    for (const auto& station : graph.getStations()) {
        if(station.second->getName() == name){
            flag = true;
            cout << "Station: " << station.second->getName() << endl;
            if(!(station.second->getDistrict().empty())){
                cout << "District: " << station.second->getDistrict() << endl;
            }
            else{
                cout << "District: --- NO DATA ---" << endl;
            }
            if(!(station.second->getMunicipality().empty())){
                cout << "Municipality: " << station.second->getMunicipality() << endl;
            }
            else{
                cout << "Municipality: --- NO DATA ---" << endl;
            }
            if(!(station.second->getTownship().empty())){
                cout << "Township: " << station.second->getTownship() << endl;
            }
            else{
                cout << "Township: --- NO DATA ---" << endl;
            }
            if(!(station.second->getLine().empty())){
                cout << "Line: " << station.second->getLine() << endl;
            }
            else{
                cout << "Line: --- NO DATA ---" << endl;
            }

            for (const auto& edge : station.second->getEdge()) {
                cout << "  ==> Connects to: " << edge->getDestinationStation()->getName() << endl;
                cout << "      Capacity: " << edge->getCapacity() << endl;
                cout << "      Service: " << edge->getService() << endl;
            }
            cout << endl;
        }
    }
    if(!flag){
        cout << "Not Found" << endl << endl;
    }
}

void Menu::displayStationsWithChar(const string& in) {
    if(toUpperCase(in) == "D"){
        bool flag = false;
        string district;
        int counter = 1;
        cout << "Enter the District: ";
        getline(cin >> ws, district);
        cout << endl;
        cout << "All stations from District: " << district;
        cout << endl;
        for (const auto& station : graph.getStations()) {
            if(district == station.second->getDistrict()){
                flag = true;
                cout << counter << ":" << station.second->getName() << endl;
                counter++;
            }
        }
        cout << endl;
        if(!flag) cout << "--- NO DATA ---" << endl;
        cout << endl;
    }
    else if(toUpperCase(in) == "M"){
        bool flag = false;
        string municipality;
        int counter = 1;
        cout << "Enter the Municipality: ";
        getline(cin >> ws, municipality);
        cout << endl;
        cout << "All stations from Municipality: " << municipality;
        cout << endl;
        for (const auto& station : graph.getStations()) {
            if(municipality == station.second->getMunicipality()){
                flag = true;
                cout << counter << ":" << station.second->getName() << endl;
                counter++;
            }
        }
        cout << endl;
        if(!flag) cout << "--- NO DATA ---" << endl;
        cout << endl;
    }
    else if(toUpperCase(in) == "L"){
        bool flag = false;
        string line;
        int counter = 1;
        cout << "Enter the Line: ";
        getline(cin >> ws, line);
        cout << endl;
        cout << "All stations from Line: " << line;
        cout << endl;
        for (const auto& station : graph.getStations()) {
            if(line == station.second->getLine()){
                flag = true;
                cout << counter << ":" << station.second->getName() << endl;
                counter++;
            }
        }
        cout << endl;
        if(!flag) cout << "--- NO DATA ---" << endl;
        cout << endl;
    }
    else{
        cout << "Invalid choice, please try again." << endl << endl;
    }
}

void Menu::displayMaxFlow() {
    string srcString, destString;
    Station * src;
    Station * dest;
    cout << "Insert Source Station Name:";
    getline(cin >> ws, srcString);
    src = graph.findStation(srcString);
    if(src== nullptr){
        cout << srcString << " is not a train station." <<endl;
        cout << "Returning..."<<endl<<endl;
        return;
    }
    cout << "Insert Destination Station Name:";
    getline(cin >> ws, destString);
    dest = graph.findStation(destString);
    if(dest== nullptr){
        cout << destString << " is not a train station." <<endl;
        cout << "Returning..."<<endl<<endl;
        return;
    }

    int totalFlow = graph.maxFlow(src,dest);
    if(totalFlow == 0){
        cout << "There's no path between " << src->getName() << " and " << dest->getName() << endl<< endl;
    }
    else{
        cout << totalFlow << " trains have the capacity to travel concurrently between " << src->getName() << " and " << dest->getName() << "." << endl << endl;
    }
}

void Menu::displayShortestPath(){
    string srcString, destString;
    Station * src;
    Station * dest;
    cout << "Insert Source Station Name:";
    getline(cin >> ws, srcString);
    src = graph.findStation(srcString);
    if(src== nullptr){
        cout << srcString << " is not a train station." <<endl;
        cout << "Returning..."<<endl<<endl;
        return;
    }
    cout << "Insert Destination Station Name:";
    getline(cin >> ws, destString);
    dest = graph.findStation(destString);
    if(dest== nullptr){
        cout << destString << " is not a train station." <<endl;
        cout << "Returning..."<<endl<<endl;
        return;
    }
    vector<string> path = graph.dijkstra(src,dest);
    if(path[0] != src->getName()){
        cout <<endl<< "Theres no path between " << src->getName() << " and " << dest->getName() << "." << endl<<endl;
    }
    else{
        cout <<endl<< "Shortest path between " << src->getName() << " and " << dest->getName() << ":" << endl<<endl;
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i != path.size() - 1) {
                cout << " ==> ";
            }
        }
        cout<< endl<< endl << "Total distance: " << path.size() << endl<<endl;
    }

}

void Menu::displayPairsWithMaximumCapacity(){
    int maximumFlow = 0;
    unordered_map<string,string> pairStations;
    auto stations = graph.getStations();
    for(const auto& stationX : stations){
        for(const auto& stationY : stations){
            if(stationX.second != stationY.second){
                int flow = graph.maxFlow(stationX.second, stationY.second);
                if(maximumFlow < flow){
                    maximumFlow = flow;
                    pairStations.clear();
                    pairStations.insert({stationX.second->getName(), stationY.second->getName()});
                }
                else if (flow == maximumFlow){
                    pairStations.insert({stationX.second->getName(), stationY.second->getName()});
                }
            }
        }
    }

    cout << endl << "Max: " << maximumFlow << endl;

    for(const auto& pair : pairStations){
        cout << pair.first << " - " << pair.second << endl << endl;
    }
}



void Menu::displayLargerBudgets() {
    string ans;
    cout << "District or Municipality? (d/m):\n";
    getline(cin >> ws, ans);
    while(toUpperCase(ans) != "M" && toUpperCase(ans) != "D"){
        cout << ans << endl;
        cout << "Invalid answer!\nDistrict or Municipality? (d/m):\n";
        getline(cin >> ws, ans);
    }
    int ammount;
    while (true) {
        cout << "Amount to be displayed:\n";
        cin >> ammount;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << "Error: Invalid input. Please enter a valid number.\n";
        } else {
            break;
        }
    }

    vector<pair<string,int>> listK;
    if(toUpperCase(ans) == "D")
        listK = graph.top_k_max_flow_district(ammount);
    else listK = graph.top_k_max_flow_municipality(ammount);
    for(const auto& p : listK){
        cout << p.first << " requires " <<  p.second << " trains.\n";
    }
}

void Menu::displayMaxTrains() {
    cout << "Enter Station Name:";
    string stationName;
    getline(cin >> ws, stationName);
    while(graph.findStation(stationName) == nullptr){
        cout << endl << "Invalid Station Name!\n";
        cout << "Enter Station Name:";
        getline(cin >> ws, stationName);
    }
    int max = graph.maxTrains(stationName);
    cout << endl << graph.findStation(stationName)->getName() << " can have " << max << " trains arriving at the same time\n" << endl << endl;
}

void Menu::displayMinCost() {
    string srcString, destString;
    Station * src;
    Station * dest;
    cout << "Insert Source Station Name:";
    getline(cin >> ws, srcString);
    src = graph.findStation(srcString);
    if(src== nullptr){
        cout << srcString << " is not a train station." <<endl;
        cout << "Returning..."<<endl<<endl;
        return;
    }
    cout << "Insert Destination Station Name:";
    getline(cin >> ws, destString);
    dest = graph.findStation(destString);
    if(dest== nullptr){
        cout << destString << " is not a train station." <<endl;
        cout << "Returning..."<<endl<<endl;
        return;
    }
    const pair<int, int> min_cost = graph.minCost(src, dest);
    cout << endl << "Only " << min_cost.first << " trains can travel concurrently between " << src->getName() << " and " << dest->getName() << " with a minimum cost of " << min_cost.second << " euros.\n" << endl;
}

void Menu::displayMaxFlowWithFailure() {
    vector<pair<string,string>> affected;
    string srcString, destString;
    Station * src;
    Station * dest;
    cout << "Insert Source Station Name:";
    getline(cin >> ws, srcString);
    src = graph.findStation(srcString);
    if (src == nullptr) {
        cout << srcString << " is not a train station." << endl;
        cout << "Returning..." << endl << endl;
        return;
    }
    cout << "Insert Destination Station Name:";
    getline(cin >> ws, destString);
    dest = graph.findStation(destString);
    if (dest == nullptr) {
        cout << destString << " is not a train station." << endl;
        cout << "Returning..." << endl << endl;
        return;
    }
    affected.emplace_back(srcString,destString);
    int flow = graph.maxFlowWithFailure(affected,srcString,destString);
    if(flow == 0){
        cout << "There's no path between " << srcString << " and " << destString << endl<< endl;
    }
    else{
        cout << flow << " trains have the capacity to travel concurrently between " << srcString << " and " << destString << "." << endl << endl;
    }
}



