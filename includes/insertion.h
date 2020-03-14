#ifndef INSERTION_H
#define INSERTION_H

#include "graph.h"
#include "client.h"
#include "vehicle.h"

#include <vector>

class Insertion
{
private:
    /* data */
    Graph *graph;
public:
    Insertion(/* args */);
    
    void setGraph(Graph *graph);
    void buildSolution(std::vector<Vehicle*> v);

    int getMovement(std::vector<Client>& route, int currentDistance);

    std::vector<Client> move(std::vector<Client>&, int, int);
};


#endif