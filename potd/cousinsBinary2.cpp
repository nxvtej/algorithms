#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution
{
public:
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        // one method is to have level sum vector and push all lvl sum inside it
        // after that pass, another pass and get sibling by child and then
        // substract and assign
        queue<TreeNode *> q;
        q.push(root);

        int lvlSum = root->val;

        while (!q.empty())
        {
            int size_ = q.size();
            int nextSum = 0;

            for (int i = 0; i < size_; i++)
            {

                TreeNode *currentNode = q.front();
                q.pop();

                currentNode->val = lvlSum - currentNode->val;

                int sibling =
                    (currentNode->left != nullptr) ? currentNode->left->val : 0;
                sibling += (currentNode->right != nullptr)
                               ? currentNode->right->val
                               : 0;

                if (currentNode->left)
                {
                    nextSum += currentNode->left->val;
                    currentNode->left->val = sibling;
                    q.push(currentNode->left);
                }
                if (currentNode->right)
                {
                    nextSum += currentNode->right->val;
                    currentNode->right->val = sibling;
                    q.push(currentNode->right);
                }
            }

            lvlSum = nextSum;
        }

        return root;
    }
}; /*
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        // one method is to have level sum vector and push all lvl sum inside it
        // after that pass, another pass and get sibling by child and then
        // substract and assign
        queue<TreeNode*> q;
        vector<int> lvlSum;

        q.push(root);
        while (!q.empty()) {
            int size_ = q.size();
            int sum = 0;
            for (int i = 0; i < size_; i++) {
                TreeNode* currentNode = q.front();
                q.pop();
                sum += currentNode->val;
                if (currentNode->left) {
                    q.push(currentNode->left);
                }
                if (currentNode->right) {
                    q.push(currentNode->right);
                }
            }

            lvlSum.push_back(sum);
        }

        for (auto it : lvlSum)
            cout << it << " ";

        // another pass to to substract sibling

        q.push(root);
        root->val = 0;

        int k = 1;
        while (!q.empty()) {

            int size_ = q.size();

            for (int i = 0; i < size_; i++) {
                TreeNode* currentNode = q.front();
                q.pop(); // 0

                int siblingSum = (currentNode->left != nullptr)
                                     ? currentNode->left->val
                                     : 0; // 13
                siblingSum += (currentNode->right != nullptr)
                                  ? currentNode->right->val
                                  : 0;

                if (currentNode->left) {
                    currentNode->left->val = lvlSum[k] - siblingSum; // 0
                    q.push(currentNode->left);
                }

                if (currentNode->right) {
                    currentNode->right->val = lvlSum[k] - siblingSum;
                    q.push(currentNode->right);
                }
            }
            k++;
        }

        return root;
    }
};
*/
/*

Code
Solutions
Solutions
Testcase
Testcase
Test Result
2641. Cousins in Binary Tree II
Solved
Medium
Topics
Companies
Hint
Given the root of a binary tree, replace the value of each node in the tree with the sum of all its cousins' values.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Return the root of the modified tree.

Note that the depth of a node is the number of edges in the path from the root node to it.



Example 1:


Input: root = [5,4,9,1,10,null,7]
Output: [0,0,0,7,7,null,11]
Explanation: The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
- Node with value 5 does not have any cousins so its sum is 0.
- Node with value 4 does not have any cousins so its sum is 0.
- Node with value 9 does not have any cousins so its sum is 0.
- Node with value 1 has a cousin with value 7 so its sum is 7.
- Node with value 10 has a cousin with value 7 so its sum is 7.
- Node with value 7 has cousins with values 1 and 10 so its sum is 11.
Example 2:


Input: root = [3,1,2]
Output: [0,0,0]
Explanation: The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
- Node with value 3 does not have any cousins so its sum is 0.
- Node with value 1 does not have any cousins so its sum is 0.
- Node with value 2 does not have any cousins so its sum is 0.


Constraints:

The number of nodes in the tree is in the range [1, 105].
1 <= Node.val <= 104

*/