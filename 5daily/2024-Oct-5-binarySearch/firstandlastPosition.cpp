#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int search(vector<int> &nums, int target, bool findStartIndex)
    {
        int ans = -1;
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] > target)
                end = mid - 1;
            else if (nums[mid] < target)
                start = mid + 1;
            else
            {
                ans = mid;
                if (findStartIndex)
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
        }
        return ans;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        // can bniary searchg twice one time for first and one time for last
        vector<int> ans = {-1, -1};
        ans[0] = search(nums, target, true);
        ans[1] = search(nums, target, false);
        return ans;
    }
};