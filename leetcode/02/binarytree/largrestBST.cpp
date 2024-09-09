#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
struct information
{
    int maxValue = 0;
    int minValue = 0;
    int maxSize = 0;
    bool isBst = false;
};
class Solution
{
private:
    information solve(Node *node, int &size)
    {
        if (node == nullptr)
        {
            return {INT_MIN, INT_MAX, 0, true};
        }

        information leftans = solve(node->left, size);
        information rightans = solve(node->right, size);

        information currentNode;
        currentNode.maxSize = (leftans.maxSize + rightans.maxSize + 1);
        currentNode.maxValue = max(node->data, rightans.maxValue);
        currentNode.minValue = min(node->data, leftans.minValue);

        if (leftans.isBst && rightans.isBst && (node->data > leftans.maxValue) && (node->data < rightans.minValue))
        {
            currentNode.isBst = true;
        }
        else
            currentNode.isBst = false;

        if (currentNode.isBst)
        {
            size = max(size, currentNode.maxSize);
        }

        return currentNode;
    }

public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
        // Your code here
        if (root == nullptr)
            return 0;
        int size = 0;
        information res = solve(root, size);

        return size;
    }
};