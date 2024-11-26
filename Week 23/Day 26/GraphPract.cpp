#include <iostream>
using namespace std;

int **createGraph(int v) {
    int **adjMat = new int*[v + 1];
    for (int i = 0; i <= v; i++) {
        adjMat[i] = new int[v + 1];
        for (int j = 0; j <= v; j++) {
            adjMat[i][j] = 0;
        }
    }
    return adjMat;
}

void insertions(int v, int **adjMat, int x, int y) {
    if (x < 1 || y < 1 || x > v || y > v) {
        cout << "Invalid edge: (" << x << ", " << y << ")\n";
        return;
    }
    adjMat[x][y] = 1; // Directed graph
    cout << "Edge inserted: (" << x << ", " << y << ")\n";
}

void bfs(int **adjMat, int start, int v) {
    bool visited[v + 1] = {false};
    int queue[v + 1], front = 0, rear = 0;

    visited[start] = true;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];
        cout << current << " ";

        for (int i = 1; i <= v; i++) {
            if (adjMat[current][i] && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    cout << endl;
}

void dfsHelper(int start, int v, int **adjMat, bool *visited) {
    visited[start] = true;
    cout << start << " ";

    for (int i = 1; i <= v; i++) {
        if (adjMat[start][i] && !visited[i]) {
            dfsHelper(i, v, adjMat, visited);
        }
    }
}

void dfs(int start, int v, int **adjMat) {
    bool visited[v + 1] = {false};
    dfsHelper(start, v, adjMat, visited);
    cout << endl;
}

void warshall(int v, int **adjMat) {
    for (int k = 1; k <= v; k++) {
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) {
                adjMat[i][j] = adjMat[i][j] || (adjMat[i][k] && adjMat[k][j]);
            }
        }
    }
}

// Function to print the adjacency matrix
void printAdjMat(int v, int **adjMat) {
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int vertex, edges;
    cout << "Enter the number of vertices and edges: ";
    cin >> vertex >> edges;

    int **adjMat = createGraph(vertex);

    cout << "Enter the edges (x, y):\n";
    for (int i = 0; i < edges; i++) {
        int x, y;
        cin >> x >> y;
        insertions(vertex, adjMat, x, y);
    }

    int start;
    cout << "Enter the starting vertex for BFS and DFS: ";
    cin >> start;

    cout << "BFS traversal:\n";
    bfs(adjMat, start, vertex);

    cout << "DFS traversal:\n";
    dfs(start, vertex, adjMat);

    cout << "Applying Warshall's algorithm (Transitive Closure):\n";
    warshall(vertex, adjMat);

    cout << "Adjacency matrix after Warshall's algorithm:\n";
    printAdjMat(vertex, adjMat);

    // Deallocate memory
    for (int i = 0; i <= vertex; i++) {
        delete[] adjMat[i];
    }
    delete[] adjMat;

    return 0;
}