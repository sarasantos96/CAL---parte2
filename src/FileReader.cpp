#include "FileReader.h"

#define NODES 		"nodes.txt"
#define ROADS 		"roads.txt"
#define SUBROADS 	"subroads.txt"

using namespace std;
/*node_id;lat_deg;lon_deg;lon_rad;lat_rad*/
vector<Node> readNodes(){
	ifstream infile;
	vector<Node> nodes;
	string line;
	int node_id;
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

		nodes.push_back(Node(node_id,lat_deg,lon_deg,lat_rad,lon_rad));
	}

	infile.close();
	return nodes;
}

vector<Road> readRoads(){
	//road_id;road_name;is_two_way(yes/no)
	ifstream infile;
	vector<Road> roads;
	string line;
	int road_id;
	string road_name;
	bool is_two_way;
	infile.open(ROADS);

	while(getline(infile,line)){
		stringstream linestream(line);
		string data;

		linestream >> road_id;
		getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> road_name;
		getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		linestream >> is_two_way;

		roads.push_back(Road(road_id,road_name,is_two_way));
	}

	infile.close();
	return roads;
}

void readSubRoads(){
//road_id;node1_id;node2_id;


}
