#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

class Solution
{
public:
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        // vector<long long> lvlSum;

        priority_queue<long, vector<long>, greater<long>> pq;

        queue<TreeNode *> q;
        q.push(root);
        // lvlSum.push_back(root->val);

        while (!q.empty())
        {

            int size_ = q.size();
            long sum = 0;
            while (size_--)
            {
                TreeNode *frontNode = q.front();
                q.pop();
                sum += frontNode->val;
                if (frontNode->left)
                    q.push(frontNode->left);

                if (frontNode->right)
                    q.push(frontNode->right);
            }

            pq.push(sum);
            if (pq.size() > k)
                pq.pop();
        }

        // sort(begin(lvlSum), end(lvlSum));
        if (k > pq.size())
            return -1;
        return pq.top();
    }
};

/*
2583. Kth Largest Sum in a Binary Tree
Solved
Medium
Topics
Companies
Hint
You are given the root of a binary tree and a positive integer k.

The level sum in the tree is the sum of the values of the nodes that are on the same level.

Return the kth largest level sum in the tree (not necessarily distinct). If there are fewer than k levels in the tree, return -1.

Note that two nodes are on the same level if they have the same distance from the root.



Example 1:


Input: root = [5,8,9,2,1,3,7,4,6], k = 2
Output: 13
Explanation: The level sums are the following:
- Level 1: 5.
- Level 2: 8 + 9 = 17.
- Level 3: 2 + 1 + 3 + 7 = 13.
- Level 4: 4 + 6 = 10.
The 2nd largest level sum is 13.
Example 2:


Input: root = [1,2,null,3], k = 1
Output: 3
Explanation: The largest level sum is 3.


Constraints:

The number of nodes in the tree is n.
2 <= n <= 105
1 <= Node.val <= 106
1 <= k <= n

*/