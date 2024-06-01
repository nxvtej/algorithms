/*\
Ques 2 -> Walls

Consider N walls, each of unit width, situated next to each other.

You have to select any two walls i and j (1<=i, j<=N) such that 
if you break all walls except i and j and fill the spaces between 
them with water, then the amount of water stored is maximum.

Write a program to find the maximum amount of water that can be 
accumulated between the walls.

eg: 1 2 3 4 5

Ans: we choose wall 2 and 5, the amount of water that can be 
stored will be the distance between walls i.e (5-2-1) = 4 which is maximum.
They were having two different set, in set 2, the second question was:
*/

#include <iostream>
#include <vector>
using namespace std;

#define pb push_back
int walls(vector<int> wall, int n){
	int maxCapacity=INT_MIN;

	for(int i=0;i<n-1;i++){
		for(int j =i+1;j<n;j++){
			int capacity = min(wall[i], wall[j])*(j-i-1);
			maxCapacity = max(capacity, maxCapacity);
		}
	}
	return maxCapacity;
}
// something better than this would be 2 pointer approach 
// O(n)

int _walls(vector<int> buildings, int n){
	int leftP=0,rightP = n-1;
	int maxCapacity=0;

	while(leftP < rightP){
		if(buildings[leftP] < buildings[rightP]){
			maxCapacity = max(maxCapacity, buildings[leftP]*(rightP-leftP-1));
			leftP++;
		} else {
			maxCapacity = max(maxCapacity, buildings[rightP]*(rightP-leftP-1));
			rightP--;
		}
	}
	return maxCapacity;
}
int main(){
	vector<int> height;
	int n = 0;
	cin>>n;
	int t=n;
	int c;
	while(t--){
		cin>>c;
		height.pb(c);
	}
	cout<<_walls(height, n);
}

/**************************/
