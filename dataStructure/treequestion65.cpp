#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left ;
    struct Node* right ;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
// longest path sum of nodes
class Solution
{
public:
    
    void solve(Node* root , int sum , int &maxSum, int len, int &maxLen) {
        // base case 
        if(root==NULL) {
            if(len > maxLen) {
                maxLen = len;
                maxSum = sum;
            }
            else if(len == maxLen) {
                maxSum =max(sum, maxSum);
            }
            return;
        }
        sum = sum+root->data;
        solve(root->left,sum,maxSum,len+1,maxLen);
        solve(root->right,sum,maxSum,len+1,maxLen);
                
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        int len=0;
        int maxLen =0;
        
        int sum=0;
        int maxSum =0;
        solve(root,sum, maxSum, len, maxLen);
        return maxSum;
    }
};

// k sum path


class Solution{
  public:
  void solve(Node* root, int k, int &count, vector<int> path) {
      if(root==NULL) return ;
      path.push_back(root->data);
      
    //   left 
    solve(root->left, k, count, path);
    solve(root->right, k, count, path);
    
    // check for k sum
    int size=path.size();
    int sum =0;
    for(int i=size-1;i>=0;i--) {
        sum+=path[i];
        if(sum==k) count++;
    }
    path.pop_back();
  }
    int sumK(Node *root,int k)
    {
        // code here 
        vector<int> path;
        int count =0;
        solve(root,k,count,path);
        return count;
    }
};

// optimized way
class Solution{
  public:
   #define ll long long
    map<ll ,int> mp;
    int ans=0;
    void solve(Node* root, int targetSum,ll currSum){
        if(root==NULL) return;
        currSum+=root->data;
        ans+=mp[currSum-targetSum];//it mean between the ongoing process there is a place where targetSum is generated.
        mp[currSum]++;
        solve(root->left , targetSum,currSum);
        solve(root->right , targetSum,currSum);
        mp[currSum]--;
        currSum-=root->data;

    }
    int sumK(Node *root,int k)
    {
 mp[0]++;
        ll currSum=0;
        solve(root,k,currSum);
        return ans;
    }
};
 
//  kth ancestor 

Node* solve(Node* root,  int &k, int node) {
    if(root==NULL) return NULL;
    if(root->data == node) {
        return root;
    }
    
    Node* leftAns = solve(root->left, k, node);
    Node* rightAns = solve(root->right, k, node);
    
    if(leftAns != NULL && rightAns ==NULL) {
        k--;
        if(k <= 0) {
            k =INT_MAX;
            return root;
        }
        return leftAns;
    }
    
    if(leftAns == NULL && rightAns != NULL) {
       k--;
        if(k <= 0) {
            k =INT_MAX;
            return root;
        }
        return rightAns; 
    }
    return NULL;
    
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    Node * ans = solve(root,k,node);
    if(ans==NULL || ans->data == node) return -1;
    else return ans->data;
    
}

// max sum without taking adjacent node


class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    pair<int,int> solve(Node* root) {
        if(root==NULL) {
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        pair<int,int> leftans=solve(root->left);
        pair<int,int> rightans=solve(root->right);
            
            pair<int,int> result;
            result.first = root->data+leftans.second+rightans.second;
            result.second = max(leftans.first,leftans.second) + max(rightans.first,rightans.second);
            return result;
}
    int getMaxSum(Node *root) 
    {
    pair<int, int> ans= solve(root);
    return max(ans.first,ans.second);
        
    }
};