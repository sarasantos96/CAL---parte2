#ifndef SRC_FILEREADER_H_
#define SRC_FILEREADER_H_
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Node.h"
#include "Road.h"

using namespace std;

vector<Node> readNodes();
vector<Road> readRoads();

#endif
