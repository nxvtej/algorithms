#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <numeric>
#include <map>
#include <set>
#include <list>

#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>

#define pb push_back

#define qi queue<int>
#define qp queue<pair<int, int>>
#define ff front().first
#define fs front().second

using namespace std;
#define int long long

int minSwaps(vector<int> &arr)
{
    int n = arr.size();
    vector<pair<int, int>> sorted;
    for (int i = 0; i < n; i++)
    {
        sorted.pb({arr[i], i});
    }
    sort(sorted.begin(), sorted.end());
    int ans = 0;
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == true || sorted[i].second == i)
            continue;

        int j = sorted[i].second;
        int len = 0;
        while (vis[j] == false && sorted[j].second != j)
        {
            vis[j] = true;
            len++;
            j = sorted[j].second;
        }
        vis[j] = true;
        ans += len - 1;
    }
    return ans;
}
/*
Minimum Swaps to Sort
Difficulty: MediumAccuracy: 38.39%Submissions: 166K+Points: 4
Given an array of n distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.


Example 1:

Input:
nums = {2, 8, 5, 4}
Output:
1
Explanation:
swap 8 with 4.
Example 2:

Input:
nums = {10, 19, 6, 3, 5}
Output:
2
Explanation:
swap 10 with 3 and swap 19 with 5.

Your Task:
You do not need to read input or print anything. Your task is to complete the function minSwaps() which takes the nums as input parameter and returns an integer denoting the minimum number of swaps required to sort the array.
If the array is already sorted, return 0.


Expected Time Complexity: O(nlogn)
Expected Auxiliary Space: O(n)


Constraints:
1 ≤ n ≤ 105
1 ≤ numsi ≤ 106
*/