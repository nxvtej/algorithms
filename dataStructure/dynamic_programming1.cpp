#include<bits/stdc++.h>
using namespace std;

// returning nth fibo number 
int func(int n){
	// so to find the nth we need n-1th and n-2th nubmer 
	// so 
	if(n==0) return 0;
	if(n==1) return 1;
	return func(n-1)+func(n-2);

}

int main(){
	int n;
	cin>>n;
cout<<func(n);
}