#include<bits/stdc++.h>
using namespace std;

int fibo(int n){
	if(n == 0){
		// printf("%d ", 0);
		return 0;
	} else if(n == 1){
		// printf("%d ", 1);
		return 1;
	} else{
		int ele = fibo(n-1) + fibo(n-2);
		printf("%d ", ele);
		return ele;
	}
}
int main() {

	int n ;
	cin>>n;

	printf("\n%d", fibo(n));
}