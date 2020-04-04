#include "../includes/heuristic.h"

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
    this->vehicleAux = new Vehicle();
    vehicleAux->setCapacity(capacity);
    vehicleAux->setLoad(capacity);
    // Adiciona o depósito como o início da rota
    vehicleAux->addClientToRoute((*model->getClients()[0]));
    addVehicle(vehicleAux);
}

void Heuristic::addVehicle(Vehicle *v)
{
    vehicles.push_back(v);
}

void Heuristic::nearestNeighboor(int iterations)
{
    std::chrono::duration<double, std::milli> hc;
    std::chrono::duration<double, std::milli> vnd;

    for(int k = 0; k < iterations; ++k)
    {
        // Guarda o tempo inicial da heurística
        auto startT1 = std::chrono::high_resolution_clock::now();
        int i, client = 0;
        int visitedClients = 0;
        // O problema tem pelo menos um caminhão
        int numberOfVehicles = 1;
        bool change;
        int c[model->getDimension()-1];
        int aux;
        int s;
        while (numberOfVehicles && (visitedClients < model->getDimension()-1))
        {
            s = 0;
            i = client;
            change = false;
            int shortestDistance = std::numeric_limits<int>::max();

            for (int j = 1; j < model->getDimension(); ++j)
            {
                // graph->getFirstRow();
                if((graph->getMatrix()[i][j] != 0) && (graph->getMatrix()[i][j] < shortestDistance) && 
                (*model->getClients()[j]).inRoute() == false) 
                {
                    if(!visitedClients && !i) 
                    {
                        c[s] = j;
                        ++s;
                        if(s == model->getDimension()-1)
                        {
                            aux = rand() % model->getDimension()-1;
                            aux = aux < 0 ? 0 : aux;
                            aux = c[aux];
                            if (vehicles[numberOfVehicles-1]->CheckDelivery((*model->getClients()[aux]).getDemand()))
                            {
                                client = aux;
                                shortestDistance = graph->getMatrix()[i][aux];
                                change = true;
                            }
                        }
                    }
                    else 
                    {
                        if (vehicles[numberOfVehicles-1]->CheckDelivery((*model->getClients()[j]).getDemand()))
                        {
                            client = j;
                            shortestDistance = graph->getMatrix()[i][j];
                            change = true;
                        }
                    }
                }
            }

            if(change)
            {
                vehicles[numberOfVehicles-1]->calculateLoad((*model->getClients()[client]).getDemand());
                (*model->getClients()[client]).setInRoute(true);
                vehicles[numberOfVehicles-1]->addClientToRoute((*model->getClients()[client]));
                vehicles[numberOfVehicles-1]->addCost(graph->getMatrix()[i][client]);
                ++visitedClients;
            }
            else
            {
                // Adiciona o depósito no final da rota
                vehicles[numberOfVehicles-1]->addClientToRoute((*model->getClients()[0]));
                vehicles[numberOfVehicles-1]->addCost(graph->getMatrix()[client][0]);
                // Cria um novo caminhão
                createVehicle(this->vehicleAux->getCapacity());
                ++numberOfVehicles;
                client = 0;
            }
        }

        // Adiciona o depósito ao final da rota
        vehicles[numberOfVehicles-1]->addClientToRoute((*model->getClients()[0]));
        vehicles[numberOfVehicles-1]->addCost(graph->getMatrix()[client][0]);

        std::cout << "\n>>>>>>> " << k << " <<<<<<<" << "\n";

        int totalCost = printSolution(vehicles, "nearest nbd");

        // Guarda o tempo final da heurística
        auto endT1 = std::chrono::high_resolution_clock::now();
        // calcula a duração da heurística

        if(!k)
            hc = (endT1 - startT1);
        else
            hc += (endT1 - startT1);
        
        LocalSearch *localSearch = new LocalSearch(graph);
        buildInterSolution(vehicles, localSearch);
        buildIntraSolution(vehicles, localSearch);
        printSolution(vehicles, "final");


        auto endT2 = std::chrono::high_resolution_clock::now();
        

        if(!k)
            vnd = (endT2-startT1);
        else
            vnd += (endT2-startT1);

        erase();
    }

    
    std::cout << "A heurística levou em média " << hc.count() / iterations << " ms\n";  
    // guarda o tempo final da heuristica + vnd
    std::cout << "A heurística + vnd levou em média " << vnd.count() / iterations << " ms\n";  

}

void Heuristic::erase()
{
    vehicles.clear();
    createVehicle(this->vehicleAux->getCapacity());
    for(Client *x : model->getClients())
    {
        x->setInRoute(false);
    }
}