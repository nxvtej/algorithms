#include <iostream>
#include <unordered_map>
#include <vector>

#define um unordered_map
#define umii unordered_map<int, int>

using namespace std;
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

class BruteForceSolution
{
public:
    int ans = 0;
    int pathSum(TreeNode *root, int sum)
    {
        if (root)
        {
            dfs(root, static_cast<long long>(sum));
            pathSum(root->left, sum);
            pathSum(root->right, sum);
        }
        return ans;
    }
    void dfs(TreeNode *root, long long sum)
    {
        if (!root)
            return;
        if (root->val == sum)
            ans++;
        dfs(root->left, sum - root->val);
        dfs(root->right, sum - root->val);
    }
};

class OptimalSolution
{
    int ans = 0;

private:
    void solve(TreeNode *node, int sum, int target, umii &map)
    {

        if (node == nullptr)
            return;

        int currentSum = sum + node->val;
        map[currentSum]++;
        if (map.count(currentSum - target))
        {
            ans += map[currentSum - target];
        }
        amp[currentSum]--;
    }
    int pathSum(TreeNode *root, int targetSum)
    {
        umii map;
        map[0] = 1;
        solve(root, 0, targetSum, map);
        return ans;
    }
};
/*
437. Path Sum III
Solved
Medium
Topics
Companies
Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).
 */