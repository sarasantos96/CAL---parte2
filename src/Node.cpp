#include "Node.h"

Node:: Node(int node_id, double lat_degree, double lon_degree,
			double lat_rad, double lon_rad) : node_id(node_id),
			lat_degree(lat_degree), lon_degree(lon_degree),
			lat_rad(lat_rad), lon_rad(lon_rad){}

double Node:: getLatDegree() const {
	return lat_degree;
}

void Node:: setLatDegree(double latDegree) {
	lat_degree = latDegree;
}

double Node:: getLatRad() const {
	return lat_rad;
}

void Node:: setLatRad(double latRad) {
	lat_rad = latRad;
}

double Node:: getLonDegree() const {
	return lon_degree;
}

void Node:: setLonDegree(double lonDegree) {
	lon_degree = lonDegree;
}

double Node:: getLonRad() const {
	return lon_rad;
}

void Node:: setLonRad(double lonRad) {
	lon_rad = lonRad;
}

int Node:: getNodeId() const {
	return node_id;
}

void Node:: setNodeId(int nodeId) {
	node_id = nodeId;
}
