#include "../includes/heuristic.h"

// TODO: adicionar comentários

Heuristic::Heuristic(){}

void Heuristic::setModel(Model *model)
{
    this->model = model;
}

void Heuristic::setGraph(Graph *graph)
{
    this->graph = graph;
}

void Heuristic::createVehicle(int capacity)
{
    this->vehicle = new Vehicle();
    vehicle->setCapacity(capacity);
    vehicle->setLoad();
    // Adiciona o depósito como o início da rota
    vehicle->addClientToRoute((*model->getClients()[0]));
    addVehicle(vehicle);
}

void Heuristic::addVehicle(Vehicle *v)
{
    vehicles.push_back(v);
}

void Heuristic::nearestNeighboor()
{
    int i, client;
    int visitedClients = 0;
    // O problema tem pelo menos um caminho
    int numberOfVehicles = 1;

    while (numberOfVehicles)
    {
        client = 0;


        while (visitedClients < model->getDimension()-1)
        {
            i = client;
            int shortestDistance = std::numeric_limits<int>::max();

            for (int j = 1; j < model->getDimension(); ++j)
            {
                if((graph->getMatrix()[i][j] != 0) && (graph->getMatrix()[i][j] < shortestDistance)) 
                {
                    if((*model->getClients()[j]).inRoute() == false)
                    {
                        if (vehicles[numberOfVehicles-1]->CheckDelivery((*model->getClients()[j]).getDemand()))
                        {
                            client = j;
                            shortestDistance = graph->getMatrix()[i][j];
                        }
                    }
                }
            }

            // Verifica se o caminhão já entregou todas as demandas
            if(client == i)
            {   
                if(visitedClients < model->getDimension()-1)
                {
                    // Adiciona o depósito no final da rota
                    vehicles[numberOfVehicles-1]->addClientToRoute((*model->getClients()[0]));
                    vehicles[numberOfVehicles-1]->setCost(graph->getMatrix()[client][0]);
                    // cost += graph->getMatrix()[client][0];
                    // Cria um novo caminhão
                    createVehicle(this->vehicle->getCapacity());
                    ++numberOfVehicles;
                }
                else
                { 
                    // Verificar
                    numberOfVehicles = 0;
                }
                break;
                
            }
            else
            {
                int d =(*model->getClients()[client]).getDemand();
                vehicles[numberOfVehicles-1]->calculateLoad(d);
                (*model->getClients()[client]).setInRoute();
                vehicles[numberOfVehicles-1]->addClientToRoute((*model->getClients()[client]));
                vehicles[numberOfVehicles-1]->setCost(graph->getMatrix()[i][client]);
            }

            ++visitedClients;
            if(visitedClients == model->getDimension()-1)
            {
                // Adiciona o depósito ao final da rota
                vehicles[numberOfVehicles-1]->addClientToRoute((*model->getClients()[0]));
                vehicles[numberOfVehicles-1]->setCost(graph->getMatrix()[client][0]);
                // Zera o números de veículos
                numberOfVehicles = 0;
            }
            
        }
    }
    vehicle->printRoute(vehicles);
}