#include <iostream>
#include <vector>
#include <map>

using namespace std;

int solve(vector<int> &nums, int k)
{
    int n = nums.size();
    map<int, int> dp;
    int sum = 0, cnt = 0;
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {

        sum += nums[i];
        int check = sum - k;
        cnt += dp[check];
        dp[sum]++;
    }

    return cnt;
}

/*

560. Subarray Sum Equals K
Solved
Medium
Topics
Companies
Hint
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2

*/