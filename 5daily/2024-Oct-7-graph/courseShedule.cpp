#include <bits/stdc++.h>
using namespace std;
class Solution
{
    bool topologicalSortCheck(unordered_map<int, vector<int>> &graph, int n, vector<int> &indegree)
    {
        queue<int> que;
        int count = 0; // agar cycle nahi hai to count increase kro
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                count++;
                que.push(i);
            }
        }

        while (!que.empty())
        {
            int u = que.front();
            que.pop();

            for (int &neighbour : graph[u])
            {
                indegree[neighbour]--;

                if (indegree[neighbour] == 0)
                {
                    count++;
                    que.push(neighbour);
                }
            }
        }

        return count == n;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>> &graph)
    {

        // creating map

        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);

        for (auto &vec : graph)
        {
            int a = vec[0];
            int b = vec[1];

            // phle b krege fir a krege
            adj[b].push_back(a);

            // arrow ja rha hai to indegree jayga a ka

            indegree[a]++;
        }

        return topologicalSortCheck(adj, numCourses, indegree);
    }
};
/*
class Solution {
public:
    bool dfs(int node, unordered_map<int, vector<int>> &adj, vector<int> &visited) {
        // If the node is in the current recursion stack, there's a cycle
        if (visited[node] == 1) return false;
        // If it's already fully processed, skip it
        if (visited[node] == 2) return true;

        // Mark the node as part of the current recursion stack
        visited[node] = 1;

        // Explore all the neighbors
        for (int &neighbor : adj[node]) {
            if (!dfs(neighbor, adj, visited)) {
                return false;
            }
        }

        // Mark the node as fully processed
        visited[node] = 2;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> visited(numCourses, 0); // 0 = unvisited, 1 = visiting, 2 = visited

        // Build the adjacency list for the graph
        for (auto &prerequisite : prerequisites) {
            adj[prerequisite[1]].push_back(prerequisite[0]);
        }

        // Run DFS from each unvisited node
        for (int i = 0; i < numCourses; ++i) {
            if (visited[i] == 0) {
                if (!dfs(i, adj, visited)) {
                    return false; // Cycle detected
                }
            }
        }

        return true; // No cycles, all courses can be finished
    }
};


*/
