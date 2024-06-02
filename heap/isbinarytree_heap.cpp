//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {
        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution
{
private:
    int countNodes(struct Node *tree)
    {
        if (tree == nullptr)
            return 0;
        return 1 + countNodes(tree->left) + countNodes(tree->right);
    }

    bool isCBT(struct Node *tree, int index, int count)
    {
        if (tree == nullptr)
            return true;

        if (index >= count)
        {
            return false;
        }

        return isCBT(tree->left, 2 * index + 1, count) && isCBT(tree->right, 2 * index + 2, count);
    }

    bool isMaxHeap(struct Node *tree)
    {
        if (tree->left == nullptr && tree->right == nullptr)
        {
            return true;
        }
        if (tree->right == nullptr)
        {
            return tree->data > tree->left->data;
        }

        bool leftAns = isMaxHeap(tree->left);
        bool rightAns = isMaxHeap(tree->right);

        return (
            tree->data > tree->left->data &&
            tree->data > tree->right->data &&
            leftAns && rightAns);
    }

public:
    bool isHeap(struct Node *tree)
    {
        // code here
        // needs to check two thing CBT && maxheap
        int count = countNodes(tree);

        if (isCBT(tree, 0, count) && isMaxHeap(tree))
        {
            return true;
        }

        return false;
    }
};

int main()
{
    int tc;
    scanf("%d ", &tc);
    while (tc--)
    {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}