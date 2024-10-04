#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long largestPerimeter(vector<int> &nums)
    {
        // return triangleNumber(nums);
        if (nums.size() < 3)
            return -1;
        sort(nums.begin(), nums.end());
        long long sum = nums[0] + nums[1];
        long long maxi = 0;
        for (int i = 2; i < nums.size(); i++)
        {
            if (sum > nums[i])
            {
                maxi = sum + nums[i];
            }
            sum += nums[i];
        }

        return maxi > 0 ? maxi : -1;
    }
};