#ifndef FILEREADER_H
#define FILEREADER_H

#include "demands.h"

#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

void readFile(std::string);
void readDimensionAndCapacity();
void skipLine(int lines);
void readDemands();

#endif