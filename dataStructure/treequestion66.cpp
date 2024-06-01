#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
// construct binary tree from inorder, postorder traversal
void createmapping(int in[], map<int, int> &nodetoindex, int n)
{
    for (int i = 0; i < n; i++)
    {
        nodetoindex[in[i]] = i;
    }
}
Node *solve(int in[], int post[], int &postorderindex,
            int inorderstart, int inorderend, int n, map<int, int> &nodetoindex)
{
    // base case
    if (postorderindex < 0 || inorderstart > inorderend)
        return NULL;

    // create a root for element
    int element = post[postorderindex--];
    Node *node = new Node(element);

    // find the element postition in inorder
    int position = nodetoindex[element];

    node->right = solve(in, post, postorderindex, position + 1, inorderend, n,
                        nodetoindex);
    node->left = solve(in, post, postorderindex, inorderstart,
                       position - 1, n, nodetoindex);

    return node;
}
// Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n)
{

    // starting from postorder index
    // it's always the last one
    int postorderindex = n - 1;
    // creating a mapping for tree, node to index;
    map<int, int> nodetoindex;
    createmapping(in, nodetoindex, n);

    // creating ans
    Node *ans = solve(in, post, postorderindex, 0, n - 1, n, nodetoindex);
}

// -------------------------------//
// construct tree from inorder and preoder traversal

class Solution
{
public:
    void createmapping(int in[], map<int, int> &nodetoindex, int n)
    {
        for (int i = 0; i < n; i++)
        {
            nodetoindex[in[i]] = i;
        }
    }
    Node *solve(int in[], int pre[], int &index, int inorderstart,
                int inorderend, int n, map<int, int> &nodetoindex)
    {
        // base case
        if (index >= n || inorderstart > inorderend)
        {
            return NULL;
        }

        int element = pre[index++];
        Node *root = new Node(element);
        int position = nodetoindex[element];

        // recursive
        root->left = solve(in, pre, index, inorderstart, position - 1, n, nodetoindex);
        root->right = solve(in, pre, index, position + 1, inorderend, n, nodetoindex);

        return root;
    }
    Node *buildTree(int in[], int pre[], int n)
    {
        int preorderindex = 0;
        map<int, int> nodetoindex;
        createmapping(in, nodetoindex, n);
        Node *ans = solve(in, pre, preorderindex, 0, n - 1, n, nodetoindex);
        return ans;
    }
};

// some how above code is not passing all the test cases
class Solution
{
private:
    int Findposition(int in[], int inorderStart, int inorderEnd, int element, int n)
    {
        for (int i = inorderStart; i <= inorderEnd; i++)
        {
            if (in[i] == element)
            {
                return i;
            }
        }
        return -1;
    }
    Node *solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n)
    {
        if (index >= n || inorderStart > inorderEnd)
        {
            return NULL;
        }

        int element = pre[index++]; // At every interation index is increasing
        Node *root = new Node(element);
        int position = Findposition(in, inorderStart, inorderEnd, element, n);

        root->left = solve(in, pre, index, inorderStart, position - 1, n);
        root->right = solve(in, pre, index, position + 1, inorderEnd, n);

        return root;
    }

public:
    Node *buildTree(int in[], int pre[], int n)
    {
        // Code here
        int preorderindex = 0; // Pre order is NLR so First element is root .

        Node *ans = solve(in, pre, preorderindex, 0, n - 1, n);
        return ans;
    }
};