#include <iostream>
using namespace std;

class node {
    public :
        int data;
        node* right;
        node* left;

    node(int data) {
        this->data = data;
        this->right = left = NULL;
    }
};

node* buildtree(node* root) {
    cout<<"enter the root node\n";

    int data;
    
    cin>>data;
    root = new node(data);

    if(data == -1) return NULL;

    cout<<"enter data for inseting in left of : "<<data<<endl;
    root->left = buildtree(root->left);
    cout<<"enter data for inserting in right of : "<<data<<endl;
    root->right = buildtree(root->right);

    return root;
}

int main() {
    node* root = NULL;
    root= buildtree(root);

    return 0;
}