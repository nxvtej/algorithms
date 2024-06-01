#include <bits/stdc++.h>
#include <unordered_map>

#include <queue>
using namespace std;

void prepareAdjList(unordered_map<int, set<int>> &adjList,
                    vector<pair<int, int>> &edges) {
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfsTraversal(unordered_map<int, set<int>> &adjList,
                  unordered_map<int, bool> &visited, vector<int> &ans,
                  int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;  // Corrected to use 'true' instead of '1'

    while (!q.empty()) {
        int frontNode = q.front();
        q.pop();

        // add those values in the values
        ans.push_back(frontNode);
        for (auto it : adjList[frontNode]) {
            if (!visited[it]) {
                q.push(it);
                visited[it] = true;  // Corrected to use 'true' instead of '1'
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges) {
    unordered_map<int, set<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;
    prepareAdjList(adjList, edges);
    for (int i = 0; i < vertex; i++) {
        if (!visited[i]) {
            bfsTraversal(adjList, visited, ans, i);
        }
    }
    return ans;
}

int main() {
    int vertices = 6;
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 3}, {4, 5}};

    vector<int> result = BFS(vertices, edges);

    cout << "BFS traversal: ";
    for (int node : result) {
        cout << node << " ";
    }
    return 0;
}