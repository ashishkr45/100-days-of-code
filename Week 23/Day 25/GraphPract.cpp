#include <iostream>
using namespace std;

class Graph {
private:
    int v; // total number of vertices
    int e; // total number of edges
    int** ajMat;

    void DFShelper(int start, bool* visited) {
        cout << start << " ";
        visited[start] = true;

        for (int i = 1; i <= v; i++) { // Iterate over valid vertices
            if (ajMat[start][i] && !visited[i]) {
                DFShelper(i, visited);
            }
        }
    }

public:
    Graph(int v, int e) {
        this->v = v;
        this->e = e;

        ajMat = new int*[v + 1];
        for (int i = 0; i <= v; i++) {
            ajMat[i] = new int[v + 1];
        }

        for (int i = 0; i <= v; i++) {
            for (int j = 0; j <= v; j++) {
                ajMat[i][j] = 0;
            }
        }
    }

    ~Graph() {
        for (int i = 0; i <= v; i++) {
            delete[] ajMat[i];
        }
        delete[] ajMat;
    }

    void insert(int x, int y) {
        if (x > v || y > v || x < 1 || y < 1) {
            cout << "Invalid edge!\n";
            return;
        }
        /* undirected graph */
        ajMat[x][y] = 1;
        ajMat[y][x] = 1;
        cout << "Insertion Successful\n";
    }

    void BFS(int start) {
        if (start < 1 || start > v) {
            cout << "Invalid start vertex!\n";
            return;
        }

        bool* visited = new bool[v + 1]();
        int queue[100], front = 0, rear = 0;

        visited[start] = true;
        queue[rear++] = start;

        while (front < rear) {
            int current = queue[front++];
            cout << current << " ";

            for (int i = 1; i <= v; ++i) {
                if (ajMat[current][i] && !visited[i]) {
                    visited[i] = true;
                    queue[rear++] = i;
                }
            }
        }
        cout << endl;
        delete[] visited;
    }

    void DFS(int start) {
        if (start < 1 || start > v) {
            cout << "Invalid start vertex!\n";
            return;
        }

        bool* visited = new bool[v + 1]();
        DFShelper(start, visited);
        cout << endl;
        delete[] visited;
    }
};

int main() {
    int v, e;

    cout << "Enter the number of vertices and edges: ";
    cin >> v >> e;

    Graph graph(v, e);

    cout << "Enter the edges (a b):\n";
    for (int i = 0; i < e; ++i) {
        int a, b;
        cin >> a >> b;
        graph.insert(a, b);
    }

    cout << "BFS starting from node 1:\n";
    graph.BFS(1);

    cout << "DFS starting from node 1:\n";
    graph.DFS(1);

    return 0;
}