#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;


int h[N];

// brute force approach 
/*
int func(int i){

// there are 2 ways we can reach either i-1 or i-2;
	if(i==0) return 0;
	int cost = INT_MAX;
	cost = min(cost, func(i-1)+abs(h[i]-h[i-1]));
	if(i>1)
		cost = min(cost, func(i-2)+abs(h[i]-h[i-2]));

	return cost;
}
*/


// using memoisation 

int dp[N];

int func(int i){
	if(i==0) return 0;
	if(dp[i] != -1) return dp[i];

	int cost =INT_MAX;
	cost = min(cost, func(i-1)+abs(h[i]-h[i-1]));
	if(i>1)
		cost = min(cost, func(i-2)+abs(h[i]-h[i-2]));

	return dp[i]=cost;
} 
int main(){
	memset(dp,-1,sizeof(dp));
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
cin>>h[i];
	}
	cout<<func(n-1);

}



// using iterative approach for this 
/*
int frog_jump(int i){
	int dp[i];
	dp[0]=0;
	for(int j=1;j<i;j++){
		dp[j]=min(dp[j-1]+abs(h[j]-h[j-1]), (i>=2 ? dp[j-2]+abs(h[j-2]-h[j]): INT_MAX));
	}
	return dp[i-1];

}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>h[i];
	}

	cout<<frog_jump(n);
}
*/