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