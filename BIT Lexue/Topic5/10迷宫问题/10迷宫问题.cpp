#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100;
int maze[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
vector<pair<int, int>> path;
int n;

bool isSafe(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 0 && !visited[x][y]);
}

bool solveMaze(int x, int y) {
    if (x == n - 1 && y == n - 1) {
        path.push_back({x + 1, y + 1});
        return true;
    }

    if (isSafe(x, y)) {
        visited[x][y] = true;
        path.push_back({x + 1, y + 1});

        if (solveMaze(x + 1, y)) return true;
        if (solveMaze(x, y + 1)) return true;
        if (solveMaze(x - 1, y)) return true;
        if (solveMaze(x, y - 1)) return true;

        path.pop_back();
        visited[x][y] = false;
    }

    return false;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> maze[i][j];

    if (solveMaze(0, 0)) {
        for (auto p : path)
            cout << "<" << p.first << "," << p.second << "> ";
    } else {
        cout << "there is no solution!";
    }

    return 0;
}