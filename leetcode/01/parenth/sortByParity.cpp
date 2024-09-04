#include <iostream>
#include <vector>
#include <queue>

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

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int even = 0;
        int n = nums.size();
        int odd = n - 1;
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2 == 0)
            {
                ans[even] = nums[i];
                even++;
            }
            else
            {
                ans[odd] = nums[i];
                odd--;
            }
        }
        return ans;
    }

    vector<int> sortby(vector<int> &nums)
    {
        int left = 0;
        int right = 0;
        int n = nums.size() - 1;
        while (right <= n)
        {
            if (nums[right] % 2 == 0)
            {
                swap(nums[left], nums[right]);
                left++;
                right++;
            }
            else
            {
                right++;
            }
        }
        return nums;
    }
};

/*
905. Sort Array By Parity
Easy
Topics
Companies
Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.

Return any array that satisfies this condition.

Example 1:

Input: nums = [3,1,2,4]
Output: [2,4,3,1]
Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
Example 2:

Input: nums = [0]
Output: [0]

*/