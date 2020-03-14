#ifndef HEURISTIC_H
#define HEURISTIC_H

#include "model.h"
#include "twoOpt.h"
#include "vehicle.h"
#include "swap.h"
#include "insertion.h"
#include "util.h"

#include <limits>

class Heuristic
{
private:
    Model *model;
    Graph *graph;
    TwoOpt *opt;
    Swap *s;
    Insertion *ins;
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
    void setSwap(Swap *s);
    void createVehicle(int);

};



#endif