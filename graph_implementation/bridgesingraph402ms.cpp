class Solution {
    void dfs(vector<vector<int>> &adj_list,int parent,int u,
                vector<bool> &visited,
                vector<array<int,2>> &dis,
                vector<vector<int>> &bridges
    ){
        visited[u] = true;
        // traverse adjacent u->v
        if(parent == -1)
            dis[u] = {0,0};
        else
            dis[u] = {dis[parent][0] + 1,dis[parent][0] + 1};
        for(int v:adj_list[u]){
            if(v == parent)
                continue;
            else if(visited[v]){
                // never will lead to a bridge
                dis[u][1] = min(dis[v][1],dis[u][1]);
            }else{
                dfs(adj_list,u,v,visited,dis,bridges);
                dis[u][1] = min(dis[v][1],dis[u][1]);
                // check if u->v is a bridge
                if(dis[v][1]>dis[u][0]){
                    // it will lead to a bridge
                    bridges.push_back({u,v});
                }
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj_list(n);
        for(vector<int> &edge:connections){
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);            
        }
        vector<array<int,2>> dis(n);
        vector<vector<int>> bridges;
        vector<bool> visited(n,false);
        for(int i = 0;i<n;i++){
            if(visited[i]){
                continue;
            }
            dfs(adj_list,-1,i,visited,dis,bridges);
        }
        return bridges;
    }
};

// using rank
class Solution {
 public:
  vector<vector<int>> criticalConnections(int n,
                                          vector<vector<int>>& connections) {
    vector<vector<int>> ans;
    vector<vector<int>> graph(n);

    for (const vector<int>& connection : connections) {
      const int u = connection[0];
      const int v = connection[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    // rank[i] := the minimum node that node i can reach with forward edges
    // Initialize with NO_RANK = -2 to indicate not visited..
    getRank(graph, 0, 0, vector<int>(n, NO_RANK), ans);
    return ans;
  }

 private:
  static constexpr int NO_RANK = -2;

  // Gets the minimum rank that u can reach with forward edges.
  int getRank(const vector<vector<int>>& graph, int u, int currRank,
              vector<int>&& rank, vector<vector<int>>& ans) {
    if (rank[u] != NO_RANK)  // The rank is already determined.
      return rank[u];

    rank[u] = currRank;
    int minRank = currRank;

    for (const int v : graph[u]) {
      // visited || parent (that's why NO_RANK = -2 instead of -1)
      if (rank[u] == rank.size() || rank[v] == currRank - 1)
        continue;
      const int nextRank = getRank(graph, v, currRank + 1, move(rank), ans);
      // (u, v) is the only way for u go to v.
      if (nextRank == currRank + 1)
        ans.push_back({u, v});
      minRank = min(minRank, nextRank);
    }

    rank[u] = rank.size();  // Mark as visited.
    return minRank;
  }
};


