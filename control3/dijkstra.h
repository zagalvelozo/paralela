#pragma once

#include <string>

#include "map.h"

std::string getnamestation(int id);

int getidstation(std::string sigla);

void dijkstra(const Map &m, const int initialNodeName, const int goalNodeName, const int mpiNodesCount);

void dijkstraWorker(int mpiNodeId, int mpiWorkerNodes);
