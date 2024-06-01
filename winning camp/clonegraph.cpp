#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
    private: unordered_map<Node*, Node*> mpp;
public:
    Node* cloneGraph(Node* node) {
        
        //  first possiblity when head is null 
        if(node==NULL) return NULL;
        
        // then create new node assign the valeuer to that node;
        Node* first = new Node(node->val, {});
        mpp[node] =first;

        queue<Node*> q;
        q.push(node); 

        // traverse while graph 
        while(!q.empty()) {
            Node* current = q.front();
            q.pop();

            for(auto it: current->neighbors) {
                if(mpp.find(it) == mpp.end()) {
mpp[it] = new Node(it->val, {});
                q.push(it);
                }
                mpp[current]->neighbors.push_back(mpp[it]);
            }
            
        }

    
    return mpp[node];
    }
};