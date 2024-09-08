#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <numeric>
#include <map>
#include <set>
#include <list>
#include <semaphore.h> // Not needed for this problem, but included as per your original code

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

class Solution
{
private:
    // Memoization approach (Helper function)
    int solveMemo(int n, vector<int> &nums, int currentIndex, int prevIndex, vector<vector<int>> &dp)
    {
        if (currentIndex == n)
            return 0;

        if (dp[currentIndex][prevIndex + 1] != -1)
            return dp[currentIndex][prevIndex + 1];

        int take = 0;
        int nottake = 0;

        if (prevIndex == -1 || nums[currentIndex] > nums[prevIndex])
        {
            take = 1 + solveMemo(n, nums, currentIndex + 1, currentIndex, dp);
        }

        nottake = solveMemo(n, nums, currentIndex + 1, prevIndex, dp);

        return dp[currentIndex][prevIndex + 1] = max(take, nottake);
    }

public:
    // 1. Memoization (Top-Down) Approach
    int lengthOfLIS_Memo(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solveMemo(n, nums, 0, -1, dp);
    }

    // 2. Tabulation (Bottom-Up) Approach
    int lengthOfLIS_Tabulation(vector<int> &nums)
    {
        int n = nums.size();
        // Initialize DP table with 0
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // Base case: when currentIndex == n, LIS is 0
        for (int prev = 0; prev <= n; prev++)
        {
            dp[n][prev] = 0;
        }

        // Fill the table in reverse order
        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int take = 0;
                int nottake = 0;

                if (prev == -1 || nums[curr] > nums[prev])
                {
                    take = 1 + dp[curr + 1][curr + 1];
                }

                nottake = dp[curr + 1][prev + 1];

                dp[curr][prev + 1] = max(take, nottake);
            }
        }

        return dp[0][-1 + 1];
    }

    // 3. Space Optimization Approach
    int lengthOfLIS_SpaceOptim(vector<int> &nums)
    {
        int n = nums.size();
        // Initialize nextRow and currRow with 0
        vector<int> nextRow(n + 1, 0);
        vector<int> currRow(n + 1, 0);

        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int take = 0;
                int nottake = 0;

                if (prev == -1 || nums[curr] > nums[prev])
                {
                    take = 1 + nextRow[curr + 1];
                }

                nottake = nextRow[prev + 1];

                currRow[prev + 1] = max(take, nottake);
            }
            nextRow = currRow;
        }

        return nextRow[-1 + 1];
    }

    // 4. Optimal O(n log n) Approach
    int lengthOfLIS_Optimal(vector<int> &nums)
    {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            auto it = lower_bound(ans.begin(), ans.end(), nums[i]);
            if (it == ans.end())
                ans.push_back(nums[i]);
            else
                *it = nums[i];
        }
        return ans.size();
    }
};

int32_t main()
{
    // Example inputs
    vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> nums2 = {0, 1, 0, 3, 2, 3};
    vector<int> nums3 = {7, 7, 7, 7, 7, 7, 7};

    // Create Solution object
    Solution sol;

    // Function to display results for a given vector and all approaches
    auto displayResults = [&](const vector<int> &nums, const string &name)
    {
        // Make a non-const copy since the methods expect non-const vectors
        vector<int> copy_nums = nums;

        cout << "Results for " << name << ":\n";

        // 1. Memoization
        int memo = sol.lengthOfLIS_Memo(copy_nums);
        cout << "Memoization Approach: " << memo << endl;

        // 2. Tabulation
        int tab = sol.lengthOfLIS_Tabulation(copy_nums);
        cout << "Tabulation Approach: " << tab << endl;

        // 3. Space Optimization
        int spaceOpt = sol.lengthOfLIS_SpaceOptim(copy_nums);
        cout << "Space Optimization Approach: " << spaceOpt << endl;

        // 4. Optimal O(n log n)
        int optimal = sol.lengthOfLIS_Optimal(copy_nums);
        cout << "Optimal O(n log n) Approach: " << optimal << endl;

        cout << "--------------------------\n";
    };

    // Display results for each vector
    displayResults(nums1, "nums1");
    displayResults(nums2, "nums2");
    displayResults(nums3, "nums3");

    return 0;
}

/*
300. Longest Increasing Subsequence
Solved
Medium
Topics
Companies
Given an integer array nums, return the length of the longest strictly increasing
subsequence

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1


Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104


Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
s*/