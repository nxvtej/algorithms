#include <bits/stdc++.h>
using namespace std;
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
    private:
    void solve(TreeNode* root, stringstream &s){
        if(root==NULL) return;
        s<<root->val;
        if(!root->left && !root->right) return;

        s<<"(";
        solve(root->left, s);
        s<<")";

        if(root->right) {
            s<<"(";
            solve(root->right, s);
            s<<")";
        }
    }
public:
    string tree2str(TreeNode* root) {
        stringstream s;
        if(root==NULL) return s.str();
        solve(root,s);
        return s.str();

    }
};
