#ifndef SRC_NODE_H_
#define SRC_NODE_H_

class Node{
	int node_id;
	int lat_degree;
	int lon_degree;
	int lat_rad;
	int lon_rad;
public:
	Node(int node_id, int lat_degree, int lon_degree,
			int lat_rad, int lon_rad);

	int getLatDegree() const;
	void setLatDegree(int latDegree);

	int getLatRad() const;
	void setLatRad(int latRad);

	int getLonDegree() const;
	void setLonDegree(int lonDegree);

	int getLonRad() const;
	void setLonRad(int lonRad);

	int getNodeId() const;
	void setNodeId(int nodeId);
};

#endif
