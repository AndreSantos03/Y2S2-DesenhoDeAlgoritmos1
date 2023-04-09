//
// Created by diogo on 16/03/2023.
//

#include "../../include/graph/Graph.h"

int Graph::findCost(const Trip& trip) {
    if(trip.getService() == "STANDARD") return 2;

    else if(trip.getService() == "ALFA PENDULAR") return 4;

    return -1;
}

void Graph::addEdge(Station *src, Station *dest,const string &service, double capacity) {

    src->addEdge(dest, capacity, service);
    dest->addEdge(src, capacity, service);


}

void Graph::removeEdge(Station *source, Station *destination) {
    source->removeEdge(destination);
    destination->removeEdge(source);
}


unordered_map<string, Station *> Graph::getStations() const {
    return stations;
}

Station* Graph::getStation(const string &basicString) {
    return stations[basicString];
}


void Graph::addStations(Station *station) {
    if (stations.find(station->getName()) == stations.end()) {
        stations[station->getName()] = station;
    }
}

void Graph::addLines(const string &lineName, Station *station) {
    lines[lineName].push_back(station);
}


const unordered_map<string, vector<Station *>> &Graph::getLines() const {
    return lines;
}


Station* Graph::findStation(const string& src) {
    for (const auto& station: stations) {
        if (station.first == src) {
            return station.second;
        }
    }
    return nullptr;
}

vector<string> Graph::dijkstra(Station* src, Station* dest) {
    unordered_map<string, Station*> visited;
    unordered_map<string, Station*> unvisited;
    unordered_map<string, Station*> previous;
    unordered_map<string, int> distances;

    for (const auto& station : stations) {
        unvisited[station.second->getName()] = station.second;
        distances[station.second->getName()] = INT_MAX;
    }
    distances[src->getName()] = 0;

    while (!unvisited.empty()) {
        Station* curr = unvisited.begin()->second;
        for(auto &station: unvisited){
            if(distances[station.first] < distances[curr->getName()])
                curr = station.second;
        }

        if(curr->getName() == dest->getName()) break;

        unvisited.erase(curr->getName());
        visited[curr->getName()] = curr;

        for(auto &connection: curr->getEdge()){
            if(visited.find(connection->getDestinationStation()->getName()) == visited.end()){
                int i = distances[curr->getName()] + 1;
                if(i < distances[connection->getDestinationStation()->getName()]){
                    distances[connection->getDestinationStation()->getName()] = i;
                    previous[connection->getDestinationStation()->getName()] = curr;
                }
            }
        }
    }

    if (distances[dest->getName()] == INT_MAX) {
        return {};
    }

    vector<string> path;
    Station *current = dest;
    while (current != nullptr) {
        path.push_back(current->getName());
        current = previous[current->getName()];
    }
    reverse(path.begin(), path.end());
    return path;
}

bool Graph::bfsEdmondsKarp(Station* src, Station* dest) {
    for (auto& [name, station] : stations) {
        station->setVisited(false);
        station->setPath(nullptr);
        for (auto edge : station->getEdge()) {
            delete edge->getReverse();
            edge->setReverse(nullptr);
        }
    }

    std::queue<Station*> q;
    q.push(src);
    src->setVisited(true);

    while (!q.empty()) {
        Station* currStation = q.front();
        q.pop();

        for (auto edge : currStation->getEdge()) {
            Station* neighborStation = edge->getDestinationStation();

            if (!neighborStation->isVisited() && edge->getCapacity() - edge->getFlow() > 0) {
                neighborStation->setPath(edge);
                neighborStation->setVisited(true);
                q.push(neighborStation);

                if (neighborStation == dest) {
                    return true;
                }
            }
        }

        for (auto edge : currStation->getIncoming()) {
            Station* neighborStation = edge->getSourceStation();

            if (!neighborStation->isVisited() && edge->getFlow() != 0) {
                Trip* reverseEdge = new Trip(edge->getDestinationStation(), edge->getSourceStation(), edge->getFlow(), edge->getService());
                reverseEdge->setFlow(0);
                edge->setReverse(reverseEdge);
                reverseEdge->setReverse(edge);

                neighborStation->setPath(reverseEdge);
                neighborStation->setVisited(true);
                q.push(neighborStation);
            }
        }
    }
    return false;
}


int Graph::maxFlow(Station* src, Station* dest) {
    for(auto& station : stations){
        for(auto trip : station.second->getEdge())
            trip->setFlow(0);
    }

    int maxFlow = 0;
    bool foundPath = true;

    while(foundPath){
        foundPath = bfsEdmondsKarp(src, dest);

        if(foundPath){
            int mrc = INT32_MAX;
            Station* currStation = dest;

            while(currStation != src){
                Trip* path = currStation->getPath();

                if(path->getReverse() == nullptr)
                    mrc = std::min(mrc, static_cast<int> (path->getCapacity() - path->getFlow()));
                else
                    mrc = std::min(mrc, static_cast<int> (path->getReverse()->getFlow()));

                currStation = path->getSourceStation();
            }

            currStation = dest;

            while(currStation != src){
                Trip* path = currStation->getPath();

                if(path->getReverse() == nullptr)
                    path->setFlow(path->getFlow() + mrc);
                else
                    path->getReverse()->setFlow(path->getReverse()->getFlow() - mrc);

                currStation = path->getSourceStation();
            }

            maxFlow += mrc;
        }
    }

    return maxFlow;
}

vector<pair<string, int>> Graph::top_k_max_flow_district(int k) {
    vector<pair<string, int>> result;
    unordered_map<string, int> d_temp;
    unordered_map<string, Station*> auxStations = stations;

    for (const auto& station : stations) {
        auxStations.erase(station.first);
        for (const auto& station2 : auxStations) {
            if (station.first == station2.first)
                continue;
            if (station.second->getDistrict() != station2.second->getDistrict())
                continue;
            d_temp[station.second->getDistrict()] += maxFlow(station.second, station2.second);
        }
    }

    while (k > 0 && !d_temp.empty()) {
        string maxD;
        int maxFlow = -1;
        for (const auto& d : d_temp) {
            if (d.second > maxFlow) {
                maxFlow = d.second;
                maxD = d.first;
            }
        }
        result.emplace_back(maxD, maxFlow);
        d_temp.erase(maxD);
        k--;
    }

    return result;
}

vector<pair<string, int>> Graph::top_k_max_flow_municipality(int k) {
    vector<pair<string, int>> result;
    unordered_map<string, int> m_temp;
    unordered_map<string, Station *> auxStations = stations;
    for (const auto &station : stations) {
        auxStations.erase(station.first);
        for (const auto &station2 : auxStations) {
            if (station.first == station2.first) {
                continue;
            }
            if (station.second->getMunicipality() != station2.second->getMunicipality()) {
                continue;
            }
            m_temp[station.second->getMunicipality()] += maxFlow(station.second, station2.second);
        }
    }
    while (k > 0) {
        int max_flow = 0;
        string max_municipality;
        for (const auto &m : m_temp) {
            if (m.second > max_flow) {
                max_flow = m.second;
                max_municipality = m.first;
            }
        }
        result.emplace_back(max_municipality, max_flow);
        m_temp.erase(max_municipality);
        k--;
    }
    return result;
}

int Graph::maxTrains(const string& stationName) {
    Station *  station = findStation(stationName);
    auto *source_station = new Station("ss", "s", "s","s","s");
    stations["ss"] = source_station;
    for (auto &s: stations) {
        if (s.second != station && stations[s.first]->getEdge().size() == 1) {
            addEdge(s.second,source_station, "SP", INT_MAX);
        }
    }

    int max_flow = maxFlow(source_station, station);
    int station_flow = 0;

    for (auto &neighbor: station->getIncoming()) {
        station_flow += static_cast<int> (neighbor->getCapacity());
    }
    for (auto &s: stations) {
        if (s.second != station && s.second->getEdge().size() == 1) {
            removeEdge(s.second,source_station);
        }
    }
    return min(station_flow, max_flow);
}

pair<int, int> Graph::minCost(Station* src, Station* dest) {
    for (auto& station : stations) {
        for (auto trip : station.second->getEdge())
            trip->setFlow(0);
    }

    int maxFlow = 0;
    int minCost = 0;
    bool foundPath = true;

    while (foundPath) {
        foundPath = bfsEdmondsKarp(src, dest);

        if (foundPath) {
            int mrc = INT32_MAX;
            Station* currStation = dest;

            while (currStation != src) {
                Trip* path = currStation->getPath();

                if (path->getReverse() == nullptr)
                    mrc = std::min(mrc, static_cast<int>(path->getCapacity() - path->getFlow()));
                else
                    mrc = std::min(mrc, static_cast<int>(path->getReverse()->getFlow()));

                int cost = this->findCost(*path);

                currStation = path->getSourceStation();

                minCost += mrc * cost;

                if (path->getReverse() == nullptr)
                    path->setFlow(path->getFlow() + mrc);
                else
                    path->getReverse()->setFlow(path->getReverse()->getFlow() - mrc);
            }

            maxFlow += mrc;
        }
    }

    return {maxFlow, minCost};
}
