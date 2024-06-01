//find smalles missing numbers
// A binary search based program to find the
// only missing number in a sorted array of
// distinct elements within limited range.
#include <iostream>
using namespace std;

int search(int ar[], int size)
{
	// Extreme cases
	if (ar[0] != 1)
		return 1;
	if (ar[size - 1] != (size + 1))
		return size + 1;

	int a = 0, b = size - 1;
	int mid;
	while ((b - a) > 1) {
		mid = (a + b) / 2;
		if ((ar[a] - a) != (ar[mid] - mid))
			b = mid;
		else if ((ar[b] - b) != (ar[mid] - mid))
			a = mid;
	}
	ar[0]=ar[a]+1;
	return (ar[a] + 1);
}

// This code is contributed by Pushpesh Raj
// not able to handle duplicates

int helper(int arr[], int size){
	if(arr[0]!=1) return 1;
	int i=0;

	for(i=0;i<size;i++){
		if(arr[i] == arr[i+1] || (arr[i+1]-arr[i]==1)) continue;
		else break;
	}
	return i+2;
}
int main()
{
	int ar[] = { 1, 2, 3, 4, 5, 6, 8 };
	int size = sizeof(ar) / sizeof(ar[0]);
	cout << "Missing number:" << helper(ar, size)<<endl;
	
}
