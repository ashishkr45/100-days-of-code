#include <iostream>
#include <queue>
using namespace std;

class Graph {
    int **adjMat; // Pointer to the adjacency matrix
    int *visited; // Array to track visited vertices
    int v;        // Number of vertices
    int e;        // Number of edges

public:
    Graph(int v, int e) {
        this->v = v;
        this->e = e;

        // Allocate dynamic memory for the adjacency matrix
        adjMat = new int*[v + 1];
        for (int i = 0; i <= v; i++) {
            adjMat[i] = new int[v + 1];
        }

        // Initialize the adjacency matrix with 0
        for (int i = 0; i <= v; i++) {
            for (int j = 0; j <= v; j++) {
                adjMat[i][j] = 0;
            }
        }

        // Allocate and initialize the visited array
        visited = new int[v + 1];
        for (int i = 0; i <= v; i++) {
            visited[i] = 0;
        }
    }

    ~Graph() { // Destructor to deallocate dynamic memory
        for (int i = 0; i <= v; i++) {
            delete[] adjMat[i];
        }
        delete[] adjMat;
        delete[] visited;
    }

    bool empty() {
        return v == 0;
    }

    int numEdge() {
        return e;
    }

    int numVertex() {
        return v;
    }

    void addEdge(int x, int y) { // Considering an undirected graph
        if (x > v || y > v || x < 1 || y < 1) {
            cout << "Invalid Coordinates" << endl;
            return;
        }
        adjMat[x][y] = 1;
        adjMat[y][x] = 1;
    }

    void remEdge(int x, int y) {
        if (x > v || y > v || x < 1 || y < 1) {
            cout << "Invalid Coordinates" << endl;
            return;
        }

        if (adjMat[x][y] == 0) {
            cout << "There's No Edge" << endl;
            return;
        }

        adjMat[x][y] = 0;
        adjMat[y][x] = 0;
    }

    void displayAdjMat() {
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) {
                cout << adjMat[i][j] << " ";
            }
            cout << endl;
        }
    }

    void bfs(int start) {
        queue<int> q;
        q.push(start);
        visited[start] = 1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            cout << u << " ";

            for (int i = 1; i <= v; i++) { 
                if (adjMat[u][i] == 1 && visited[i] == 0) {
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }

	void dfs(int start) {
        
	}
};

int main() {
    int n, e, u, v;

    cout << "\nEnter the number of vertices in the Graph\n";
    cin >> n;
    cout << "\nEnter the number of distinct unordered pairs\n";
    cin >> e;

    Graph g(n, e);

    for (int i = 1; i <= e; i++) {
        cout << "\nEnter the Vertex u of Edge " << i << "\n";
        cin >> u;
        cout << "\nEnter the Vertex v of Edge " << i << "\n";
        cin >> v;
        g.addEdge(u, v);
    }

    cout << "\nThe Adjacency Matrix of G is ***********\n";
    g.displayAdjMat();

    cout << "\nThe Breadth First Search Traversal of Graph is....\n";
    g.bfs(1);

    return 0;
}