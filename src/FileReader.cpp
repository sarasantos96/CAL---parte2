#include "FileReader.h"

#define NODES 		"nodes.txt"
#define ROADS 		"roads.txt"
#define SUBROADS 	"subroads.txt"

using namespace std;

/*node_id;lat_deg;lon_deg;lon_rad;lat_rad*/
vector<Vertex> readNodes(){
	ifstream infile;
	vector<Vertex> nodes;
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
		nodes.push_back( Vertex(node_id, Point(lon_deg,lat_deg), Point(lon_rad,lat_rad)) );
	}

	infile.close();
	return nodes;
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
vector<Subroad> readSubRoads(){
	ifstream infile;
	vector<Subroad> subroads;
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

		subroads.push_back(Subroad(road_id,node1_id,node2_id));
	}

	infile.close();
	return subroads;
}
