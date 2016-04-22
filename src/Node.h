#ifndef SRC_NODE_H_
#define SRC_NODE_H_

#include "Point.h"

class Node{
	unsigned int node_id;
	Point p_degree;
	Point p_radian;
public:
	Node(int node_id, Point p_degree, Point p_radian);

	Point getPointDegree() const;
	void setPointDegree(Point p_degree);

	Point getPointRadian() const;
	void setPointRadian(Point p_radian);

	int getNodeId() const;
	void setNodeId(int nodeId);

	bool operator==(const Node& rhs) const;
};





#endif
