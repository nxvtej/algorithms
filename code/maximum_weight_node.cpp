#include <vector>
#include <limits>
#include <iostream>

using namespace std;

// Function to find the node number of maximum weight node
int findMaxWeightNode(int n, const vector<int>& edges) {
    vector<int> weights(n, 0); // Initialize weights to 0

    // Count weights of all nodes
    for (int i = 0; i < n; i++) {
        if (edges[i] != -1) {
            weights[edges[i]] += i; // Increment weight of the node pointed by edges[i]
        }
    }

    // Find the node with maximum weight
    int maxWeightNode = -1;
    int maxWeight = numeric_limits<int>::min();
    for (int i = 0; i < n; i++) {
        if (weights[i] > maxWeight) {
            maxWeight = weights[i];
            maxWeightNode = i;
        }
    }

    return maxWeightNode;
}

int main() {
    int testCase=0;
    cin>>testCase;
    while(testCase--){
    int n; // Number of cells
    cin >> n;

    vector<int> edges(n); // Edge connections (example)
    for (int i = 0; i < n; i++) {
        cin >> edges[i];
    }

    int maxWeightNode = findMaxWeightNode(n, edges);

    if (maxWeightNode == -1) {
        cout << "No node found." << endl;
    } else {
        cout << "The node with maximum weight is: " << maxWeightNode << endl;
    }
}
    return 0;
}
