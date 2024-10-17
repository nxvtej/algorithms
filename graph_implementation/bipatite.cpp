#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool dfs(int node, int nodecolor, vector<int> &color, vector<vector<int>> &graph)
    {
        color[node] = nodecolor;

        for (auto it : graph[node])
        {
            if (color[it] == nodecolor)
                return false;

            if (color[it] == -1)
            {

                // nodecolor = 1-nodecolor;
                // recursion mei bhi update kr diya
                if (!dfs(it, 1 - nodecolor, color, graph))
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
                if (dfs(i, 1, color, graph) == false)
                    return false;
        }
        return true;
    }
};
/*
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);
        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (color[i] != 0)
                continue;

            color[i] = 1;
            q.push(i);

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbour : graph[node]) {
                    if (color[neighbour] == 0) {
                        color[neighbour] = -color[node];
                        q.push(neighbour);
                    } else {
                        if (color[neighbour] == color[node])
                            return false;
                    }
                }
            }
        }
        return true;
    }
};
*/