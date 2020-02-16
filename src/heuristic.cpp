#include "../includes/heuristic.h"

// TODO: adicionar comentários

Heuristic::Heuristic(Model *model, Graph *graph, Vehicle *vehicle)
{
    this->model = model;
    this->graph = graph;
    this->vehicle = vehicle;
}

void Heuristic::nearestNeighboor()
{
    int i = 0;
    int client = 0;
    int visitedCients = 0;

    while (visitedCients < model->getDimension())
    {
        i = client;
        int shortestDistance = std::numeric_limits<int>::max();

        for (int j = 1; j < model->getDimension(); ++j)
        {
            if((graph->getMatrix()[i][j] != 0) && (graph->getMatrix()[i][j] < shortestDistance)) 
            {
                if((*model->getClients()[j]).inRoute() == false)
                {
                    if (vehicle->fits((*model->getClients()[j]).getDemand()))
                    {
                        client = j;
                        shortestDistance = graph->getMatrix()[i][j];
                    }
                }
            }
        }

        if ((*model->getClients()[client]).inRoute() == false)
        {
            vehicle->setCarga((*model->getClients()[client]).getDemand());
            (*model->getClients()[client]).setInRoute();
            vehicle->addClientToRoute((*model->getClients()[client]));
        }

        ++visitedCients;
        
    }
    
}