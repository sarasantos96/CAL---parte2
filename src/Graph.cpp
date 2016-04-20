#include "Graph.h"

/*
 * ================================================================================================
 * Class Vertex
 * ================================================================================================
 */
Vertex:: Vertex(int node_id, Point p_deg, Point p_r): id(node_id), p_degree(p_deg), p_rad(p_r), distance(0.0),
		visited(false), processing(false), indegree(0), path(NULL){}

int Vertex:: getId() const {return this->id;}
void Vertex:: setId(int id) {this->id = id;}

double Vertex:: getDistance() const {return this->distance;}
void Vertex:: setDistance(double distance) {this->distance = distance;}

int Vertex:: getIndegree() const {return this->indegree;}

void Vertex:: incIndegree() {this->indegree++;}
void Vertex:: decIndegree() {this->indegree--;}

bool Vertex:: getVisited() const {return this->visited;}
void Vertex:: setVisited(bool visited) {this->visited = visited;}

bool Vertex:: getProcessing() const {return this->processing;}
void Vertex:: setProcessing(bool processing) {this->processing = processing;}

Point Vertex:: getPointDegree() const {return this->p_degree;}
void Vertex:: setPointDegree(Point p_degree){this->p_degree = p_degree;}

Point Vertex:: getPointRad() const {return this->p_rad;}
void Vertex:: setPointRad(Point p_rad) {this->p_rad = p_rad;}

vector<Edge> Vertex:: getAdj() const {return this->adj;}
void Vertex:: setAdj(vector<Edge> adj) {this->adj = adj;}

struct vertex_greater_than {
    bool operator()(Vertex* a, Vertex* b) const {
        return a->getDistance() > b->getDistance();
    }
};

void Vertex:: addEdge(Vertex *dest, double w) {
	Edge edgeD(dest,w);
	adj.push_back(edgeD);
}

bool Vertex:: removeEdgeTo(Vertex *d) {
	d->indegree--;
	typename vector<Edge >::iterator it= adj.begin();
	typename vector<Edge >::iterator ite= adj.end();
	while (it!=ite) {
		if (it->getDestination()->getId() == d->getId()) {
			adj.erase(it);
			return true;
		}
		else it++;
	}
	return false;
}

/* ================================================================================================
 * Class Edge
 * ================================================================================================
 */
Edge:: Edge(Vertex *d, double w): destination(d), weight(w){}

Vertex* Edge:: getDestination() const {return destination;}

double Edge:: getWeight() const {return weight;}
/* ================================================================================================
 * Class Graph
 * ================================================================================================
 */
bool Graph:: addVertex(const Vertex &in) {
	typename vector<Vertex *>::iterator it= vertexSet.begin();
	typename vector<Vertex *>::iterator ite= vertexSet.end();
	for (; it!=ite; it++)
		if ((*it)->getId() == in.getId()) return false;
	Vertex *v1 = new Vertex(in);
	vertexSet.push_back(v1);
	return true;
}

bool Graph:: removeVertex(const Vertex &in) {
	typename vector<Vertex *>::iterator it = vertexSet.begin();
	typename vector<Vertex *>::iterator ite = vertexSet.end();
	for (; it!=ite; it++) {
		if ((*it)->getId() == in.getId()) {
			Vertex * v= *it;
			vertexSet.erase(it);
			typename vector<Vertex *>::iterator it1 = vertexSet.begin();
			typename vector<Vertex *>::iterator it1e = vertexSet.end();
			for (; it1!=it1e; it1++) {
				(*it1)->removeEdgeTo(v);
			}

			typename vector<Edge >::iterator itAdj= v->getAdj().begin();
			typename vector<Edge >::iterator itAdje= v->getAdj().end();
			for (; itAdj!=itAdje; itAdj++) {
				itAdj->getDestination()->decIndegree();
			}
			delete v;
			return true;
		}
	}
	return false;
}

bool Graph:: addEdge(const Vertex &sourc, const Vertex &dest, double w) {
	typename vector<Vertex *>::iterator it = vertexSet.begin();
	typename vector<Vertex *>::iterator ite = vertexSet.end();
	int found=0;
	Vertex *vS, *vD;
	while (found!=2 && it!=ite ) {
		if ( (*it)->getId() == sourc.getId() )
			{ vS=*it; found++;}
		if ( (*it)->getId() == dest.getId() )
			{ vD=*it; found++;}
		it ++;
	}
	if (found!=2) return false;
	vD->incIndegree();
	vS->addEdge(vD,w);

	return true;
}

bool Graph:: removeEdge(const Vertex &sourc, const Vertex &dest) {
	typename vector<Vertex *>::iterator it= vertexSet.begin();
	typename vector<Vertex *>::iterator ite= vertexSet.end();
	int found=0;
	Vertex *vS, *vD;
	while (found!=2 && it!=ite ) {
		if ( (*it)->getId() == sourc.getId() )
			{ vS=*it; found++;}
		if ( (*it)->getId() == dest.getId() )
			{ vD=*it; found++;}
		it ++;
	}
	if (found!=2)
		return false;

	vD->decIndegree();

	return vS->removeEdgeTo(vD);
}

vector<Vertex*> Graph:: dfs() const {
	typename vector<Vertex *>::const_iterator it = vertexSet.begin();
	typename vector<Vertex *>::const_iterator ite = vertexSet.end();
	for (; it !=ite; it++)
		(*it)->visited=false;
	vector<Vertex*> res;
	it=vertexSet.begin();
	for (; it !=ite; it++)
	    if ( (*it)->visited==false )
	    	dfs((*it),res);
	return res;
}

void Graph:: dfs(Vertex *v,vector<Vertex*> &res) const {
	v->visited = true;
	res.push_back(v);
	typename vector<Edge >::iterator it= (v->getAdj()).begin();
	typename vector<Edge >::iterator ite= (v->getAdj()).end();
	for (; it !=ite; it++)
	    if ( it->getDestination()->visited == false ){
	    	dfs(it->getDestination(), res);
	    }
}

vector<Vertex*> Graph:: bfs(Vertex *v) const {
	vector<Vertex*> res;
	queue<Vertex *> q;
	q.push(v);
	v->visited = true;
	while (!q.empty()) {
		Vertex *v1 = q.front();
		q.pop();
		res.push_back(v1);
		typename vector<Edge >::iterator it = v1->getAdj().begin();
		typename vector<Edge >::iterator ite = v1->getAdj().end();
		for (; it!=ite; it++) {
			Vertex *d = it->getDestination();
			if (d->visited==false) {
				d->visited=true;
				q.push(d);
			}
		}
	}
	return res;
}

int Graph:: getNumVertex() const {return vertexSet.size();}

vector<Vertex *> Graph:: getVertexSet() const {return vertexSet;}

int Graph:: getNumCycles() {
	numCycles = 0;
	dfsVisit();
	return this->numCycles;
}

bool Graph:: isDAG() {
	return (getNumCycles() == 0);
}

Vertex* Graph:: getVertex(const Vertex &v) const {
	for(unsigned int i = 0; i < vertexSet.size(); i++)
		if (vertexSet[i]->getId() == v.getId()) return vertexSet[i];
	return NULL;
}

void Graph:: resetIndegrees() {
	//colocar todos os indegree em 0;
	for(unsigned int i = 0; i < vertexSet.size(); i++) vertexSet[i]->indegree = 0;

	//actualizar os indegree
	for(unsigned int i = 0; i < vertexSet.size(); i++) {
		//percorrer o vector de Edges, e actualizar indegree
		for(unsigned int j = 0; j < vertexSet[i]->adj.size(); j++) {
			vertexSet[i]->adj[j].getDestination()->incIndegree();
		}
	}
}

vector<Vertex*> Graph:: getSources() const {
	vector< Vertex* > buffer;
	for(unsigned int i = 0; i < vertexSet.size(); i++) {
		if( vertexSet[i]->indegree == 0 ) buffer.push_back( vertexSet[i] );
	}
	return buffer;
}

vector<Vertex*> Graph:: topologicalOrder() {
	//vetor com o resultado da ordenacao
	vector<Vertex*> res;

	//verificar se é um DAG
	if( getNumCycles() > 0 ) {
		cout << "Ordenacao Impossivel!" << endl;
		return res;
	}

	//garantir que os "indegree" estao inicializados corretamente
	this->resetIndegrees();

	queue<Vertex*> q;

	vector<Vertex*> sources = getSources();
	while( !sources.empty() ) {
		q.push( sources.back() );
		sources.pop_back();
	}


	//processar fontes
	while( !q.empty() ) {
		Vertex* v = q.front();
		q.pop();

		res.push_back(v);

		for(unsigned int i = 0; i < v->adj.size(); i++) {
			v->adj[i].getDestination()->decIndegree();
			if( v->adj[i].getDestination()->indegree == 0) q.push( v->adj[i].getDestination() );
		}
	}

	//testar se o procedimento foi bem sucedido
	if ( res.size() != vertexSet.size() ) {
		while( !res.empty() ) res.pop_back();
	}

	//garantir que os "indegree" ficam atualizados ao final
	this->resetIndegrees();

	return res;
}

vector<Vertex*> Graph:: getPath(const Vertex &origin, const Vertex &dest){
	list<Vertex*> buffer;
	Vertex* v = getVertex(dest);

	buffer.push_front(v);
	while ( v->path != NULL &&  v->path->getId() != origin.getId()) {
		v = v->path;
		buffer.push_front(v);
	}
	if( v->path != NULL )
		buffer.push_front(v->path);


	vector<Vertex*> res;
	while( !buffer.empty() ) {
		res.push_back( buffer.front() );
		buffer.pop_front();
	}
	return res;
}

void Graph:: unweightedShortestPath(const Vertex &s) {

	for(unsigned int i = 0; i < vertexSet.size(); i++) {
		vertexSet[i]->path = NULL;
		vertexSet[i]->setDistance(INT_INFINITY);
	}

	Vertex* v = getVertex(s);
	v->setDistance(0);
	queue< Vertex* > q;
	q.push(v);

	while( !q.empty() ) {
		v = q.front(); q.pop();
		for(unsigned int i = 0; i < v->adj.size(); i++) {
			Vertex* w = v->adj[i].getDestination();
			if( w->getDistance() == INT_INFINITY ) {
				w->setDistance(v->getDistance() + 1);
				w->path = v;
				q.push(w);
			}
		}
	}
}

void Graph:: dfsVisit() {
	typename vector<Vertex*>::const_iterator it = vertexSet.begin();
	typename vector<Vertex*>::const_iterator ite = vertexSet.end();
	for (; it !=ite; it++)
		(*it)->visited=false;
	it=vertexSet.begin();
	for (; it !=ite; it++)
	    if ( (*it)->visited==false )
	    	dfsVisit(*it);
}

void Graph:: dfsVisit(Vertex *v) {
	v->processing = true;
	v->visited = true;
	typename vector<Edge >::iterator it= (v->adj).begin();
	typename vector<Edge >::iterator ite= (v->adj).end();
	for (; it !=ite; it++) {
		if ( it->getDestination()->processing == true) numCycles++;
	    if ( it->getDestination()->visited == false ){
	    	dfsVisit(it->getDestination());
	    }
	}
	v->processing = false;
}

vector<Vertex*> Graph:: getfloydWarshallPath(const Vertex &origin, const Vertex &dest){

	int originIndex = -1, destinationIndex = -1;

	for(unsigned int i = 0; i < vertexSet.size(); i++)
	{
		if(vertexSet[i]->getId() == origin.getId())
			originIndex = i;
		if(vertexSet[i]->getId() == dest.getId())
			destinationIndex = i;

		if(originIndex != -1 && destinationIndex != -1)
			break;
	}


	vector<Vertex*> res;

	//se nao foi encontrada solucao possivel, retorna lista vazia
	if(W[originIndex][destinationIndex] == INT_INFINITY)
		return res;

	res.push_back(vertexSet[originIndex]);

	//se houver pontos intermedios...
	if(P[originIndex][destinationIndex] != -1)
	{
		int intermedIndex = P[originIndex][destinationIndex];

		getfloydWarshallPathAux(originIndex, intermedIndex, res);

		res.push_back(vertexSet[intermedIndex]);

		getfloydWarshallPathAux(intermedIndex,destinationIndex, res);
	}

	res.push_back(vertexSet[destinationIndex]);

	return res;
}

void Graph:: getfloydWarshallPathAux(int index1, int index2, vector<Vertex*> & res){
	if(P[index1][index2] != -1)
	{
		getfloydWarshallPathAux(index1, P[index1][index2], res);

		res.push_back(vertexSet[P[index1][index2]]);

		getfloydWarshallPathAux(P[index1][index2],index2, res);
	}
}

void Graph:: bellmanFordShortestPath(const Vertex &s) {

	for(unsigned int i = 0; i < vertexSet.size(); i++) {
		vertexSet[i]->path = NULL;
		vertexSet[i]->setDistance(INT_INFINITY);
	}

	Vertex* v = getVertex(s);
	v->setDistance(0);
	queue< Vertex* > q;
	q.push(v);

	while( !q.empty() ) {
		v = q.front(); q.pop();
		for(unsigned int i = 0; i < v->adj.size(); i++) {
			Vertex* w = v->adj[i].getDestination();
			if(v->getDistance() + v->adj[i].getWeight() < w->getDistance()) {
				w->setDistance(v->getDistance() + v->adj[i].getWeight());
				w->path = v;
				q.push(w);
			}
		}
	}
}

void Graph:: dijkstraShortestPath(const Vertex &s) {

	for(unsigned int i = 0; i < vertexSet.size(); i++) {
		vertexSet[i]->path = NULL;
		vertexSet[i]->setDistance(INT_INFINITY);
		vertexSet[i]->processing = false;
	}

	Vertex* v = getVertex(s);
	v->setDistance(0);

	vector< Vertex* > pq;
	pq.push_back(v);

	make_heap(pq.begin(), pq.end());


	while( !pq.empty() ) {

		v = pq.front();
		pop_heap(pq.begin(), pq.end());
		pq.pop_back();

		for(unsigned int i = 0; i < v->adj.size(); i++) {
			Vertex* w = v->adj[i].getDestination();

			if(v->getDistance() + v->adj[i].getWeight() < w->getDistance() ) {

				w->setDistance((double)(v->getDistance() + v->adj[i].getWeight()));
				w->path = v;

				//se já estiver na lista, apenas a actualiza
				if(!w->processing)
				{
					w->processing = true;
					pq.push_back(w);
				}

				make_heap (pq.begin(),pq.end(),vertex_greater_than());
			}
		}
	}
}

int Graph:: edgeCost(int vOrigIndex, int vDestIndex)
{
	if(vertexSet[vOrigIndex] == vertexSet[vDestIndex])
		return 0;

	for(unsigned int i = 0; i < vertexSet[vOrigIndex]->adj.size(); i++)
	{
		if(vertexSet[vOrigIndex]->adj[i].getDestination() == vertexSet[vDestIndex])
			return vertexSet[vOrigIndex]->adj[i].getWeight();
	}

	return INT_INFINITY;
}

void Graph:: floydWarshallShortestPath() {

	W = new int * [vertexSet.size()];
	P = new int * [vertexSet.size()];
	for(unsigned int i = 0; i < vertexSet.size(); i++)
	{
		W[i] = new int[vertexSet.size()];
		P[i] = new int[vertexSet.size()];
		for(unsigned int j = 0; j < vertexSet.size(); j++)
		{
			W[i][j] = edgeCost(i,j);
			P[i][j] = -1;
		}
	}


	for(unsigned int k = 0; k < vertexSet.size(); k++)
		for(unsigned int i = 0; i < vertexSet.size(); i++)
			for(unsigned int j = 0; j < vertexSet.size(); j++)
			{
				//se somarmos qualquer coisa ao valor INT_INFINITY, ocorre overflow, o que resulta num valor negativo, logo nem convém considerar essa soma
				if(W[i][k] == INT_INFINITY || W[k][j] == INT_INFINITY)
					continue;

				int val = min ( W[i][j], W[i][k]+W[k][j] );
				if(val != W[i][j])
				{
					W[i][j] = val;
					P[i][j] = k;
				}
			}

}

void printSquareArray(int ** arr, unsigned int size){
	for(unsigned int k = 0; k < size; k++)
	{
		if(k == 0)
		{
			cout <<  "   ";
			for(unsigned int i = 0; i < size; i++)
				cout <<  " " << i+1 << " ";
			cout << endl;
		}

		for(unsigned int i = 0; i < size; i++)
		{
			if(i == 0)
				cout <<  " " << k+1 << " ";

			if(arr[k][i] == INT_INFINITY)
				cout << " - ";
			else
				cout <<  " " << arr[k][i] << " ";
		}

		cout << endl;
	}
}
