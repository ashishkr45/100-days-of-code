#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
private:
	int v; //no of vertices
	list<int> *l; //adjency list
	/*l is a pointer to an array where each element of the array is a list<int>*/
public:
	Graph(int v) {
		this->v = v;
		l = new list<int> [v]; //making a list of size v
	}

	void addEdge(int u, int v) { //we trying to make a edge btw u and v, u-----v
		l[u].push_back(v);
		/*adds v to the adjacency list of u. This means that there’s an edge from u to v*/
		l[v].push_back(u);
		/*adds u to the adjacency list of v, establishing the edge in the reverse direction as well, from v to u*/
	}

	void print() {
		for (int u = 0; u < v; u++) {
			list<int> neighbour = l[u];
			cout << u << " : ";
			for(int v : neighbour) {
				cout << v <<" ";
			}
			cout << endl;
		}
	}
};

int main() {
	Graph graph(5);

	graph.addEdge(0, 1);
	graph.addEdge(1, 2);
	graph.addEdge(1, 3);
	graph.addEdge(2, 3);
	graph.addEdge(2, 4);

	graph.print();

	return 0;
}