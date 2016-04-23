/*#include <iostream>
#include "FileReader.h"
#include "Graph.h"
#include "Node.h"

using namespace std;

int main(){
	cout<<"0\n";
	Graph<Node,Road> g;
	cout<<"1\n";
	g.addVertex(Node(0,Point(0,0),Point(0,0)));

	cout<<"2\n";
	readNodes(g);
	vector<Road> roads = readRoads();
	cout<<"3\n";
	readSubRoads(g,roads);

	cout<<"4\n";
	vector<Vertex<Node,Road>* > vs = g.getVertexSet();
	cout<<"5\n";

    return 0;
}

*/

