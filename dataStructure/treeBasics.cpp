#include <iostream>
#include <queue>

using namespace std;

class node
{
public:
    int data;
    node *right;
    node *left;

    node(int data)
    {
        this->data = data;
        this->right = this->left = NULL;
    }
};

node *buildtree(node *root)
{
    int data;
    cout << "Enter the data" << endl;
    cin >> data;
    root = new node(data);

    if (data == -1)
        return NULL;

    cout << "enter data for left child of " << data << endl;
    root->left = buildtree(root->left);
    cout << "enter data for right child of " << data << endl;
    root->right = buildtree(root->right);

    return root;
}

void buildtreelevelorder(node* &root) {
    
}

void printtree(node *root)
{
    if (root == NULL)
    {
        cout << "\n";
        return;
    }
    cout << root->data << ", ";
    printtree(root->left);
    printtree(root->right);
    // cout<<"\n";
}

/* printing tree
level order traversal
*/

void levelordertraversal(node *root)
{
    // lets use queue
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inorder(node* root) {
    // base case
    if(root==NULL) return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node* root) {
    if(root==NULL) return ;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root) {
    if(root == NULL) return ;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main()
{
    node *root = NULL;
    root = buildtree(root);
    cout << "\nprinting the tree :\n";
    printtree(root);

    levelordertraversal(root);
    cout<<"inOrder traversal\n";
    inorder(root);
    cout<<"\npreOrder traversal\n";
    preorder(root);
    cout<<"\npostOrder traversal\n";
    postorder(root);
    return 0;
}

// 3 2 -1 1 -1 -1 8 4 -1 -1 5 4 7 -1 -1 -1 -1