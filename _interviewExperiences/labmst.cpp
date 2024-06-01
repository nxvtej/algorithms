
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    unordered_map<int, int> mapping;
    int level(TreeNode* node, int value){
        
        queue<TreeNode*> q;
        q.push(node);
        int level =0;
        while(!q.empty()){
            int size =  q.size();
            for(int i=0;i<size;i++){
                TreeNode* frontNode = q.front();
                q.pop();

                if(frontNode->val == value){
                     cout<<"node "<<frontNode->val<<" found at "<<level;
                     return level;
                 }

                if(frontNode->left) q.push(frontNode);
                if(frontNode->right) q.push(frontNode);
            }
level++;
        }

        return false;
    }
    void createMapping(TreeNode* node, TreeNode* parent){
    	cout<<"inside mapping function\n";
        if(node == nullptr) return ;

        if(parent != nullptr){
            mapping[node->val] = parent->val;
        }

        createMapping(node->left, node);
        createMapping(node->right, node);
    }
    bool checkParent( int num1, int num2) {
        return mapping[num1] == mapping[num2];
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        // TreeNode* node1 = findNode(root, x);
        // TreeNode* node2 = findNode(root,y);
        cout<<"inside cousing funciton\n";
        createMapping(root, nullptr);
        return ((level(root, x) == level(root, y)) && !checkParent( x, y));
    }
};

TreeNode* createBinaryTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    return root;
}

int main() {
    Solution sol;
    TreeNode* root = createBinaryTree();
    int x = 4;
    int y = 5;
    cout<<"just above fucntion call\n";
    if (sol.isCousins(root, x, y)) {
        cout << "Node " << x << " and Node " << y << " are cousins." << endl;
    } else {
        cout << "Node " << x << " and Node " << y << " are not cousins." << endl;
    }

    // Clean up the allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
