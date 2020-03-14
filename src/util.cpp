#include "../includes/util.h"

void printSolution(std::vector<Vehicle*> v, std::string nbd)
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
}