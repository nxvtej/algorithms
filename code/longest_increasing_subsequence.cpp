#include<bits/stdc++.h>
using namespace std;

const int N  =1e5+10;
int dp[N];
// int num[N];

int lis(int i, vector<int> &num){
	// check in dp 
	if(dp[i] != -1) return dp[i];

	int ans = 1;
	for(int j=0;j<i;j++){
		if(num[i]>num[j])
			ans = max(ans, lis(j,num)+1);
	}
	return dp[i]= ans;
}

int max_of_two(int answer, int ans) {
	return answer> ans ? answer : ans;
}

int max_of_three(int* a, int* b, int* c){
	int aa,bb,cc;
	aa = *((int*)a);
	bb = *((int*)b);
	cc = *((int*)c);

	int (*d_max)(int,int) = max;
	int second_max = (*d_max)(aa,bb);
	int final_max = (*d_max)(second_max,cc); 

	return final_max;
}

// void pointer 
void * Mymallocsize(size_t cdSize){
	return malloc(cdSize);
} 

int main(){
	memset(dp, -1, sizeof(dp));

	int n;
	cin>>n;
	vector<int> num(n);
	for(int i=0;i<n;i++)
		cin>>num[i];

	for(int i=0;i<n;i++) 
		cout<<num[i]<<" ";

	cout<<endl;
	// now ge tthe anser
		int answer=1;

	// to call max function we will use pointers 
	int (*pointermax)(int, int) = max;

	for(int i=0;i<n;i++){
		answer = (*pointermax)(answer, lis(i,num));
	}
	cout<<answer;

	/*
	cout<<("testing pointer max: \n");
	int a,b,c;
	cin>>a>>b>>c;
	cout<<(max_of_three(&a,&b,&c));
	return 0;

	*/
}

/*
//creating the fucntion call via pointers 
#include<iostream>
using namespace std;
int max_of_two(int* a, int* b)
{
int aa = *((int*)a);
int bb = *((int*)b);
return aa > bb ? aa : bb ;
}

int max_of_three(int *a, int *b, int *c ){

int (*d_max)(int*,int*) = max_of_two;
int var_max = (*d_max)(a, b);
int maximum = (*d_max)(&var_max,c);

return maximum;
}
int main(){

int x=25,y=11,z=54;


int (*pointer_max)(int*,int*,int*) = max_of_three;
int maximum_number = (*pointer_max)(&x, &y, &z);
cout<<"max value of  two integer is : "<<maximum_number;
return 0;
}

*/