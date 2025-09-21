#include <iostream>
using namespace std;

const int N = 5; // Maze size

bool isSafe(int maze[N][N], int x, int y, bool visited[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && 
            maze[x][y] == 1 && !visited[x][y]);
}

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N], bool visited[N][N]) {
    if (x == N - 1 && y == N - 1) {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(maze, x, y, visited)) {
        visited[x][y] = true;
        sol[x][y] = 1;

        // Move Down
        if (solveMazeUtil(maze, x + 1, y, sol, visited)) return true;

        // Move Right
        if (solveMazeUtil(maze, x, y + 1, sol, visited)) return true;

        // Move Up
        if (solveMazeUtil(maze, x - 1, y, sol, visited)) return true;

        // Move Left
        if (solveMazeUtil(maze, x, y - 1, sol, visited)) return true;

        // Backtrack
        sol[x][y] = 0;
        visited[x][y] = false;
        return false;
    }

    return false;
}

bool solveMaze(int maze[N][N]) {
    int sol[N][N] = {0};
    bool visited[N][N] = {false};

    if (!solveMazeUtil(maze, 0, 0, sol, visited)) {
        cout << "No solution exists" << endl;
        return false;
    }

    cout << "Path found:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
    return true;
}

int main() {
    int maze[N][N] = {
        {1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 1}
    };

    solveMaze(maze);
    return 0;
}
