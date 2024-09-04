#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <numeric>
#include <map>
#include <set>

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

// soo amny wrong treis
class Solution
{
public:
    int arrayPairSum(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i)
        {
            int minin = min(nums[i], nums[i + 1]); // 1
            sum += minin;                          // 8
            i += 2;                                // i =
        }

        return sum;
    }
};

class WorkingSolution
{
public:
    int arrayPairSum(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i)
        {
            int minin = min(nums[i], nums[i + 1]); // 1
            sum += minin;                          // 8
            i += 2;                                // i =
        }
        sum = 0;

        sort(nums.begin(), nums.end());

        int n = nums.size();
        int mid = n / 2;
        // if()
        for (int i = n - 1; i > 0; i -= 2)
        {

            sum += min(nums[i], nums[i - 1]);
        }
        return sum;
    }
};

/*

561. Array Partition
Easy
Topics
Companies
Hint
Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1),
(a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.

Example 1:

Input: nums = [1,4,3,2]
Output: 4
Explanation: All possible pairings (ignoring the ordering of elements) are:
1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
So the maximum possible sum is 4.
Example 2:

Input: nums = [6,2,6,5,1,2]
Output: 9
Explanation: The optimal pairing is (2, 1), (2, 5), (6, 6). min(2, 1) + min(2, 5) + min(6, 6) = 1 + 2 + 6 = 9.

*/