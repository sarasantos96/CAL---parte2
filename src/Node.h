#ifndef SRC_NODE_H_
#define SRC_NODE_H_

class Node{
	int node_id;
	double lat_degree;
	double lon_degree;
	double lat_rad;
	double lon_rad;
public:
	Node(int node_id, double lat_degree, double lon_degree,
			double lat_rad, double lon_rad);

	double getLatDegree() const;
	void setLatDegree(double latDegree);

	double getLatRad() const;
	void setLatRad(double latRad);

	double getLonDegree() const;
	void setLonDegree(double lonDegree);

	double getLonRad() const;
	void setLonRad(double lonRad);

	int getNodeId() const;
	void setNodeId(int nodeId);
};

#endif
