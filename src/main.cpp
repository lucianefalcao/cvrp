#include "../includes/fileReader.h"

int main(int argc, char** argv)
{

    int fileNumber;
    int iterations;
    std::string path = "instances/";

    while (true)
    {
        std::cout << "Digite um numero para selecionar o arquivo ou 0 para sair" << std::endl;

        std::cout << "0 - Exit" << std::endl;
        std::cout << "1 - P-n16-k8" << std::endl;
        std::cout << "2 - P-n19-k2" << std::endl;
        std::cout << "3 - P-n20-k2" << std::endl;
        std::cout << "4 - P-n23-k8" << std::endl;
        std::cout << "5 - P-n45-k5" << std::endl;
        std::cout << "6 - P-n50-k10" << std::endl;
        std::cout << "7 - P-n51-k10" << std::endl;
        std::cout << "8 - P-n55-k7" << std::endl;

        std::cin >> fileNumber;

        std::cout << "Digite o número de repetições" << std::endl;
        std::cin >> iterations; 

        switch (fileNumber)
        {
        case 0:
            std::exit(0);
        case 1:
            path += "P-n16-k8.txt";
            readFile(path, iterations);
            std::exit(0);
        case 2:
            path += "P-n19-k2.txt";
            readFile(path, iterations);
            std::exit(0);
        case 3:
            path += "P-n20-k2.txt";
            readFile(path, iterations);
            std::exit(0);
        case 4: 
            path += "P-n23-k8.txt";
            readFile(path, iterations);
            std::exit(0);
        case 5:
            path += "P-n45-k5.txt";
            readFile(path, iterations);
            std::exit(0);
        case 6:
            path += "P-n50-k10.txt";
            readFile(path, iterations);
            std::exit(0);
        case 7:
            path += "P-n51-k10.txt";
            readFile(path, iterations);
            std::exit(0);
        case 8:
            path += "P-n55-k7.txt";
            readFile(path, iterations);
            std::exit(0);
        default:
            break;
        }

    }

    return 0;
}