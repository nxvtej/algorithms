#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
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
    int lengthOfLIS(vector<int> &nums)
    {

        vector<int> ans;
        int n = nums.size();
        int i = 0;
        while (i < n)
        {
            auto it = lower_bound(begin(ans), end(ans), nums[i]);
            if (it == end(ans))
                ans.push_back(nums[i]);
            else
                *it = nums[i];
            i++;
        }
        return ans.size();
    }
};