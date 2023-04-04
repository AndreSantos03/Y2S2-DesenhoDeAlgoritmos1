#include "../include/Menu.h"

#include <string>


using namespace std;

string toUpperCase(const string& str) {
    string result;

    for (char c : str) {
        if (c >= 'a' && c <= 'z') {
            result += char(c - ('a' - 'A'));
        }
        else {
            result += c;
        }
    }

    return result;
}

Menu::Menu() {
    data = ReadData();
    graph = data.getGraph();
}

void Menu::display() {
    int choice;
    do {
        cout << "1. Specific Station Information\n"
             << "2. (TO IMPLEMENT)\n"
             << "3. (TO IMPLEMENT)\n"
             << "4. Quit\n"
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
                break;
            case 3:
                break;
            case 4:
                cout << "Quitting...\n" << endl;
                break;
            default:
                cout << "Invalid choice, please try again.\n";
                break;
        }
    } while (choice != 4);
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
        if(toUpperCase(station.second.getName()) == toUpperCase(name)){
            flag = true;
            cout << "Station: " << station.second.getName() << endl;
            if(!(station.second.getDistrict().empty())){
                cout << "District: " << station.second.getDistrict() << endl;
            }
            else{
                cout << "District: --- NO DATA ---" << endl;
            }
            if(!(station.second.getMunicipality().empty())){
                cout << "Municipality: " << station.second.getMunicipality() << endl;
            }
            else{
                cout << "Municipality: --- NO DATA ---" << endl;
            }
            if(!(station.second.getTownship().empty())){
                cout << "Township: " << station.second.getTownship() << endl;
            }
            else{
                cout << "Township: --- NO DATA ---" << endl;
            }
            if(!(station.second.getLine().empty())){
                cout << "Line: " << station.second.getLine() << endl;
            }
            else{
                cout << "Line: --- NO DATA ---" << endl;
            }

            for (const auto& edge : station.second.getAdj()) {
                cout << "   -> Connects to: " << edge.getDestination() << endl;
                cout << "      Capacity: " << edge.getCapacity() << endl;
                cout << "      Service: " << edge.getService() << endl;
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
            if(toUpperCase(district) == toUpperCase(station.second.getDistrict())){
                flag = true;
                cout << counter << ":" << station.second.getName() << endl;
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
            if(toUpperCase(municipality) == toUpperCase(station.second.getMunicipality())){
                flag = true;
                cout << counter << ":" << station.second.getName() << endl;
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
            if(toUpperCase(line) == toUpperCase(station.second.getLine())){
                flag = true;
                cout << counter << ":" << station.second.getName() << endl;
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




