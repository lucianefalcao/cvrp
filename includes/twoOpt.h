#ifndef TWOOPT_H
#define TWOOPT_H

#include "client.h"
#include "graph.h"
#include "vehicle.h"

#include <vector>
#include <limits>

class TwoOpt
{
private:
    /* data */
    Graph *graph;
public:
    TwoOpt(/* args */);

    void setGraph(Graph *graph);

    int buildSolution(std::vector<Vehicle*> v);
    int getMovement(std::vector<Client>&, int);

    std::vector<Client> change(std::vector<Client>&, int, int);
};


#endif