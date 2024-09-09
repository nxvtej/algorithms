
#include <bits/stdc++.h>
using namespace std;

// structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
private:
    void solve(Node *node, int len, int &maxlen, int &maxSum, int sum)
    {
        if (node == nullptr)
        {
            if (len > maxlen)
            {
                maxlen = len;
                maxSum = sum;
            }
            else if (len == maxlen)
            {
                maxSum = max(maxSum, sum);
            }

            return;
        }

        solve(node->left, len + 1, maxlen, maxSum, sum + node->data);
        solve(node->right, len + 1, maxlen, maxSum, sum + node->data);

        return;
    }

public:
    int sumOfLongRootToLeafPath(Node *root)
    {
        // code here
        // approach would be going till leaf and then comparing the sum and the length

        int len = 0;
        int maxSum = 0;
        int maxlen = 0;
        solve(root, len, maxlen, maxSum, 0);
    }
};