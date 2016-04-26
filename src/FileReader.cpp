#include "FileReader.h"
#include "graphviewer.h"

#define NODES 		"nodes.txt"
#define ROADS 		"roads.txt"
#define SUBROADS 	"subroads.txt"

Graph<Node,Road> g;
GraphViewer *gv;

void loadGraph(Graph<Node,Road> &g){
	readNodes(g);
	vector<Road> roads = readRoads();
	readSubRoads(g,roads);

	/*gv = new GraphViewer(600, 600, true);
	gv->createWindow(600, 600);
	gv->defineEdgeDashed(true);
	gv->defineVertexColor("blue");
	gv->defineEdgeColor("black");*/

}

Node findNode(Graph<Node,Road> & g, int node_id){
	for(int i = 0; i < g.getNumVertex(); i++){
		if(node_id == g.getVertexSet()[i]->getInfo().getNodeId())
			return g.getVertexSet()[i]->getInfo();
	}
	return Node(-1,Point(0,0),Point(0,0), "");
}

Road findRoad(vector<Road> r, int road_id){
	for(unsigned int i = 0; i < r.size(); i++){
		if(road_id == r[i].getRoadId()) return r[i];
	}
	return Road(-1,"",false);
}

/*node_id;lat_deg;lon_deg;lon_rad;lat_rad*/
void readNodes(Graph<Node,Road> & g){
	ifstream infile;
	string line;
	infile.open(NODES);

	while(getline(infile,line)){
		stringstream linestream(line);
		string data;

		unsigned int node_id;
		double x, y, x_r, y_r;
		string nome = "";

		linestream >> node_id;
		getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> x;
		getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> y;
		getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> x_r;
		getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> y_r;
		getline(linestream, data, ';');
		linestream >> nome;

		Node n(node_id, Point(x,y), Point(x_r,y_r), nome);

		g.addVertex(n);
		//gv->addNode(node_id,x,y);
	}

	infile.close();
}

//road_id;road_name;is_two_way(yes/no)
vector<Road> readRoads(){
	ifstream infile;
	vector<Road> roads;
	string line;
	int road_id;
	string road_name, is_two_way;
	infile.open(ROADS);

	while(getline(infile,line)){
		stringstream linestream(line);
		string data;

		linestream >> road_id;
		getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> road_name;
		getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> is_two_way;

		if(is_two_way == "False") roads.push_back(Road(road_id,road_name,false));
		else roads.push_back(Road(road_id,road_name,true));
	}

	infile.close();
	return roads;
}

//road_id;node1_id;node2_id;
void readSubRoads(Graph<Node,Road> &g, vector<Road> roads){
	ifstream infile;
	string line;
	int road_id, node1_id, node2_id;
	infile.open(SUBROADS);

	while(getline(infile,line)){
		stringstream linestream(line);
		string data;

		linestream >> road_id;
		getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> node1_id;
		getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> node2_id;

		Node node_1 = findNode(g,node1_id);
		Node node_2 = findNode(g,node2_id);
		Point d1 = node_1.getPointDegree();
		Point d2 = node_2.getPointDegree();

		double distance = sqrt(pow((d1.getX() - d2.getX()),2) + pow((d1.getY() - d2.getY()),2));

		Road r = findRoad(roads, road_id);

		if(r.isIsTwoWay()){
			g.addEdge(node_1,node_2,r,distance);
			g.addEdge(node_2,node_1,r,distance);
		}else{
			g.addEdge(node_1,node_2,r,distance);
			//gv->addEdge(road_id,node1_id,node2_id,0);
		}
	}

	infile.close();
}
