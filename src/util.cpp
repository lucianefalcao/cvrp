#include "../includes/util.h"

int getTotalCost(std::vector<Vehicle*> v)
{
    int totalCost = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        totalCost += v[i]->getCost();
    }
    
    return totalCost;
}

int printSolution(std::vector<Vehicle*> v, std::string nbd)
{
    int totalCost = 0;
    std::cout << "\n" << nbd << ":\n";

    for (int i = 0; i < v.size(); ++i)
    {
        std::cout << "\nCaminhão " << i+1 << ": ";
        for(int j = 0; j < v[i]->getRoute().size()-1; ++j)
        {
            std::cout << v[i]->getRoute()[j].getID() << " -> ";
        }
        std::cout << "0\n";
        std::cout << "Custo da rota: " << v[i]->getCost() << "\n";
        totalCost += v[i]->getCost();
    }
    std:: cout << '\n';
    std::cout << "Custo total: "<< totalCost << "\n";

    return totalCost;
}

int buildIntraSolution(std::vector<Vehicle*> v, LocalSearch *search)
{
    int totalCost = 0;
    int distance;
    std::vector<Client> r;
    
    for(int i = 0; i < v.size(); ++i)
    {
        r = v[i]->getRoute();
        distance = v[i]->getCost();
        search->vnd(r, &distance);
        v[i]->setRoute(r);
        v[i]->setCost(distance);
        totalCost += v[i]->getCost();
    }

    return totalCost;
}

int buildInterSolution(std::vector<Vehicle*> v, LocalSearch *search)
{
    int Acost, Bcost;
    int totalCost = 0;
    std::vector<Client> a, b;

    for (int k = 0; k < v.size(); ++k)
    {
        Acost = v[k]->getCost(); // custo da rota A
        a = v[k]->getRoute(); // rota A
        int loadA = v[k]->getLoad(); // Capacidade restante do veículo A
        for (int l = k+1; l < v.size(); ++l)
        {
            Bcost = v[l]->getCost(); // custo da rota B
            b = v[l]->getRoute(); // rota B
            int loadB = v[l]->getLoad(); // Capacidade restante do veículo B
            search->interVND(a, b, &Acost, &Bcost, &loadA, &loadB);
            // Atualiza os valores dos veículos A e B 
            v[k]->setRoute(a);
            v[l]->setRoute(b);
            v[k]->setCost(Acost);
            v[l]->setCost(Bcost);
            v[k]->setLoad(loadA);
            v[l]->setLoad(loadB);
        }

        totalCost += v[k]->getCost();
    }

    return totalCost;
}