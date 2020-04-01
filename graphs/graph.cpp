
#include <iostream>
#include <list>
using namespace std;

struct node{
	int id;
	int data;
	list<node*> adj;
};

class Graph{
private:
	bool undirected;
	int numNodes;
	list<node*> nodes;
	node * getPointer(int);

public:
	Graph(bool und){
		undirected = und;
		numNodes = 0;
		nodes.clear();
	}
	bool getGType() {return undirected;}
	bool addNode(int,int);
	int getNumNodes() {return numNodes;}
	bool addEdge(int,int);
	void printGraph();
	bool existEdge(int,int);
	void deleteNode(int);
	void deleteEdge(int,int);
};

/*
if undirected == true, edges are A --- B
else A --> B
*/

void Graph::deleteEdge(int idA, int idB){
	if (undirected){
		node * a = getPointer(idA);
		node * b = getPointer(idB);

		list<node*>::iterator it = a->adj.begin();
		bool end = false;
		while(!end && it != a->adj.end()){
			if((*it)->id == idB){
				a->adj.erase(it);
				end = true;
			}
			else{
				it++;
			}
		}
		it = b->adj.begin();
		end = false;
		while(!end && it != b->adj.end()){
			if((*it)->id == idA){
				b->adj.erase(it);
				end = true;
			}
			else{
				it++;
			}
		}

	}
	else{
		node * a = getPointer(idA);
		list<node*>::iterator it = a->adj.begin();
		bool end = false;
		while(!end && it != a->adj.end()){
			if((*it)->id == idB){
				a->adj.erase(it);
				end = true;
			}
			else{
				it++;
			}
		}
	}
}

void Graph::deleteNode(int id){
	if(getPointer(id) != NULL){
		list<node*>::iterator itA = nodes.begin();
		bool erased = false;
		list<node*>::iterator aux;
		while(itA != nodes.end()){

			if((*itA)->id == id){
				aux = itA;
			}
			else{
				list<node*>::iterator itB = (*itA)->adj.begin();
				erased = false;
				while(erased != true && itB != (*itA)->adj.end()){
					if((*itB)->id == id){
						(*itB)->adj.erase(itB);
						erased = true;
					}
					itB++;
				}
			}
			itA++;
		}
		(*aux)->adj.clear();
		nodes.erase(aux);
	}
}

bool Graph::existEdge(int idA, int idB){
	node * a = getPointer(idA);
	list<node*>::iterator it = a->adj.begin();
	while(it != a->adj.end()){
		if((*it)->id == idB)
			return true;
		it++;
	}
	return false;
}

node * Graph::getPointer(int id){
	list<node*>::iterator it = nodes.begin();
	while(it != nodes.end()){
		if((*it)->id == id){
			return (*it);
		}
		it++;
	}
	return NULL;
}

void Graph::printGraph(){
	list<node*>::iterator itA = nodes.begin();
	while(itA != nodes.end()){
		cout << (*itA)->id << " -> {";
		list<node*>::iterator itB = (*itA)->adj.begin();
		if(itB != (*itA)->adj.end()){
			cout << (*itB)->id;
			itB++;
		}
		while(itB != (*itA)->adj.end()){
			cout  << "," << (*itB)->id;
			itB++;
		}
		cout << "}" << endl;
		itA++;
	}
}

bool Graph::addNode(int data,int id){
	if(getPointer(id) == NULL){
		node * new_node = new node;
		new_node->id = id;
		new_node->data = data;
		nodes.push_back(new_node);
		numNodes++;
		return true;
	}
	else
		return false;
}

bool Graph::addEdge(int idA, int idB){
	//the class alows self edges
	if(idA == idB){
		if(!existEdge(idA,idB)){
			node * a = getPointer(idA);
			if(a != NULL){
				a->adj.push_back(a);
				return true;
			}
			else
				return false;
		}
		else
			return false;
	}
	else{
		if(!existEdge(idA,idB)){
			node * a = getPointer(idA);
			node * b = getPointer(idB);
			if(a != NULL && b != NULL){
				if(undirected == true){
					a->adj.push_back(b);
					b->adj.push_back(a);
				}
				else
					a->adj.push_back(b);

				return true;
			}
			return false;
		}
		else
			return false;
	}
}

int main(){

	Graph a(true);
	a.printGraph();
	cout << endl;
	a.addNode(23,1);
	a.addNode(44,2);
	a.addNode(2,3);
	a.addNode(1,4);
	a.printGraph();
	cout << endl;

	a.addEdge(1,2);
	a.addEdge(1,3);
	a.addEdge(2,3);


	a.addEdge(1,4);
	a.addEdge(2,4);
	a.addEdge(4,2);
	a.addEdge(3,4);

	a.addEdge(3,3);
	a.addEdge(3,3);

	a.printGraph();
	cout << endl;

	a.deleteEdge(3,3);
	a.deleteEdge(2,4);
	a.deleteNode(1);

	a.printGraph();
	cout << endl;

}
