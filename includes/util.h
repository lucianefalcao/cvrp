#ifndef UTIL_H
#define UTIL_H

#include "vehicle.h"
#include "localSearch.h"

#include <vector>
#include <string>


int printSolution(std::vector<Vehicle*> v, std::string);
int getTotalCost(std::vector<Vehicle*> v);

int buildIntraSolution(std::vector<Vehicle*> v, LocalSearch *);
int buildInterSolution(std::vector<Vehicle*> v, LocalSearch *);

#endif