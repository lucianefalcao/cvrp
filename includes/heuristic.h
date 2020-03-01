#ifndef HEURISTIC_H
#define HEURISTIC_H

#include "model.h"
#include "twoOpt.h"
#include "vehicle.h"

#include <limits>

class Heuristic
{
private:
    Model *model;
    Graph *graph;
    TwoOpt *opt;
    Vehicle *vehicle = NULL;
    std::vector<Vehicle*> vehicles;
public:
    Heuristic();
    ~Heuristic();

    void nearestNeighboor();
    void addVehicle(Vehicle *v);
    void setModel(Model *model);
    void setGraph(Graph *graph);
    void set2OPT(TwoOpt *opt);
    void createVehicle(int);

};



#endif