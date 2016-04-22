#ifndef SRC_FILEREADER_H_
#define SRC_FILEREADER_H_

#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "Graph.h"
#include "Road.h"
#include "Subroad.h"
#include "Point.h"

using namespace std;

vector<Vertex> readNodes();
vector<Road> readRoads();
vector<Subroad> readSubRoads();

#endif
