#include "../includes/heuristic.h"

// TODO: adicionar comentários

Heuristic::Heuristic(Model *model, Graph *graph, Vehicle *vehicle)
{
    this->model = model;
    this->graph = graph;
    this->vehicle = vehicle;
}

bool Heuristic::everyoneVisited()
{
    for (int i = 1; i < model->getClients().size(); ++i)
    {
        if(!(*model->getClients()[i]).inRoute())
            return true;
    }

    return false;
    
}

void Heuristic::nearestNeighboor()
{
    int i, client;
    int visitedClients = 0;
    int cost = 0;

    // Adiciona o depósito como o início da rota
    vehicle->addClientToRoute((*model->getClients()[0]));

    // Mudar este laço
    while (everyoneVisited())
    {
        client = 0;
        vehicle->setCarga(0);

        while (visitedClients < model->getDimension())
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

            if(client == i)
            {
                // TODO: implementar quando a demanda não cabe
            }

            if ((*model->getClients()[client]).inRoute() == false)
            {
                vehicle->setCarga((*model->getClients()[client]).getDemand());
                (*model->getClients()[client]).setInRoute();
                vehicle->addClientToRoute((*model->getClients()[client]));
            }

            ++visitedClients;
            
        }

        // Adiciona o depósito ao final da rota
        vehicle->addClientToRoute((*model->getClients()[0]));
        vehicle->printRoute();
    }
    

    
    
}