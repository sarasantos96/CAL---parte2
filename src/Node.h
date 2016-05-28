#ifndef SRC_NODE_H_
#define SRC_NODE_H_

#include "Point.h"
#include <string>
#include <cmath>

using namespace std;

class Node{
	unsigned int node_id;
	string hotel;
	string morada;
	Point p_degree;
	Point p_radian;
public:
	Node(int node_id, Point p_degree, Point p_radian, string hotel, string morada);

	Point getPointDegree() const;
	void setPointDegree(Point p_degree);

	Point getPointRadian() const;
	void setPointRadian(Point p_radian);

	int getNodeId() const;
	void setNodeId(int nodeId);

	string getHotelName() const;
	void setHotelName(string hotel);

	string getMorada() const;
	void setMorada(string morada);

	bool operator==(const Node& rhs) const{
		if(node_id == rhs.getNodeId()) return true;
		return false;
	}
	bool operator < (const Node & rhs) const{
		if(node_id < rhs.getNodeId()) return true;
		return false;
	}

	bool operator != (const Node & rhs) const{
		return (node_id != rhs.getNodeId());
	}
};





#endif
