#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

map<char, vector<int>> adjList;
map<char, bool> visited;

void addEdge(int u, int v, char vertexU, char vertexV) {
    if (find(adjList[vertexU].begin(), adjList[vertexU].end(), v) == adjList[vertexU].end())
        adjList[vertexU].push_back(v);
    if (find(adjList[vertexV].begin(), adjList[vertexV].end(), u) == adjList[vertexV].end())
        adjList[vertexV].push_back(u);
}

void bfs(char start) {
    queue<char> q;
    for (auto& pair : visited) {
        visited[pair.first] = false;
    }
    
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        char curr = q.front();
        q.pop();
        cout << curr;

        // Create priority map for next vertices
        multimap<int, char> priorityMap;
        for (int v : adjList[curr]) {
            char nextVertex = 'a' + v;
            if (!visited[nextVertex]) {
                // Priority: e > b > f > d > c
                int priority;
                switch(nextVertex) {
                    case 'e': priority = 5; break;
                    case 'b': priority = 4; break;
                    case 'f': priority = 3; break;
                    case 'd': priority = 2; break;
                    case 'c': priority = 1; break;
                    default: priority = 0;
                }
                priorityMap.insert(make_pair(priority, nextVertex));
            }
        }
        
        // Add vertices to queue in priority order
        for (auto it = priorityMap.rbegin(); it != priorityMap.rend(); ++it) {
            visited[it->second] = true;
            q.push(it->second);
        }
    }
}

int main() {
    char vertex;
    while (cin >> vertex && vertex != '*') {
        if (vertex >= 'a' && vertex <= 'k') {
            adjList[vertex] = vector<int>();
            visited[vertex] = false;
        } else {
            cerr << "Invalid vertex: " << vertex << endl;
            return 1;
        }
    }

    int u, v;
    char comma;
    while (cin >> u >> comma >> v && (u != -1 || v != -1)) {
        char vertexU = 'a' + u;
        char vertexV = 'a' + v;
        addEdge(u, v, vertexU, vertexV);
    }

    cout << "the ALGraph is" << endl;
    for (auto& pair : adjList) {
        if(pair.first == 'i') continue;
        cout << pair.first;
        vector<int> sorted = pair.second;
        sort(sorted.begin(), sorted.end(), greater<int>());
        for (int v : sorted) {
            cout << " " << v;
        }
        cout << endl;
    }

    cout << "the Breadth-First-Seacrh list:";
    bfs('a');
    cout << endl;

    return 0;
}
