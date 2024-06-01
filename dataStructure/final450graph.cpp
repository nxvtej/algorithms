#include <bits/stdc++.h>
using namespace std;


/**************************************************************************/
// check if graph is bipartite or not
// brute force 

class solution
{
    bool solve(int start, int V, vector<int> adj[], int color[])
    {
        queue<int> q;
        q.push(start);
        color[start] = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto neighbor : adj[node])
            {
                // give oppposite to the each neighbour
                if (color[neighbor] == -1)
                {

                    color[neighbor] = !color[node];
                    q.push(neighbor);
                }
                else if (color[neighbor] == color[node])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(int V, vector<int> adj[])
    {
        int color[V];
        for (int i = 0; i < V; i++)
            color[i] = -1;

        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {

                if (solve(i, V, adj, color) == false)
                    return false;
            }
        }

        return true;
    }
};