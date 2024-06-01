#include <unordered_map>
#include <stack>
#include <vector>
#include <limits>
#include <list>
#include <iostream>

using namespace std;

class graph
{
public:
    unordered_map<int, list<pair<int, int>>> adj;
    // adding edges manually so created a fucntion for this
    void addEdges(int u, int v, int weight)
    {
        pair<int, int> p = make_pair(v, weight);
        adj[u].push_back(p);
    }

    // printing the  adj list
    void printAdj()
    {
        for (auto node : adj)
        {
            cout << node.first << "->";
            for (auto neighbour : node.second)
            {
                cout << "( " << neighbour.first << " , " << neighbour.second << " ) ";
            }
            cout << endl;
        }
    }

    // getting the path using bfs
    void depthfirstsearch(int node, unordered_map<int, bool> &visited, stack<int> &s)
    {
        visited[node] = true;
        for (auto neighbour : adj[node])
        {
            if (!visited[neighbour.first])
            {
                depthfirstsearch(neighbour.first, visited, s);
            }
        }
        s.push(node);
    }

    // getting the shortest path using toposort
    void getshortestpath(int src, stack<int> &toposort, vector<int> &distance)
    {
        distance[src] = 0;
        while (!toposort.empty())
        {
            int top = toposort.top();
            toposort.pop();
            if (distance[top] != INT_MAX)
            {
                for (auto it : adj[top])
                {
                    if (distance[top] + it.second < distance[it.first])
                        distance[it.first] = distance[top] + it.second;
                }
            }
        }
    }
};

int main()
{
    graph g;
    g.addEdges(2, 4, 6);
    g.addEdges(3, 4, 1);
    g.addEdges(2, 5, 11);
    g.addEdges(4, 5, 8);
    g.addEdges(0, 1, -1);
    g.addEdges(1, 3, 5);
    g.addEdges(0, 2, 5);
    cout << "adjacency list of the following graph is : \n";
    g.printAdj();

    // second step  topological sort
    int n = 5;
    unordered_map<int, bool> visited;
    stack<int> s;
    for (int i = 0; i <= n; i++)
    {
        if (!visited[i])
        {
            g.depthfirstsearch(i, visited, s);
        }
    }

    int src = 0;
    vector<int> distance(n);
    for (int i = 0; i <= n; i++)
    {
        distance[i] = INT_MAX;
    }

    g.getshortestpath(src, s, distance);

    for (int i = 0; i <= n; i++)
    {
        cout << distance[i] << " ";
    }
    cout << endl;
    return 0;
}