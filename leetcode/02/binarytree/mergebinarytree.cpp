struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node *solve(Node *node, Node *root)
{
    if (node == nullptr && root == nullptr)
        return nullptr;
    else if (node == nullptr)
        return root;
    else if (root == nullptr)
        return node;

    node->data = node->data + root->data;
    node->left = solve(node->left, root->left);
    node->right = solve(node->right, root->right);
    return node;
}