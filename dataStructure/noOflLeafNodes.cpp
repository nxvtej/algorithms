#include <iostream>
#include <>

using namespace std;

// using inorder traversal technique
void inorder(BinaryTreeNode<int> *root,int &count) {
if(root==NULL) return ;
inorder(root->left,count);
if(root->left == NULL && root->right == NULL) count++;
inorder(root->right,count);
}

int noofleafnodes(BinaryTreeNode<int> *root) {
    int count =0;
    inorder(root,count);
    return count;
}

int main() {
    
    return 0;
}