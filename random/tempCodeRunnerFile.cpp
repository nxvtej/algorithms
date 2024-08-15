
/*
#include <bits/stdc++.h>
using namespace std;

struct Node
{
public:
    int data;

    Node *left;
    Node *right;
    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

Node *buildTree()
{
    int data;
    cin >> data;

    if (data == -1)
        return nullptr;

    Node *node = new Node(data);
    cout << "enter left node data for " << node->data << " : ";
    node->left = buildTree();

    cout << "enter right node data for " << node->data << " : ";
    node->right = buildTree();
    return node;
}

void printinorder(Node *node)
{
    if (node == nullptr)
        return;

    printinorder(node->left);
    cout << node->data << " ";
    printinorder(node->right);
    return;
}
int main()
{
    cout << "step1: build tree\nenter root data or -1 for nullptr: ";
    Node *root = buildTree();
    cout << "\nprinting the tree: ";
    printinorder(root);
}
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

bool isSingleInputMode()
{
    // Peek to see how many items are in the input stream
    int peekedChar = cin.peek();
    // If the next character is a digit, assume multiple inputs
    return isdigit(peekedChar);
}

Node *buildTree(bool singleInputMode)
{
    int data;
    cin >> data;

    if (data == -1)
        return nullptr;

    Node *node = new Node(data);

    if (!singleInputMode)
    {
        cout << "enter left node data for " << node->data << " : ";
    }
    node->left = buildTree(singleInputMode);

    if (!singleInputMode)
    {
        cout << "enter right node data for " << node->data << " : ";
    }
    node->right = buildTree(singleInputMode);

    return node;
}

void printInOrder(Node *node)
{
    if (node == nullptr)
        return;

    printInOrder(node->left);
    cout << node->data << " ";
    printInOrder(node->right);
}

int main()
{
    cout << "Step 1: Build tree\nenter root data or -1 for nullptr: ";

    // Determine input mode
    bool singleInputMode = isSingleInputMode();

    Node *root = buildTree(singleInputMode);

    cout << "Printing the tree (In-Order Traversal): ";
    printInOrder(root);
    cout << endl;

    return 0;
}
