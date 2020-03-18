#ifndef HEURISTIC_H
#define HEURISTIC_H

#include "model.h"
#include "graph.h"
#include "vehicle.h"
#include "util.h"
#include "localSearch.h"

#include <limits>

class Heuristic
{
private:
    Model *model;
    Graph *graph;
    LocalSearch *localSearch;
    Vehicle *vehicle = NULL;
    std::vector<Vehicle*> vehicles;
public:
    Heuristic();
    ~Heuristic();

    void nearestNeighboor();
    void addVehicle(Vehicle *v);
    void setModel(Model *model);
    void setGraph(Graph *graph);
    void createVehicle(int);

};



#endif