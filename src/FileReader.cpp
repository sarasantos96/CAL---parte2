#include "FileReader.h"

#define NODES 		"nodes.txt"
#define ROADS 		"roads.txt"
#define SUBROADS 	"subroads.txt"

Graph<Node,Road> g;

void loadGraph(Graph<Node,Road> g){
	readNodes(g);
	vector<Road> roads = readRoads();
	readSubRoads(g,roads);
}

Node findNode(Graph<Node,Road> & g, int node_id){
	for(int i = 0; i < g.getNumVertex(); i++){
		if(node_id == g.getVertexSet()[i]->getInfo().getNodeId())
			return g.getVertexSet()[i]->getInfo();
	}
	return Node(-1,Point(0,0),Point(0,0));
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
	unsigned int node_id;
	double lat_deg, lon_deg, lon_rad, lat_rad;
	infile.open(NODES);

	while(getline(infile,line)){
		stringstream linestream(line);
		string data;

		linestream >> node_id;
		getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> lat_deg;
		getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> lon_deg;
		getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> lon_rad;
		getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> lat_rad;

		Node n(node_id, Point(lon_deg,lat_deg), Point(lon_rad,lat_rad));

		stringstream label;
		label << node_id;
		string result = label.str();

		g.addVertex(n);
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

		if(r.getRoadId() != -1){
			g.addEdge(node_1,node_2,r,distance);
		}
	}

	infile.close();
}
