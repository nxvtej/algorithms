#include <bits/stdc++.h>
using namespace std;

// A function to return the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
    // Create a vector to store the items in the knapsack
    vector<int> items;

    // Sort the items by decreasing value-to-weight ratio
    sort(items.begin(), items.end(), [](int i, int j) {
        return (double)val[i] / wt[i] > (double)val[j] / wt[j];
    });

    // Iterate over the items and add them to the knapsack if possible
    int currWeight = 0;
    int maxValue = 0;
    for (int i = 0; i < n; i++)
    {
        if (currWeight + wt[i] <= W)
        {
            currWeight += wt[i];
            maxValue += val[i];
            items.push_back(i);
        }
    }

    // Return the maximum value
    return maxValue;
}

// Driver code
int main()
{
    int W = 50; // Capacity of the knapsack
    int wt[] = {10, 20, 30}; // Weights of the items
    int val[] = {60, 100, 120}; // Values of the items
    int n = sizeof(wt) / sizeof(wt[0]); // Number of items

    // Solve the knapsack problem
    int maxValue = knapSack(W, wt, val, n);

    // Print the maximum value
    cout << "The maximum value that can be put in the knapsack is: " << maxValue << endl;

    return 0;
}