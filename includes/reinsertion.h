#ifndef REINSERTION_H
#define REINSERTION_H

#include "graph.h"
#include "client.h"
#include "vehicle.h"

#include <vector>

class Reinsertion
{
private:
    /* data */
    Graph *graph;
public:
    Reinsertion(/* args */);
    
    void setGraph(Graph *graph);

    int buildSolution(std::vector<Vehicle*> v);
    int getMovement(std::vector<Client>& route, int currentDistance);

    std::vector<Client> move(std::vector<Client>&, int, int);
};


#endif