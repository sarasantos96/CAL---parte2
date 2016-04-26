#include <iostream>
#include "AirShuttle.h"
#include "FileReader.h"
#include "Graph.h"
#include "Node.h"
#include "main.h"

using namespace std;

/*
int main(){
	Graph<Node,Road> g;
	loadGraph(g);

	g.dijkstraShortestPath(g.getVertex(1)->getInfo());
		vector<Node> fim1 = g.getPath(g.getVertex(1)->getInfo(),g.getVertex(2)->getInfo());

	g.dijkstraShortestPath(g.getVertex(2)->getInfo());
	vector<Node> fim2 = g.getPath(g.getVertex(2)->getInfo(),g.getVertex(5)->getInfo());

	g.dijkstraShortestPath(g.getVertex(5)->getInfo());
	vector<Node> fim3 = g.getPath(g.getVertex(5)->getInfo(),g.getVertex(3)->getInfo());

	for(unsigned int i = 1; i < fim1.size(); i++){
		cout << fim1[i].getNodeId() << endl;
	}
	cout << endl;
	for(unsigned int i = 1; i < fim2.size(); i++){
		cout << fim2[i].getNodeId() << endl;
	}
	cout << endl;
	for(unsigned int i = 1; i < fim3.size(); i++){
		cout << fim3[i].getNodeId() << endl;
	}

    return 0;
}
*/
