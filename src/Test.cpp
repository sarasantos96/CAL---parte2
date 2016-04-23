#include <iostream>
#include "FileReader.h"
#include "Graph.h"
#include "Node.h"

using namespace std;

int main(int argc, char const *argv[]){
	Graph<Node,Road> g;
	loadGraph(g);
    return 0;
}
