#ifndef HEURISTIC_H
#define HEURISTIC_H

#include "model.h"
#include "graph.h"
#include "vehicle.h"
#include "util.h"
#include "localSearch.h"

#include <limits>
#include <chrono>

class Heuristic
{
    private:
        Model *model;
        Graph *graph;
        LocalSearch *localSearch;
        Vehicle *vehicleAux = NULL;
        std::vector<Vehicle*> vehicles;
        
    public:
        Heuristic();
        ~Heuristic();

        void nearestNeighboor(int);
        void addVehicle(Vehicle *v);
        void setModel(Model *model);
        void setGraph(Graph *graph);
        void createVehicle(int);
        void erase();
};



#endif