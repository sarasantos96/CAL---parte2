#include "Node.h"

Node:: Node(int node_id, Point p_degree, Point p_radian) : node_id(node_id), p_degree(p_degree), p_radian(p_radian){}

Point Node:: getPointDegree() const{return p_degree;}
void Node:: setPointDegree(Point p_degree){this->p_degree = p_degree;}

Point Node:: getPointRadian() const{return p_radian;}
void Node:: setPointRadian(Point p_radian){this->p_radian = p_radian;}

int Node:: getNodeId() const {return node_id;}
void Node:: setNodeId(int nodeId){this->node_id = nodeId;}

bool Node::operator ==(const Node& rhs) const{
	return node_id == rhs.getNodeId();
}
