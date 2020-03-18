#include "../includes/localSearch.h"

LocalSearch::LocalSearch(Graph *graph)
{
    this->graph = graph;

    setSwap();
    set2OPT();
    setReinsertion();
};

void LocalSearch::set2OPT()
{
    this->opt = new TwoOpt();
    this->opt->setGraph(graph);
}

void LocalSearch::setReinsertion()
{
    this->reinsertion = new Reinsertion();
    this->reinsertion->setGraph(graph);
}

void LocalSearch::setSwap()
{   
    this->swap = new Swap();
    this->swap->setGraph(graph);
}

void LocalSearch::vnd(std::vector<Vehicle*> v, int currentDistance)
{
    int k = 0;
    int bestDistance = currentDistance;
    bool improv = true;

    while (improv)
    {
        k = 1;
        improv = false;

        while (k <= 3)
        {
            switch (k)
            {
                case 1:
                    bestDistance = swap->buildSolution(v);
                    break;
                case 2:
                    bestDistance = opt->buildSolution(v);
                    break;
                case 3:
                    bestDistance = reinsertion->buildSolution(v);
                    break;
                default:
                    break;
            }

             if(bestDistance < currentDistance)
            {
                improv = true;
                currentDistance = bestDistance;
                k = 1;
            }
            else
            {
                ++k;
                improv = false;
            }
        }
    }
}