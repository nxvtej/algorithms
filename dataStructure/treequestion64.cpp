#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;
struct Node
{
};
// zig zak traversal , spiral traversal;
class Solution
{
public:
    // Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node *root)
    {
        // Code here
        vector<int> result;
        if (root == NULL)
            return result;

        queue<Node *> q;
        q.push(root);

        bool lefttoright = true;

        while (!q.empty())
        {
            int size = q.size();
            vector<int> ans(size);

            // level process
            for (int i = 0; i < size; i++)
            {
                Node *frontNode = q.front();
                q.pop();

                // normal insert
                int index = lefttoright ? i : size - i - 1;
                ans[index] = frontNode->data;

                if (frontNode->left)
                    q.push(frontNode->left);
                if (frontNode->right)
                    q.push(frontNode->right);
            }

            // change direction
            lefttoright = !lefttoright;
            for (auto i : ans)
            {
                result.push_back(i);
            }
        }
        return result;
    }
};

// boundary traversal

class Solution
{
public:
    // can do this in 3 steps
    // print left nodes excluding the leaf nodes
    // print all leaf nodes
    // now print right side  nodes in reverse order

    void printleft(Node *root, vector<int> &ans)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return;
        ans.push_back(root->data);
        if (root->left)
        {
            printleft(root->left, ans);
        }
        else
            printleft(root->right, ans);
    }
    // use in order
    void printleafnode(Node *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data);
            // return;
        }

        printleafnode(root->left, ans);
        printleafnode(root->right, ans);
    }
    void printright(Node *root, vector<int> &ans)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return;
        if (root->right)
        {
            printright(root->right, ans);
        }
        else
        {
            printright(root->left, ans);
        }
        ans.push_back(root->data);
        //  return;
        //  if() return ;
    }
    vector<int> boundary(Node *root)
    {
        // Your code here
        vector<int> ans;
        if (root == NULL)
            return ans;
        // cout<<root->data<<
        ans.push_back(root->data);
        // print left part
        printleft(root->left, ans);

        // traverse all leaf nodes
        printleafnode(root->left, ans);
        printleafnode(root->right, ans);
        // right sde
        printright(root->right, ans);
        return ans;
    }
};

// vertical traversal

vector<int> verticalOrder(Node *root)
{
    // Your code here
    //  need some data structure to represent the horizontal mapping
    //  to map horiz. we need vertical maping

    map<int, map<int, vector<int>>> nodes;
    queue<pair<Node *, pair<int, int>>> q;
    vector<int> ans;

    if (root == NULL)
        return ans;

    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty())
    {
        Node *frontNode = q.front().first;
        // now lets store hd , lvl just to traversal
        int hd = q.front().second.first;
        int lvl = q.front().second.second;
        nodes[hd][lvl].push_back(frontNode->data);
        q.pop();
        if (frontNode->left)
            q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));
        if (frontNode->right)
            q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
    }
    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
                ans.push_back(k);
        }
    }
    return ans;
}

// top view of graph

vector<int> topView(Node *root)
{
    // Your code here
    vector<int> ans;

    if (root == NULL)
        return ans;

    map<int, int> topNodes;
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int hd = temp.second;

        if (topNodes.find(hd) == topNodes.end())
        {
            topNodes[hd] = frontNode->data;
        }
        if (frontNode->left)
            q.push(make_pair(frontNode->left, hd - 1));
        if (frontNode->right)
            q.push(make_pair(frontNode->right, hd + 1));
    }

    for (auto i : topNodes)
    {
        ans.push_back(i.second);
    }
    return ans;
}

//  bottom view of bianry tree
vector<int> bottomView(Node *root)
{
    vector<int> ans;

    if (root == NULL)
        return ans;

    map<int, int> topNodes;
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int hd = temp.second;

        topNodes[hd] = frontNode->data;
        if (frontNode->left)
            q.push(make_pair(frontNode->left, hd - 1));
        if (frontNode->right)
            q.push(make_pair(frontNode->right, hd + 1));
    }

    for (auto i : topNodes)
    {
        ans.push_back(i.second);
    }
    return ans;
}

// left view 
void solve(Node* root , vector<int> &ans , int lvl) {
    if(root==NULL) return ;
    // we entered a new level
    if(lvl == ans.size()) 
    ans.push_back(root->data);
    
    solve(root->left, ans , lvl +1);
    solve(root->right , ans , lvl+1);
}
vector<int> leftView(Node *root)
{
   // just need to take first node of every level 
   vector<int> ans;
   solve(root, ans ,0);
   return ans;
   
}

// right view 
// now we just need to reverse the call 
class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    void solve(Node* root , vector<int> &ans , int lvl) {
    if(root==NULL) return ;
    // we entered a new level
    if(lvl == ans.size()) 
    ans.push_back(root->data);
    
    solve(root->right , ans , lvl+1);
    solve(root->left, ans , lvl +1);
}
    vector<int> rightView(Node *root)
    {
       vector<int> ans;
   solve(root, ans ,0);
   return ans;
    }
};

// diagonal traversal 

vector<int> diagonal(Node *root)
{
   // your code here
   vector<int> ans;
   if(root==NULL) return ans;
   queue<Node*> q;
   q.push(root);

   while(!q.empty()) {
       Node* current = q.front();
       q.pop();
       while(current!=NULL) {
           
           if(current->left != NULL)
           q.push(current->left);
           
           ans.push_back(current->data);
           
           current = current->right;
           
       }
   }
   return ans;  
}

// didn't quite understand 
// lets use map to map some left key and then store right diagonals as the vectors;

void solve(Node* &root , int diagonal, map<int, vector<int>> &mp) {
    if(root==NULL) return ;
    mp[diagonal].push_back(root->data);
    solve(root->left, diagonal+1,mp);
    solve(root->right , diagonal , mp);
}

vector<int> diagonal(Node *root)
{
    map<int , vector<int > > mp;
    solve(root, 1 , mp);
    vector<int> ans;
    for(auto it = mp.begin() ; it!=mp.end();it++) {
        // this one is also correct 
        // just remember when working with map you do it->second , as its map its mapping to next element
        
        // ans.insert(ans.end(),it.second.begin(),it.second.end());
        vector<int> temp = it->second;
        for(int i=0;i<temp.size();i++) {
            ans.push_back(temp[i]);
        }
    }
    return ans;
}
