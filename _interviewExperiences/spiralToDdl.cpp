#include <iostream>
#include <deque>
#include <stack>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

struct DLLNode
{
    int data;
    DLLNode *prev;
    DLLNode *next;
    DLLNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

DLLNode *insertAtEnd(DLLNode *head, int val)
{
    DLLNode *newNode = new DLLNode(val);
    if (!head)
    {
        return newNode;
    }
    DLLNode *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

DLLNode *spiralOrder(TreeNode *root)
{
    if (!root)
        return nullptr;

    deque<TreeNode *> dq;
    dq.push_back(root);
    bool leftToRight = true;
    DLLNode *dllHead = nullptr;

    while (!dq.empty())
    {
        int size = dq.size();
        stack<int> levelData;

        for (int i = 0; i < size; ++i)
        {
            TreeNode *curr = leftToRight ? dq.front() : dq.back();
            if (leftToRight)
                dq.pop_front();
            else
                dq.pop_back();

            if (leftToRight)
            {
                if (curr->left)
                    dq.push_back(curr->left);
                if (curr->right)
                    dq.push_back(curr->right);
            }
            else
            {
                if (curr->right)
                    dq.push_front(curr->right);
                if (curr->left)
                    dq.push_front(curr->left);
            }

            if (leftToRight)
            {
                dllHead = insertAtEnd(dllHead, curr->data);
            }
            else
            {
                levelData.push(curr->data);
            }
        }

        while (!levelData.empty())
        {
            dllHead = insertAtEnd(dllHead, levelData.top());
            levelData.pop();
        }

        leftToRight = !leftToRight;
    }

    return dllHead;
}

void printDLL(DLLNode *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    DLLNode *dllHead = spiralOrder(root);
    printDLL(dllHead);

    return 0;
}
