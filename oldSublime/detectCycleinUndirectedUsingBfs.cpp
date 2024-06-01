#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>

#define qi queue<int>
#define qp queue<pair<int, int>>
#define qpf queue<pair<pair<int, int>, int>>

#define pb push_back
#define ff front().first
#define fff front().first.first
#define ffs front().first.second
#define fs front().second

class Solution {
        private :
        bool detect(int src, vector<int> adj[], vector<int> &visited)
    {visited[src]=1;
        // after amrking viisted now bfs 
        queue<pair<int, int>> q;
        q.push({src,-1});
        while(!q.empty()){
            // get data from quue
            int node = q.front().first;
            int parent = q.front().second;
            
            // poop them 
            q.pop();
            for(auto neighbour: adj[node]){
                
                // check if viistewd
                if(!visited[neighbour]){
                    visited[neighbour]=1;
                    q.push({neighbour,node});
                }
                
                else{
                    if(parent != neighbour){
                        return true;
                    }
                }
            }
        }
        return false;
    }
public:
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        // crceate visted array first
        vector<int> visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(detect(i,adj, visited)) return true;
            }
        }
        return false;
        
    }
};

int main(){
        Solution solution;
        vector<int> adj[]= {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}};
        int V=5,E=5;
        cout<<solution.isCycle(V, adj);
        return 0;
}