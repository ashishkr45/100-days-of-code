#include <iostream>
#include <queue>
#include <vector>
#include <list>

using namespace std;

class Graph {
private:
	int v; // no of vertices
	list <int>* l;
public:
	Graph(int v) {
		this->v = v;
		l = new list<int> [v];
	}

	void addEdge(int u, int v) {
		l[u].push_back(v);
		l[v].push_back(u);
	}

	void print() {
		for(int u = 0; u < v; u++) {
			list<int> neighbour = l[u];
			for(int n : neighbour) {
				cout << n << " ";
			}
			cout << endl;
		}
	}

	void BFS() { // o( v+e) v = virtices & e = edges
		queue<int> q;
		vector<bool> visited(v, false);
		q.push(0);
		visited[0] = 1;
		cout<<"BFS sequence: ";

		while (q.size() > 0) {
			int u = q.front(); //current vertex
			q.pop();
			cout << u << " ";

			list<int> neightbours = l[u];

			for(int i : neightbours) {
				if(!visited[i]) {
					visited[i] = 1;
					q.push(i);
				}
			}
		}
		cout << endl;
	}

	void dfsHelper(int u, vector<bool> &visited) {
		visited[u] = 1;
		cout << u << " ";

		list<int> neighbour = l[u]; 
		for(int v : neighbour) {
			if(!visited[v]) {
				dfsHelper(v, visited);
			}
		}
	}

	void DFS() {
		cout<<"DFS sequence: ";
		vector<bool> visited(7, 0);
		dfsHelper(0, visited);
	}
};

int main() {
	Graph graph(7);
	graph.addEdge(0, 1);
	graph.addEdge(0, 2);
	graph.addEdge(1, 3);
	graph.addEdge(2, 4);
	graph.addEdge(3, 5);
	graph.addEdge(3, 4);
	graph.addEdge(4, 5);
	graph.addEdge(5, 6);

	graph.print();
	
	cout << endl;

	graph.BFS();

	graph.DFS();

	return 0;
}