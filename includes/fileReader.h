#ifndef FILEREADER_H
#define FILEREADER_H

#include "client.h"
#include "vehicle.h"

#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

void readFile(std::string);
void readDimensionAndCapacity();
void skipLine(int lines);
void setClients();

#endif