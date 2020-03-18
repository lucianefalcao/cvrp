#ifndef VND_H
#define VND_H

#include "twoOpt.h"
#include "swap.h"
#include "reinsertion.h"
#include "vehicle.h"
#include "graph.h"

class LocalSearch
{
private:
    TwoOpt *opt;
    Swap *swap;
    Reinsertion *reinsertion;
    Graph *graph;
public:
    LocalSearch(Graph *graph);
    ~LocalSearch();
    void vnd(std::vector<Vehicle*> v, int);
    void set2OPT();
    void setSwap();
    void setReinsertion();
};




#endif