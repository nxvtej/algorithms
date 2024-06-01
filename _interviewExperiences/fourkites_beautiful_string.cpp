/*
Ques 2-> Beautiful strings

You know vowels (a, e,  i,  o, u)  A number is given N, 
You have to generate all string of length N from vowels 
and tell the number of unique strings generated lexicographically.

eg:
N=1
The strings generated {“a”, “e”, “i”, “o”, “u”} = 5
N=2

The strings generated {“aa”, “ae”, “ai”, “ao”, “au”, “ee”, “ei”, “eo”, 
“eu”, “ii”, “io”, “iu”, “oo”, “ou”, “uu”} = 15
*/

#include <iostream>
using namespace std;

int beautifulString(int n){
	return (n+1)*(n+2)*(n+3)*(n+4)/24;
}
int main(){
	int n =2;
	cout<<beautifulString(n);
}