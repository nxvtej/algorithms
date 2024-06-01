#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;

// to make it generic
template <typename T>


class graph {
    public:
    unordered_map<int,list<int>> adj;
    // unordered_map<T<list<T>>adj;

                // T    T
    void addEdge(int u,int v,bool direction){

        adj[u].push_back(v);
        if(direction == 0) {
            adj[v].push_back(u);
        }

    }

    void printAdjlist() {
        for(auto it: adj) {
            cout<< it.first <<"->";
            for(auto ab: it.second) {
                cout<<ab<<",";
            }
            cout<<endl;
        }
    }
};
int main()
{
    // total number of nodes
    int n;
    cin>> n;
    // total number of edges
    int m;
    cin>>m;
    // graph object just to add edges to g;
// if using template then use graph <type> here

    graph<int> g; 

    for(int i=0;i<m;i++) {
        int first_connect ,second_connect;
        cin>> first_connect >> second_connect ;

        // undirected graph so 0 is given
        g.addEdge(first_connect,second_connect,0);
    }
    g.printAdjlist();
    return 0;
}
