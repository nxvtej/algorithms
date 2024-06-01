#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
// level-order traversal
class solution
{
public:
    // Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node *node)
    {
        // Your code here
        vector<int> ans;
        queue<Node *> q;
        q.push(node);
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            ans.push_back(temp->data);
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        return ans;
    }
};
// output will be simple in one line with timecomplexity of O(n)
// if we need to insert enter and print level in next line then use NULL in     queue
// lets use map to store every thing in right order

class Solution_custom
{
public:
    // Function to return the level order traversal of a tree.
    map<int, vector<int>> levelOrder(Node *node)
    {
        // Your code here
        vector<int> ans;
        queue<Node *> q;
        q.push(node);
        q.push(NULL);
        map<int, vector<int>> lvlnodeprint;
        int lvl = 0;
        bool flag = 0;

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                lvl++;

                if (!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
                // ans.push_back(temp->data);
                lvlnodeprint[lvl].push_back(temp->data);
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
        return lvlnodeprint;
    }
};

int main()
{
    // Create a sample tree (you can replace this with your own tree creation logic)
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Call the levelOrder function
    Solution_custom solutions1;
    map<int, vector<int>> level_order_map = solutions1.levelOrder(root);

    // Print the level-wise traversal
    for (auto level_nodes : level_order_map)
    {
        cout << "Level " << level_nodes.first << ": ";
        for (int node_data : level_nodes.second)
        {
            cout << node_data << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
mine version
Level 0: 1
Level 1: 2 3
Level 2: 4 5 6 7
*/

// code from coding ninjas
template <typename T>
class BinaryTreeNode
{
public:
    T val;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        BinaryTreeNode<int> *temp = q.front();
        q.pop();
        ans.push_back(temp->val);
        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
    return ans;
}

/*
Sample Input 1:
3
1 2 3 4 -1 5 6 -1 7 -1 -1 -1 -1 -1 -1
1 2 3 -1 -1 -1 -1
1 3 -1 2 -1 -1 -1
Sample Output 1:
1 2 3 4 5 6 7
1 2 3
1 3 2
*/

// leetcode version

//  * Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (root == NULL)
            return result;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int lvllen = q.size();
            vector<int> elements;

            for (int i = 0; i < lvllen; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                elements.push_back(temp->val);

                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }

            result.push_back(elements);
        }
        return result;
    }
};
/*
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 */

// ******************** NEXT CODE  * 2 *****************************

// reverse level order traversal

vector<int> reverseLevelOrder(Node *root)
{
    // code here
    vector<int> ans;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        ans.push_back(temp->data);
        if (temp->right)
            q.push(temp->right); // important change
        if (temp->left)
            q.push(temp->left);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// leetcode
class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> result;

        if (root == NULL)
            return result;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int lvllength = q.size();
            vector<int> elements;

            for (int i = 0; i < lvllength; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                elements.push_back(temp->val);

                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            result.push_back(elements);
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

/*************************NEXT QUESTION *** 3 ****************************/
// height of bianary tree
class Solution
{
public:
    // Function to find the height of a binary tree.
    int solve(struct Node *node, int h)
    {
        if (node == NULL)
            return 0;

        int leftheight = solve(node->left, h);
        int rightheight = solve(node->right, h);
        return max(leftheight, rightheight) + 1;
    }
    int height(struct Node *node)
    {
        // code here
        int h = 0;
        h = solve(node, 0);
        return h;
    }
};

/*************************NEXT QUESTION *** 4 ****************************/

// diameter of binary tree
class Solution
{
public:
    // Function to return the diameter of a Binary Tree.
    int solve(Node *node, int &diam)
    {
        if (node == NULL)
            return 0;

        int leftans = solve(node->left, diam);
        int rightans = solve(node->right, diam);
        diam = max(diam, leftans + rightans + 1);
        return 1 + max(leftans, rightans);
    }
    int diameter(Node *root)
    {
        // Your code here
        int diam = 0;
        solve(root, diam);
        return diam;
    }
};

// leet code

class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int diameter = 0;
        solve(root, diameter);
        return diameter;
    }
    int solve(TreeNode *node, int &diameter)
    {
        if (!node)
            return 0;
        int leftheight = solve(node->left, diameter);
        int rightheight = solve(node->right, diameter);
        diameter = max(diameter, leftheight + rightheight);
        return 1 + max(leftheight, rightheight);
    }
};

/*************************NEXT QUESTION *** 5 ****************************/

// mirror of given binary tree
class Solution
{
public:
    TreeNode *solve(TreeNode *root)
    {
        // TreeNode* temp;
        if (root == NULL)
            return root;
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;

        if (root->left)
            solve(root->left);
        if (root->right)
            solve(root->right);

        return root;
    }
    TreeNode *invertTree(TreeNode *root)
    {

        return solve(root);
    }
};
// coding ninja's

/*************************NEXT QUESTION *** 6 ****************************/

// reverse odd lvel of binary tree
/*
use same as previous just change is here i want to change only values
dont change nodes.
two approach
1. using queue storing all the data;
2. is using two pointers send one to right and one to left and add level

*/

class Solution
{
public:
    // int levelorder =1;
    void solve(TreeNode *root1, TreeNode *root2, int levelorder)
    {
        if (root1 == NULL || root2 == NULL)
            return;
        if (levelorder % 2 == 0)
        {
            swap(root1->val, root2->val);
        }
        solve(root1->left, root2->right, levelorder + 1);
        solve(root1->right, root2->left, levelorder + 1);
    }
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        if (root == NULL)
            return root;
        solve(root->left, root->right, 0);
        return root;
    }
};

/*************************NEXT QUESTION *** 7 ****************************/
// inorder iterative method

class Solution
{
public:
    vector<int> inOrder(Node *root)
    {
        // code here
        vector<int> ans;
        // first step create stack
        if (root == NULL)
            return ans;

        stack<Node *> s;
        Node *currentNode = root;

        while (!s.empty() || currentNode != NULL)
        {
            if (currentNode)
            {
                s.push(currentNode);
                currentNode = currentNode->left;
            }

            else
            {
                currentNode = s.top();
                s.pop();
                ans.push_back(currentNode->data);

                currentNode = currentNode->right;
            }
        }
        return ans;
    }
};

/*************************NEXT QUESTION *** 8 ****************************/
// preorder traversal

vector<int> preorderTraversal(TreeNode *root)
{
    // Write your code here
    vector<int> ans;
    if (root == NULL)
        return ans;

    stack<TreeNode *> s;
    s.push(root);

    while (!s.empty())
    {
        TreeNode *currentNode = s.top();
        s.pop();

        ans.push_back(currentNode->val);
        if (currentNode->right)
            s.push(currentNode->right);
        if (currentNode->left)
            s.push(currentNode->left);
    }
    return ans;
}

/******************************NEXT QUESTION 9****************/
// post order traversal

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

vector<int> postorderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;

    stack<TreeNode *> s;
    s.push(root);
    stack<int> out;

    while (!s.empty())
    {
        TreeNode *current = s.top();
        s.pop();

        out.push(current->data);
        if (current->left)
            s.push(current->left);
        if (current->right)
            s.push(current->right);
    }
    while (!out.empty())
    {
        ans.push_back(out.top());
        out.pop();
    }
    return ans;
}

/**********************NEXT QUESTION  10**************/
// right side view and left side view

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int lengthoflevel = q.size();
            vector<int> levelnodes;

            for (int i = 0; i < lengthoflevel; i++)
            {
                TreeNode *current = q.front();
                q.pop();

                levelnodes.push_back(current->val);
                if (current->right)
                    q.push(current->right);
                if (current->left)
                    q.push(current->left);
            }
            // reverse(levelnodes.begin(),levelnodes.end());
            int leftviewelement = levelnodes[0];
            ans.push_back(leftviewelement);
        }
        return ans;
    }
};

// even better way

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int lengthoflevel = q.size();
            int requirednode;
            ans.push_back(q.front()->val);
            for (int i = 0; i < lengthoflevel; i++)
            {
                TreeNode *current = q.front();
                q.pop();
                //    requirednode = current->val;
                if (current->right)
                    q.push(current->right);
                if (current->left)
                    q.push(current->left);
            }
            // reverse(levelnodes.begin(),levelnodes.end());
            // int leftviewelement = levelnodes[0];
            // ans.push_back(requirednode);
        }
        return ans;
    }
};

/****************************************NEXT 11*****************/
// top view of binary tree

// coding ninjas

#include <bits/stdc++.h>
vector<int> getTopView(TreeNode<int> *root)
{
    // Write your code here.
    vector<int> ans;
    if (root == NULL)
        return ans;

    map<int, int> mp;
    queue<pair<TreeNode<int> *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        auto it = q.front();
        TreeNode<int> *temp = it.first;
        int line = it.second;
        1 q.pop();
        if (mp.find(line) == mp.end())
            mp[line] = temp->data;
        if (temp->left)
            q.push(make_pair(temp->left, line - 1));
        if (temp->right)
            q.push(make_pair(temp->right, line + 1));
    }
    for (auto it : mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}

/********************************************NEXT QUESTION 12 ******************************/
// bottom view of binary tree

#include <bits/stdc++.h>
vector<int> getTopView(TreeNode<int> *root)
{
    // Write your code here.
    vector<int> ans;
    if (root == NULL)
        return ans;

    map<int, int> mp;
    queue<pair<TreeNode<int> *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        auto it = q.front();
        TreeNode<int> *temp = it.first;
        int line = it.second;
        q.pop();
        mp[line] = temp->data;
        if (temp->left)
            q.push(make_pair(temp->left, line - 1));
        if (temp->right)
            q.push(make_pair(temp->right, line + 1));
    }
    for (auto it : mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}

/*****************************NEXT QUESTION  13**************************/
// zig zak traverasl

// leet code
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;

        queue<TreeNode *> q;
        q.push(root);
        bool flag = true;
        while (!q.empty())
        {
            int len = q.size();
            vector<int> levelnodes;

            for (int i = 0; i < len; i++)
            {
                TreeNode *temp = q.front();
                q.pop();

                levelnodes.push_back(temp->val);
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            if (flag)
            {
                ans.push_back(levelnodes);
            }
            else
            {
                reverse(levelnodes.begin(), levelnodes.end());
                ans.push_back(levelnodes);
            }
            flag = !flag;
        }
        return ans;
    }
};

// coding ninjas

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    vector<int> ans;
    if (root == NULL)
        return ans;

    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    bool flag = true;
    while (!q.empty())
    {
        int len = q.size();
        vector<int> tempvec;

        for (int i = 0; i < len; i++)
        {
            BinaryTreeNode<int> *temp = q.front();
            q.pop();
            tempvec.push_back(temp->data);
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        if (flag == false)
        {
            reverse(tempvec.begin(), tempvec.end());
            for (auto it : tempvec)
            {
                ans.push_back(it);
            }
        }
        else
        {
            for (auto it : tempvec)
                ans.push_back(it);
        }
        flag = !flag;
    }
    return ans;
}

/***************************NEXT QUESTION  14******************************************/
// check i fbinary tree is balanced or not
int height(Node *root)
{
    if (root == NULL)
        return 0;
    int leftheight = height(root->left);
    int rightheight = height(root->right);
    return max(leftheight, rightheight) + 1;
}
bool checkifbalanced(Node *root)
{
    if (root = NULL)
        return true;
    bool leftans = checkifbalanced(root->left);
    bool rightans = checkifbalanced(root->right);
    bool diff = abs(height(root->left) - height(root->right)) <= 1;

    if (leftans && rightans && diff)
        return true;
    else
        return false;
}

/************************************NEXT QUESTION 15**************************************/
// diagonal tree traversal

void solve(BinaryTreeNode<int> *root, int index, map<int, vector<int>> &mpp)
{
    if (root == NULL)
        return;

    mpp[index].push_back(root->data);
    solve(root->left, index + 1, mpp);
    solve(root->right, index, mpp);
}

vector<int> diagonalPath(BinaryTreeNode<int> *root)
{
    // Write your code here.
    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, vector<int>> mpp;
    solve(root, 0, mpp);

    for (auto it : mpp)
    {
        for (auto jit : it.second)
        {
            ans.push_back(jit);
        }
    }
    return ans;
}

/**************************************NEXT QUESTION 16**************************************/
// bounday of binary tree

// coding ninjas

void solveforleft(Node *node, vector<int> &ans)
{
    if (node == NULL)
        return;

    if (node->left)
    {
        ans.push_back(node->data);
        solveforleft(node->left, ans);
    }
    else if (node->right)
    {
        ans.push_back(node->data);
        solveforleft(node->right, ans);
    }
}
void solveforleafnodes(Node *node, vector<int> &ans)
{
    if (node == NULL)
        return;

    solveforleafnodes(node->left, ans);
    if (!(node->left) && !(node->right))
        ans.push_back(node->data);
    solveforleafnodes(node->right, ans);
}
void solveforright(Node *node, vector<int> &ans)
{
    if (node == NULL)
        return;
    if (node->right)
}
vector<int> boundary_traversal(Node *node)
{
    vector<int> ans;
    if (node == NULL)
        return ans;

    ans.push_back(node->data);
    solveforleft(node, ans);
    solveforleafnodes(node->left, ans);
    solveforleafnodes(node->right, ans);
    solveforright(node->right, ans);
}

/***************************NEXT QUESTION 17*****************************/
// k-sum path in bianry tree

void solve(BinaryTreeNode<int> *root, int k, vector<int> &res,
           vector<vector<int>> &ans)
{
    if (!root)
        return;
    res.push_back(root->data);
    solve(root->left, k, res, ans);
    solve(root->right, k, res, ans);

    int temp = 0;
    for (int i = res.size() - 1; i >= 0; i--)
    {
        temp += res[i];
        if (temp == k)
        {
            vector<int> tempvec;
            for (int j = i; j < res.size(); j++)
            {
                tempvec.push_back(res[j]);
            }
            ans.push_back(tempvec);
        }
    }
    res.pop_back();
}

vector<vector<int>> kPathSum(BinaryTreeNode<int> *root, int k)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    vector<int> res;
    solve(root, k, res, ans);
    return ans;
}

/****************************NEXT QUESTIO ADDITIONAL/********************/
// construct bianry tree from string having bracket representationn

BinaryTreeNode<int> *solve(string &str, int start, int end)
{
    if (start > end)
        return nullptr;
    int i = start;
    while (i <= end && isdigit(str[i]))
    {
        i++;
    }

    int rootValue = stoi(str.substr(start, i - start));
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootValue);

    // now moving to subtree ,
    int j = i + 1; // skip opening parenthesis
    int subtreeEnd = j;
    int openCount = 1;

    while (j <= end && openCount > 0)
    {
        if (str[j] == '(')
            openCount++;
        else if (str[j] == ')')
            openCount--;
        if (openCount == 0)
            subtreeEnd = j;
        j++;
    }

    root->left = solve(str, i + 1, subtreeEnd - 1);
    root->right = solve(str, subtreeEnd + 2, end - 1);
    return root;
}

BinaryTreeNode<int> *treeFromBracket(string &str)
{
    // Write your code here
    return solve(str, 0, str.length() - 1);
}

// another approachh
// geeksforgeeks

class Solution
{
private:
    // int i= 0;

    void solve(Node *root, string &str, int &i)
    {
        if (i < str.size() && isdigit(str[i]))
        {
            int sum = 0;
            while (i < str.size() && isdigit(str[i]))
            {
                sum *= 10;
                sum += str[i] - '0';
                i++;
            }
            root->data = sum;
        }

        if (i < str.size() && str[i] == '(')
        {
            root->left = new Node(0);
            i++;
            solve(root->left, str, i);

            if (root->left->data == 0)
                root->left = NULL;
        }
        if (i < str.size() && str[i] == '(')
        {
            root->right = new Node(0);
            i++;
            solve(root->right, str, i);

            if (root->right->data == 0)
                root->right = NULL;
        }
        if (i >= str.size() || str[i] == ')')
            i++;
        return;
    }

public:
    // function to construct tree from string
    Node *treeFromString(string str)
    {
        // code here
        Node *root = new Node(0);
        // if(!str.size()) return root;
        int i = 0;
        solve(root, str, i);
        return root;
    }
};

// construct any bianry tree from the parent array

BinaryTreeNode<int> *createTree(vector<int> &parent)
{
    // Write your code here.
    int n = parent.size();
    map<int, BinaryTreeNode<int> *> mpp;
    for (int i = 0; i < n; i++)
    {
        BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(i);
        mpp[i] = newNode;
    }
    BinaryTreeNode<int> *root = NULL;
    for (int i = 0; i < n; i++)
    {
        if (parent[i] == -1)
        {
            root = mpp[i];
        }
        else
        {
            if (mpp[parent[i]]->left == NULL)
                mpp[parent[i]]->left = mpp[i];
            else
                mpp[parent[i]]->right = mpp[i];
        }
    }
    return root;
}

// more optmizied way is to use vector
// simply put vector instead of map and done

/*********************************************************************/
// check if tree is sum tree or not

int f=1;
int solve(TreeNode *root){
    if(!root->left && !root->right) return root->data;
    if(f==0) return 0;
    int a = solve(root->left);
    int b = solve(root->right);

    if(a+b != root->data) f=0;
    return a+b+root->data;
}
bool isSumTree(TreeNode *root)
{
    // Write your code here.
    f=1;
    int ans = solve(root);
    return f;
}