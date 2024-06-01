// main driver code here
#include<iostream>
#include<vector>

using namespace std;

vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    // Write your code here.
    // to store all the neighbours
    vector<int> ans[n];
    for(int i=0;i<m;i++) {

        // getting the edges fromt he vector edges
        int u = edges[i][0];
        int v = edges[i][1];

        // now store into the answer 
        // its given undirected graph
        ans[u].push_back(v);
        ans[v].push_back(u);

    }

    //final adjacency list creation 
    vector<vector<int>> adj(n);
    for(int i=0;i<n;i++) {
        adj[i].push_back(i);

        // entering neighbours into main list
        for(int j=0;j<ans[i].size();j++) {
            adj[i].push_back(ans[i][j]);

        }
    }
return adj;
}
int main() {
    printAdjacency();
    return ;
}