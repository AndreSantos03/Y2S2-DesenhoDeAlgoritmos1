//
// Created by diogo on 16/03/2023.
//

#include "../../include/graph/Graph.h"
#include "../../include/graph/Station_Trip.h"

void Graph::addEdge(Station *src, Station *dest,const string &service, double capacity) {

    src->addEdge(dest, capacity, service);
    dest->addEdge(src, capacity, service);


}

const unordered_map<string, Station *> Graph::getStations() const {
    return stations;
}

Station* Graph::getStation(const string &basicString) {
    return stations[basicString];
}


void Graph::addStations(Station *station) {
    stations[station->getName()] = station;
}

void Graph::addLines(const string &lineName, Station *station) {
    lines[lineName].push_back(station);
}


const unordered_map<string, vector<Station *>> &Graph::getLines() const {
    return lines;
}

Station *Graph::findStation(const string& src) {
    for (const auto &station: stations) {
        if (station.first == src) {
            return station.second;
        }
    }
    return nullptr;
}

/*
bool Graph::bfsEdmondsKarp(const string &src, const string &dest) {
    for(auto s: stations){
        s.second->setPath(nullptr);
        s.second->setVisited(false);

        for(auto e: s.second->getEdge()){
            delete e->getReverse();
            e->setReverse(nullptr);
        }
    }

    queue<Station *> q;
    Station * srcStat = findStation(src);
    q.push(srcStat);
    srcStat->setVisited(true);

    while(!q.empty()){
        Station* u = q.front();
        q.pop();

        for(auto e: u->getEdge()){
            Station *w = e->getDestinationStation();

            if(e->getCapacity() - e->getFlow() > 0 && !w->isVisited()){
                w->setVisited(true);
                w->setPath(e);
                q.push(w);
                if(w->getName() == dest) return true;
            }
        }

        for(auto e: u->getIncoming()){
            Station *w = e->getDestinationStation();

            if(e->getFlow() != 0 && !w->isVisited()){
                Trip * rev = new Trip(e->getDestinationStation(), e->getSourceStation(),e->getFlow(),e->getService());

                rev->setFlow(0);
                rev->setReverse(e);
                e->setReverse(rev);
                w->setVisited(rev);
                w->setPath(rev);
                q.push(w);
            }
        }
    }
}
*/

bool Graph::bfsEdmondsKarp(const string &src, const string &dest) {
    // Reset the graph
    for (auto s : stations) {
        s.second->setPath(nullptr);
        s.second->setVisited(false);

        for (auto e : s.second->getEdge()) {
            delete e->getReverse();
            e->setReverse(nullptr);
        }
    }

    // Perform the BFS traversal
    queue<Station*> q;
    Station* srcStat = findStation(src);
    q.push(srcStat);
    srcStat->setVisited(true);

    while (!q.empty()) {
        Station* u = q.front();
        q.pop();

        for (auto e : u->getEdge()) {
            Station* w = e->getDestinationStation();

            if (e->getCapacity() - e->getFlow() > 0 && !w->isVisited()) {
                w->setVisited(true);
                w->setPath(e);
                q.push(w);
            }
        }

        for (auto e : u->getIncoming()) {
            Station* w = e->getSourceStation();

            if (e->getFlow() != 0 && !w->isVisited()) {
                Trip* rev = new Trip(w, u, e->getFlow(), e->getService());

                rev->setFlow(0);
                rev->setReverse(e);
                e->setReverse(rev);
                w->setVisited(true);
                w->setPath(rev);
                q.push(w);
            }
        }
    }

    // Check if there is a path from the source station to the destination station
    Station* destStat = findStation(dest);
    return destStat->isVisited();
}

int Graph::maxFlow( const string &src, const string &dest) {

    while(bfsEdmondsKarp(src, dest)) {
        Station *curr = getStation(dest);
        double bottleneck = INT_MAX ;

        while(curr->getPath() != nullptr) {
            Trip *edge = curr->getPath();
            bottleneck = min(bottleneck, edge->getCapacity() - edge->getFlow());
            curr = edge->getSourceStation();
        }

        curr = getStation(dest);
        while(curr->getPath() != nullptr) {
            Trip *edge = curr->getPath();
            edge->setFlow(edge->getFlow() + bottleneck);
            edge->getReverse()->setFlow(edge->getReverse()->getFlow() - bottleneck);
            curr = edge->getSourceStation();
        }
    }

    int maxTrains = 0;
    Station *srcStation = getStation(src);
    for(auto e: srcStation->getEdge()) {
        if(e->getFlow() > 0) {
            maxTrains += e->getFlow();
        }
    }
    return maxTrains;
}
