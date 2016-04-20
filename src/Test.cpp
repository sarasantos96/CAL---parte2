#include <iostream>
#include "FileReader.h"
#include "Graph.h"

using namespace std;

int main(int argc, char const *argv[]){
	vector<Vertex> nodes = readNodes();
	vector<Road> roads = readRoads();
	vector<Subroad> subroads = readSubRoads();

    return 0;
}



