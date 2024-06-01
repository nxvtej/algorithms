#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

// calculate the height of binary tree
class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here 
        if(node==NULL) return 0;
        
        int leftheight = height(node->left);
        int rightheight = height(node->right);
        int ans = max(leftheight,rightheight) +1;
        
    }
};

// calculate diameter of binary tree
// O(n^2) complexity
class Solution {
    int height (Node* root)  {
         if(root==NULL) return 0;
         int left = height(root->left);
         int right = height(root->right);
         
         int ans = max(left,right) +1;
         return ans;
    }

    pair<int, int> fastDiameter(Node* root) {
        if(root==NULL) {
            pair<int,int>p=make_pair(0,0);
            return p;
        }
        pair<int, int> left = fastDiameter(root->left);
        pair<int, int> right = fastDiameter(root->right);

        int op1 = left.first;
        int op2 = right.second;
        int op3 = left.second + right.second + 1;

        pair<int,int> ans;
        ans.first = max(op1,max(op2,op3));
        ans.second = max(left.second,right.second) +1;
        return ans;
    }
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // Your code here\
        
        if(root==NULL) return 0;
        int opt1 = diameter(root->left);
        int opt2 = diameter(root->right);
        int opt3 = height(root->left) + 1 + height(root->right);  // height called along diameter call;
        
        int ans = max(opt1,max(opt2,opt3));
        return ans;
        
    }
};

// check balance binary tree
// means height of left - right sub tree must be <=1 

class Solution{
    private : 
    int height(Node* root) {
        if(root==NULL) {
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        
        return max(left,right)+1;
    }

    public:
    //Function to check whether a binary tree is balanced or not.
    pair<bool,int> fastBalance(Node* root) {
        if(root==NULL) {
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        pair<bool,int> left = fastBalance(root->left);
        pair<bool,int> right = fastBalance(root->right);

        bool leftAns = left.first;
        bool rightAns = right.first;
       bool diff = abs(left.second-right.second) <= 1;

        pair<bool,int> ans;
        
        ans.second  = max(left.second , right.second) + 1;
        if(left.first && right.first && diff) ans.first = true;
        else ans.first = false;
        return ans;
    }
    bool isBalanced(Node *root)
    {
        /* //  Your Code here
        if(root==NULL) {
            return true;
        }
        bool left = isBalanced(root->left);
       bool right = isBalanced(root->right);
       bool diff = abs(height(root->left)-height(root->right)) <= 1;
    // againa same thing O(n^2)
    // optmize it
        if(left && diff && right) return 1;
        else return false;
        */

       return fastBalance(root).first;

        
    }
};


// identical trees
   
class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
        
        if(r1 ==NULL && r2 ==NULL ) return true;
        if(r1 !=NULL && r2 ==NULL ) return false;
        if(r1 ==NULL && r2 !=NULL ) return false;
        
        bool left = isIdentical(r1->left,r2->left);
        bool right = isIdentical(r1->right,r2->right);
        
        bool currentvalue = r1->data == r2->data;
        if(left && right && currentvalue) return true;
        else return false;
        
    }
};

// check sum tree or not
// Should return true if tree is Sum Tree, else false
class Solution
{
    public:
    pair<bool, int> issumtreefast(Node* node) {
    if(node == NULL) {
        pair<bool,int> p = make_pair(true,0);
        return p;
    }
    
    if(node->left ==NULL && node->right==NULL) {
        pair<bool,int> p = make_pair(true,node->data);
        return p;
    }
    
        pair<bool,int> leftAns = issumtreefast(node->left);
        pair<bool,int> rightAns = issumtreefast(node->right);
        
        bool left = leftAns.first;
        bool right = rightAns.first;
        
        bool condition = (node->data == (leftAns.second+rightAns.second)); 
        
        pair<bool,int> ans;
        if(left && right && condition) {
            ans.first = true;
            ans.second = 2*node->data;
            
        }
        else {
            ans.first = false;
        }
        return ans;
    }
    bool isSumTree(Node* root)
    {
         // Your code here
         
         return issumtreefast(root).first;
    }
};

