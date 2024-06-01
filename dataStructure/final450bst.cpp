/********************************/
// find minimum number of swaps to convert vinary search tree into binraru search tree

// approach would be using inorder traversal as inorder wopudl be sorted of bst

#include <bits/stdc++.h>
using namespace std;

// Function to perform in-order traversal and store the elements in a vector
void inOrderTraversal(vector<int>& arr, vector<int>& inorder, int index) {
    if (index >= arr.size() || arr[index] == -1) {
        return;
    }

    inOrderTraversal(arr, inorder, 2 * index + 1); // Left child
    inorder.push_back(arr[index]);                // Current node
    inOrderTraversal(arr, inorder, 2 * index + 2); // Right child
}

// Function to calculate the minimum number of swaps to convert a binary tree to a BST
int minimumSwaps(vector<int>& arr, int n) {
    // Perform in-order traversal on the binary tree to get its elements
    vector<int> treeInorder;
    inOrderTraversal(arr, treeInorder, 0);

    // Sort the original array to get the expected in-order traversal of the BST
    vector<int> bstInorder = arr;
    sort(bstInorder.begin(), bstInorder.end());

    // Count the positions where the in-order traversals differ
    int swaps = 0;
    for (int i = 0; i < n; ++i) {
        if (treeInorder[i] != bstInorder[i]) {
            swaps++;
        }
    }

    return swaps;
}


#include <bits/stdc++.h> 
void inorder(vector<pair<int,int>> &result, vector<int> &arr, int index){
	if(arr[index]==-1) return;

	inorder(result, arr,2*index+1);
	result.push_back({arr[index],index});
	inorder(result, arr, 2*index+2);
}
int minimumSwaps(vector<int>&arr, int n) {
	// Write your code here.
	vector<pair<int,int>> result; //to map current tree inorder
	vector<int> positionsToSwap(n/2);
	inorder(result, arr, 0);

// now sort and find position to swap
	sort(result.begin(), result.end());
	for(int i=0;i<n;i++){
		if(result[i].second!=i){
				positionsToSwap.push_back(result[i].second);
		}
	}
	// fiter then to unique
	unordered_set<int> finalresult (positionsToSwap.begin(), positionsToSwap.end());
	return finalresult.size();
}