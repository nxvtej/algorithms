#include <unordered_map>
#include <list>
#include <vector>
#include <iostream>
using namespace std;
int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}

void dfs(int node, int parent, vector<int> &disTime,
         vector<int> &low, unordered_map<int, bool> &visited,
         unordered_map<int, list<int>> &adj, vector<int> &ap, int &timer)
{

    visited[node] = true;
    disTime[node] = low[node] = timer++;
    int child = 0;
    for (auto neighbour : adj[node])
    {
        if (neighbour == parent)
        {
            continue;
        }
        if (!visited[neighbour])
        {
            dfs(neighbour, node, disTime, low, visited, adj, ap, timer);
            low[node] = min(low[node], low[neighbour]);

            // main story
            if (low[neighbour] >= disTime[node] && parent != -1)
            {
                ap[node] = true;
            }

            else
            {
                low[node] = min(low[node], disTime[neighbour]);
            }
        }
    }
    if (parent == -1 && child > 1)
    {
        ap[node] = true;
    }
}
int main()
{
    int n = 5;
    int e = 5;
    // first step is to create the graph :)
    unordered_map<int, list<int>> adj;

    // for th[is we will need some vector of edges as well, so create one;
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(0, 3));
    edges.push_back(make_pair(3, 4));
    edges.push_back(make_pair(0, 4));
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(1, 2));

    for (int i = 0; i < edges.size(); i++)
    {

        adj[edges[i].first].push_back(edges[i].second);
        ` adj[edges[i].second].push_back(edges[i].first);
    }

    int timer = 0;
    vector<int> disTime(n);
    vector<int> low(n);
    unordered_map<int, bool> visited;
    vector<int> ap(n, 0);

    for (int i = 0; i < n; i++)
    {
        disTime[i] = -1;
        low[i] = -1;
    }

    // next step use dfs

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, -1, disTime, low, visited, adj, ap, timer);
        }
    }

    // priunting thea p

    cout << " articulation points are " << endl;
    for (int i = 0; i < n; i++)
    {
        if (ap[i] != 0)
        {
            cout << i << " , ";
        }
    }
    return 0;
}