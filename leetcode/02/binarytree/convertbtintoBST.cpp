// User function template for C++

class Solution
{
    vector<int> lrr;
    int i = 0;

private:
    void inorderTraversal(Node *node)
    {
        if (node == nullptr)
            return;

        inorderTraversal(node->left);
        lrr.push_back(node->data);
        inorderTraversal(node->right);
        return;
    }
    void assignValue(Node *node)
    {
        if (node == nullptr)
            return;

        assignValue(node->left);
        node->data = lrr[i++];
        assignValue(node->right);
        return;
    }

public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    Node *binaryTreeToBST(Node *root)
    {
        // Your code goes here
        if (root == nullptr)
            return nullptr;
        inorderTraversal(root);
        sort(lrr.begin(), lrr.end());
        assignValue(root);
        return root;
    }
};