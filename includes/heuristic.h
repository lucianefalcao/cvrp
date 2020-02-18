#ifndef HEURISTIC_H
#define HEURISTIC_H

#include "graph.h"
#include "model.h"
#include "vehicle.h"

#include <limits>

class Heuristic
{
private:
    Model *model;
    Graph *graph;
    Vehicle *vehicle;
public:
    Heuristic(Model *model, Graph *graph, Vehicle *vehicle);
    ~Heuristic();

    void nearestNeighboor();

    bool everyoneVisited();
};



#endif