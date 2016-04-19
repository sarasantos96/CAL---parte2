#include "Node.h"

Node:: Node(int node_id, int lat_degree, int lon_degree,
			int lat_rad, int lon_rad) : node_id(node_id),
			lat_degree(lat_degree), lon_degree(lon_degree),
			lat_rad(lat_rad), lon_rad(lon_rad){}

int Node:: getLatDegree() const {
	return lat_degree;
}

void Node:: setLatDegree(int latDegree) {
	lat_degree = latDegree;
}

int Node:: getLatRad() const {
	return lat_rad;
}

void Node:: setLatRad(int latRad) {
	lat_rad = latRad;
}

int Node:: getLonDegree() const {
	return lon_degree;
}

void Node:: setLonDegree(int lonDegree) {
	lon_degree = lonDegree;
}

int Node:: getLonRad() const {
	return lon_rad;
}

void Node:: setLonRad(int lonRad) {
	lon_rad = lonRad;
}

int Node:: getNodeId() const {
	return node_id;
}

void Node:: setNodeId(int nodeId) {
	node_id = nodeId;
}
