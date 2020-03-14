#ifndef SWAP_H
#define SWAP_H

#include "vehicle.h"
#include "graph.h"

#include <vector>

class Swap
{
private:
    Graph *graph;
public:
    Swap(/* args */);

    void setGraph(Graph *graph);
    void printSolution(std::vector<Vehicle*> v);
    void getMovement(std::vector<Client>&, std::vector<Client>&, int*, int*, int, int*, int*);
};


#endif