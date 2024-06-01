#include<iostream>
using namespace std;

/*
int func(int n){
	if(n==0) return 0;
	if(n==1) return 1;
	return func(n-1)+func(n-2);
}
int main(){
	int n;
	cin>>n;
	cout<<func(n);
	return 0;
}
*/
// tc is 2^n which is really high 


int dp[N];

// top down approach
int func(int n){
	if(n==0) return 0;
	if(n==1) return 1;
	if(dp[n]!=-1) return dp[n]; //memoise here

	return dp[n]=func(n-1)+func(n-2);
}
int main(){
	memset(dp,-1,sizeof(dp));
	// to initilized 
	// but you cant use it for other numer like 2 , 3 
	// only -1
	int n;
	cin>>n;
	cout<<func(n);
	return 0;
}

// tc - n

// also in dp we can convert fdactrorial into exponsensioal 