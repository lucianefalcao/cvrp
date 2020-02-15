#ifndef FILEREADER_H
#define FILEREADER_H

#include "client.h"
#include "vehicle.h"
#include "model.h"
#include "graph.h"

#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>

void readFile(std::string);
void readDimensionAndCapacity();
void skipLine(int lines);
void setClients();
void readMatrix();

#endif