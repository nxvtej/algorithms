#include<bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

const int N=1e5+10;
vector<int> g[N];
int par[N];

void dfs(int v, int p=-1){
	par[v]=p;
	for(auto child: g[v]){
		if(child==p) continue;
		dfs(child,v);
	}
}

// functiuon  to return path vector<int>
vector<int> path(int v){
	vector<int> ans;
	while(v!=-1){
		ans.push_back(v);
		v=par[v];
	}

	reverse(ans.begin(), ans.end());
	return ans;
}
int main(){
	int n_edges=0;
	cin>>n_edges;
	for(int i =0; i<n_edges-1;++i){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	// ṇow we need all the paretns
	dfs(1);

	int x,y;
	cin>>x>>y;

	vector<int> path_x = path(x);
	vector<int> path_y = path(y);

	int min_ln = min(path_x.size(), path_y.size());
	int lca=-1;
	for(int i=0;i<min_ln;i++){
		if(path_x[i] != path_y[i]) {lca = path_x[i-1]; break;}
		else continue;
	}
	cout<<lca;
	return 0;
}
