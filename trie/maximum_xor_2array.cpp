/*
Problem statement
You are given two arrays of non-negative integers say ‘arr1’ and ‘arr2’. Your task is to find the maximum value of ( ‘A’ xor ‘B’ ) where ‘A’ and ‘B’ are any elements from ‘arr1’ and ‘arr2’ respectively and ‘xor’ represents the bitwise xor operation.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <=  T  <= 5
1 <=  N, M <= 1000
0 <=  arr1[i], arr2[i]  <= 10 ^ 9

Where 'T' denotes the number of test cases, 'N', ‘M’ denotes the number of elements in the first array and second array, ‘arr1[i]', and ‘arr2[i]’ denotes the 'i-th' element of the first array and second array.

Time limit: 1 sec
Sample Input 1:
1
7 7
6 6 0 6 8 5 6
1 7 1 7 8 0 2
Sample Output 1:
15
Explanation of sample input 1:
First testcase:
Possible pairs are (6, 7), (6, 8), (6, 2), (8, 7), (8, 8), (6, 2). And 8 xor 7 will give the maximum result i.e. 15
Sample Input 2:
1
3 3
25 10 2
8 5 3
Sample Output 2:
28
Explanation of sample input 2:
First test case:
28 is the maximum possible xor given by pair = (25, 5). It is the maximum possible xor among all possible pairs.
*/
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vpi vector<pair<int, int>>
#define vs vector<string>
// #define via vector<int> []
#define qi queue<int>
#define qp queue<pair<int, int>>
#define qpf queue<pair<pair<int, int>, int>>

#define si set<int>
#define sii set<pair<int, int>>
#define sp set<pair<int, int>>
#define svii set<vector<pair<int, int>>>

#define pb push_back
#define ff front().first
#define fff front().first.first
#define ffs front().first.second
#define fs front().second

#include <bits/stdc++.h>

struct Node
{
    Node *links[2];
    bool containsKey(int bit)
    {
        return (links[bit] != NULL);
    }
    Node *get(int bit)
    {
        return links[bit];
    }
    void put(int bit, Node *node)
    {
        links[bit] = node;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

public:
    void insert(int num)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

public:
    int getMax(int num)
    {
        Node *node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (node->containsKey(1 - bit))
            {
                maxNum = maxNum | (1 << i);
                node = node->get(1 - bit);
            }
            else
            {
                node = node->get(bit);
            }
        }

        return maxNum;
    }
};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2)
{
    // Write your code here.
    Trie trie;
    for (auto &it : arr1)
    {
        trie.insert(it);
    }
    int maxi = 0;
    for (auto &it : arr2)
    {
        maxi = max(maxi, trie.getMax(it));
    }
    return maxi;
}

// #include <iostream>
// #include <vector>
// using namespace std;

// // Your Node and Trie classes go here

// int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2)
// {
//     // Your code goes here
// }

int main()
{
    vector<vector<int>> test_cases = {
        {1, 2, 3, 4, 5},
        {10, 20, 30, 40, 50},
        {100, 200, 300, 400, 500},
        {1000, 2000, 3000, 4000, 5000}};
    vector<vector<int>> test_cases2 = {
        {6, 7, 8, 9, 10},
        {60, 70, 80, 90, 100},
        {600, 700, 800, 900, 1000},
        {6000, 7000, 8000, 9000, 10000}};

    for (int i = 0; i < test_cases.size(); i++)
    {
        cout << "Test case " << i + 1 << ": " << maxXOR(test_cases[i].size(), test_cases2[i].size(), test_cases[i], test_cases2[i]) << endl;
    }

    return 0;
}
