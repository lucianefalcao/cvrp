#include "../includes/heuristic.h"

Heuristic::Heuristic(Model *model, Graph *graph, Vehicle *vehicle)
{
    this->model = model;
    this->graph = graph;
    this->vehicle = vehicle;
}

void Heuristic::nearestNeighboor()
{
    int shortestDistance = std::numeric_limits<int>::max();
    int i = 0;
    int client = 0;
    int visitedCients = 0;

    while (visitedCients < model->getDimension())
    {
        i = client;

        for (int j = 1; j < model->getDimension(); ++j)
        {
            if(graph->getMatrix()[i][j] < shortestDistance) 
            {
                if (model->getClients()[j].inRoute() == false)
                {
                    client = j;
                    shortestDistance = graph->getMatrix()[i][j];
                }
                
            }
        }

        if (model->getClients()[client].inRoute() == false)
        {
            if (vehicle->fits(model->getClients()[client].getDemand()))
            {
                model->getClients()[client].setInRoute();
                vehicle->addClientToRoute(model->getClients()[client]);
            }
            
        }

        ++visitedCients;
        
    }
    
}