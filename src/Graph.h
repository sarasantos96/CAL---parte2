/*
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>
#include <list>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include "Point.h"

using namespace std;

class Edge;
class Graph;

const int NOT_VISITED = 0;
const int BEING_VISITED = 1;
const int DONE_VISITED = 2;
const int INT_INFINITY = INT_MAX;

/*
 * ================================================================================================
 * Class Vertex
 * ================================================================================================
 */
class Vertex {
	int id;
	Point p_degree;
	Point p_rad;

	double distance;
	bool visited;
	bool processing;
	int indegree;

	vector<Edge> adj;
public:
	Vertex(int id, Point p_degree, Point p_rad);
	friend class Graph;
	friend class Edge;

	void addEdge(Vertex *dest, double w);
	bool removeEdgeTo(Vertex *d);

	int getId() const;
	void setId(int id);

	double getDistance() const;
	void setDistance(double distance);

	int getIndegree() const;

	void incIndegree();
	void decIndegree();

	bool getVisited() const;
	void setVisited(bool visited);

	bool getProcessing() const;
	void setProcessing(bool processing);

	Point getPointDegree() const;
	void setPointDegree(Point p_degree);

	Point getPointRad() const;
	void setPointRad(Point p_rad);

	vector<Edge> getAdj() const;
	void setAdj(vector<Edge> adj);

	bool operator<(const Vertex vertex);

	Vertex* path;
};

/* ================================================================================================
 * Class Edge
 * ================================================================================================
 */
class Edge{
	Vertex* destination;
	double weight;
public:
	friend class Vertex;
	Edge(Vertex *d, double w);

	Vertex* getDestination() const;

	double getWeight() const;
};


/* ================================================================================================
 * Class Graph
 * ================================================================================================
 */
class Graph {
	vector<Vertex *> vertexSet;

	int numCycles;
	void dfsVisit(Vertex *v);
	void dfsVisit();
	void getPathTo(Vertex *origin, vector<Vertex> &res);

	int ** W;   //weight
	int ** P;   //path
public:
	bool addVertex(const Vertex &in);
	bool addEdge(const Vertex &sourc, const Vertex &dest, double w);
	bool removeVertex(const Vertex &in);
	bool removeEdge(const Vertex &sourc, const Vertex &dest);

	vector<Vertex*> dfs() const;
	void dfs(Vertex *v, vector<Vertex*> &res) const;

	vector<Vertex*> bfs(Vertex *v) const;
	vector<Vertex *> getVertexSet() const;
	int getNumVertex() const;


	Vertex* getVertex(const Vertex &v) const;
	void resetIndegrees();
	vector<Vertex*> getSources() const;
	int getNumCycles();
	vector<Vertex*> topologicalOrder();
	vector<Vertex*> getPath(const Vertex &origin, const Vertex &dest);
	void unweightedShortestPath(const Vertex &v);
	bool isDAG();

	void bellmanFordShortestPath(const Vertex &s);
	void dijkstraShortestPath(const Vertex &s);
	void floydWarshallShortestPath();
	int edgeCost(int vOrigIndex, int vDestIndex);
	vector<Vertex*> getfloydWarshallPath(const Vertex &origin, const Vertex &dest);
	void getfloydWarshallPathAux(int index1, int index2, vector<Vertex*> & res);
};

#endif /* GRAPH_H_ */
