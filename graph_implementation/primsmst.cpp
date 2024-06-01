#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.

    // cerate adj list
    unordered_map<int , list<pair<int, int>>> adj;

    for(int i = 0; i< g.size() ;i++) {
        int u , v ;
        u = g[i].first.first;
        v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));

    }

    vector<int> key(n+1);
    vector<bool> mst(n+1);

    vector<int> parent(n+1);

    for(int i =0;i<=n;i++) {
        key[i]=INT_MAX;
        parent[i]=-1;
        mst[i]=false;
    }

    // let's start
    key[1]=0;
    parent[1]=-1;

    for(int i = 0 ; i<n ; i++) {
        int mini = INT_MAX;

        int uu;
        for(int v= 1 ; v <= n ; v++) {
                if(mst[v] == false && key[v] < mini) {
                    uu = v;
                    mini = key[v];
                }
        }

        mst[uu] = true;

    // check enighbour 
    for(auto it : adj[uu]) {
        int vv = it.first;
        int weight = it.second;
        if(mst[vv] == false && weight < key[vv]) {
            parent[vv] = uu;
            key[vv] =weight;

        }
    }
    }
vector<pair<pair<int,int> , int>> result ; 
for(int i = 2; i <=n ;i++) {
    result.push_back({{parent[i], i}, key[i]});
}
return result;
}
