/*
You are given a starting position for a rat which is stuck in a maze at an initial point (0, 0) (the maze can be thought of as a 2-dimensional plane). The maze would be given in the form of a square matrix of order N * N where the cells with value 0 represent the maze’s blocked locations while value 1 is the open/available path that the rat can take to reach its destination. The rat's destination is at (N - 1, N - 1).
Your task is to find all the possible paths that the rat can take to reach from source to destination in the maze.
The possible directions that it can take to move in the maze are 'U'(up) i.e. (x, y - 1) , 'D'(down)
i.e. (x, y + 1) , 'L' (left) i.e. (x - 1, y), 'R' (right) i.e. (x + 1, y).
*/

#include <iostream>
#include <vector>

using namespace std;

int ways(vector<vector<int>> &maze, int r, int c, vector<vector<bool>> &visited)
{
    int N = maze.size();

    // Base cases
    if (r < 0 || r >= N || c < 0 || c >= N || maze[r][c] == 0 || visited[r][c])
        return 0;
    if (r == N - 1 && c == N - 1)
        return 1;

    // Mark the cell as visited
    visited[r][c] = true;

    // Explore all four directions
    int way1 = ways(maze, r + 1, c, visited); // down
    int way2 = ways(maze, r, c + 1, visited); // right
    int way3 = ways(maze, r - 1, c, visited); // up
    int way4 = ways(maze, r, c - 1, visited); // left

    // Unmark the cell as visited for backtracking
    visited[r][c] = false;

    return way1 + way2 + way3 + way4;
}

int main()
{
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 1}};

    int N = maze.size();
    vector<vector<bool>> visited(N, vector<bool>(N, false));

    cout << "Total Number of ways: " << ways(maze, 0, 0, visited) << endl;

    return 0;
}
