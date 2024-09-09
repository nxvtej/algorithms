
// User function Template for Java

/*
class Node {
    int data;
    Node left, right;

    Node(int d) {
        data = d;
        left = right = null;
    }
}
*/
struct Node
{
    int data;
    Node *left, *right;

    Node(int d)
    {
        data = d;
        left = right = nullptr;
    }
};

static class Solution
{
private:
    Node *solve(int pre[], int n, int bound, int index[])
    {
        if (index[0] == n || pre[index[0]] > bound)
        {
            return nullptr;
        }

        Node *root = new Node(pre[index[0]++]);
        root->left = solve(pre, n, root->data, index);
        root->right = solve(pre, n, bound, index);

        return root;
    }
    // Function that constructs BST from its preorder traversal.
public:
    Node *Bst(int pre[], int size)
    {
        // code here
        int[] index = new int[]{0};
        Node root = solve(pre, size, Integer.MAX_VALUE, index);
        return root;
    }
}
/*

Preorder to BST
Difficulty: MediumAccuracy: 59.2%Submissions: 60K+Points: 4
Given an array arr[] of N nodes representing preorder traversal of some BST. You have to build the BST  from the given preorder traversal.

In Pre-Order traversal, the root node is visited before the left child and right child nodes.

Example 1:

Input:
N = 5
arr[]  = {40,30,35,80,100}
Output: 35 30 100 80 40
Explanation: PreOrder: 40 30 35 80 100
Therefore, the BST will be:
              40
           /      \
         30       80
           \        \
           35      100
Hence, the postOrder traversal will
be: 35 30 100 80 40
Example 2:

Input:
N = 8
arr[]  = {40,30,32,35,80,90,100,120}
Output: 35 32 30 120 100 90 80 40
Your Task:
You need to complete the given function and return the root of the tree. The driver code will then use this root to print the post order traversal.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 103
1 <= arr[i] <= 104

Seen
*/