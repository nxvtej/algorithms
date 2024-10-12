#include <bits/stdc++.h>
using namespace std;
// bfs
class Solution
{
public:
    int n;
    void bfs(vector<bool> &visited, vector<vector<int>> &isConnected, int node)
    {
        visited[node] = true;
        queue<int> que;
        que.push(node);

        while (!que.empty())
        {
            int frontNode = que.front();
            que.pop();

            for (int col = 0; col < n; col++)
            {
                if (!visited[col] && isConnected[frontNode][col])
                {
                    visited[col] = true;
                    que.push(col);
                }
            }
        }

        return;
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        // create adj
        n = isConnected.size();
        vector<bool> visited(n, false);
        // create visited not visited do dfs
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                bfs(visited, isConnected, i);
                count++;
            }
        }
        // incrase count and return
        return count;
    }
};

// dfs
class Solution
{
public:
    int n;
    void dfs(vector<bool> &visited, vector<vector<int>> &isConnected, int node)
    {
        visited[node] = true;

        // nieghbour hi to represen kr rha hai ye
        for (int col = 0; col < n; col++)
        {
            if (!visited[col] && isConnected[node][col])
            {
                dfs(visited, isConnected, col);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        // create adj
        n = isConnected.size();
        vector<bool> visited(n, false);
        // create visited not visited do dfs
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(visited, isConnected, i);
                count++;
            }
        }
        // incrase count and return
        return count;
    }
};

class Solution
{
public:
    void dfs(vector<bool> &visited, unordered_map<int, vector<int>> &adj, int node)
    {
        visited[node] = true;

        for (auto neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                dfs(visited, adj, neighbour);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        // create adj
        int n = isConnected.size();
        vector<bool> visited(n, false);

        // creating graph
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        // create visited not visited do dfs
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(visited, adj, i);
                count++;
            }
        }
        // incrase count and return
        return count;
    }
};
