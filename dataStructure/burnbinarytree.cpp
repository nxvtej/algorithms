#include <bits/stdc++.h>
using namespace std;

class Solution {
private:

struct Node {
    int data ;
    struct Node* left;
    struct Node* right;

};
    Node* createParentMapping(Node* root, int target, map<Node*, Node*>& nodeToParent) {
        Node* res = nullptr;
        queue<Node*> q;
        q.push(root);
        nodeToParent[root] = nullptr;

        while (!q.empty()) {
            Node* front = q.front();
            q.pop();

            if (front->data == target) {
                res = front;
            }

            if (front->left) {
                nodeToParent[front->left] = front;
                q.push(front->left);
            }
            if (front->right) {
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }

        return res;
    }

    int burnTree(Node* root, map<Node*, Node*>& nodeToParent) {
        if (!root) {
            return 0;
        }

        unordered_map<Node*, bool> visited;
        queue<Node*> q;
        q.push(root);
        visited[root] = true;

        int ans = 0;

        while (!q.empty()) {
            int size = q.size();
            bool flag = false;

            for (int i = 0; i < size; i++) {
                Node* front = q.front();
                q.pop();

                if (front->left && !visited[front->left]) {
                    flag = true;
                    q.push(front->left);
                    visited[front->left] = true;
                }
                if (front->right && !visited[front->right]) {
                    flag = true;
                    q.push(front->right);
                    visited[front->right] = true;
                }
                if (nodeToParent[front] && !visited[nodeToParent[front]]) {
                    flag = true;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = true;
                }
            }

            if (flag) {
                ans++;
            }
        }

        return ans;
    }

public:
    int minTime(Node* root, int target) {
        map<Node*, Node*> nodeToParent;
        Node* targetNode = createParentMapping(root, target, nodeToParent);
        int ans = burnTree(targetNode, nodeToParent);
        return ans;
    }
};