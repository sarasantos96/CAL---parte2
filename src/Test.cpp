/*#include <iostream>
#include "FileReader.h"
#include "Graph.h"
#include "Node.h"

using namespace std;

int main(int argc, char const *argv[]){
	Graph<Node,Road> g;

	g.addVertex(Node(0,Point(0,0),Point(0,0)));

	readNodes(g);
	vector<Road> roads = readRoads();
	readSubRoads(g,roads);

	vector<Vertex<Node,Road>* > vs = g.getVertexSet();

    return 0;
}*/



