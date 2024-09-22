#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
// vector<int> tree[N];
int par[N];

int main(){
	int number_of_nodes;
	cin>>number_of_nodes;
	vector<int> tree[number_of_nodes];
	for(int i=0;i<5-1;i++){
		int x,y;
		cin>>x>>y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}

	// to check if it's working properly let's print all the nodes;
	for(int i=1;i<=5;i++){
		for(auto child: tree[i]){
			cout<<child<<" ";
		}
		cout<<endl;
	}
}