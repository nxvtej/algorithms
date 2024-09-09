
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>

#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>

#define pb push_back

#define qi queue<int>
#define qp queue<pair<int, int>>
#define ff front().first
#define fs front().second

using namespace std;

struct Node
{
    int data;
    Node *right, *left;
};

/*You are required to complete below method */
class Solution
{
    vi inorder, leaf;

private:
    void inorderTraversal(Node *node)
    {
        if (node == nullptr)
            return;

        inorderTraversal(node->left);
        inorder.pb(node->data);
        if (node->left == nullptr && node->right == nullptr)
            leaf.pb(node->data);
        inorderTraversal(node->right);

        return;
    }

public:
    bool isDeadEnd(Node *root)
    {
        // Your code here
        // approach do inorder traversal and then check for dead end comapring the lef with the inroder root;

        inorderTraversal(root);

        int j = 0;

        for (int i = 0; i < inorder.size() && j < leaf.size(); i++)
        {
            if (inorder[i] == leaf[j])
            {
                if (inorder[i - 1] == leaf[j] - 1 && inorder[i + 1] == leaf[j] + 1)
                    return true;

                j++;
            }
        }
        return false;
    }
};