class Solution
{
public:
    Node *LCA(Node *root, int n1, int n2)
    {
        // code here
        if (root == nullptr)
        {
            return nullptr;
        }

        /*
        if(root->data == n1 || root->data == n2){
            return root;
        }

        Node* left = LCA(root->left, n1, n2);
        if(left != nullptr) return left;
        Node* right = LCA(root->right, n1, n2);
        return right;

        */

        while (true)
        {
            if (root->data > n1 && root->data > n2)
            {
                root = root->left;
            }
            else if (root->data < n1 && root->data < n2)
            {
                root = root->right;
            }
            else
            {
                return root;
            }
        }
    }
};