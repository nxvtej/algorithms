
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int c1 = 0, c2 = 0;
        int val1 = -1, val2 = -1; // Initialize to invalid values

        // Step 1: Find potential candidates for majority elements using Moore's Voting Algorithm
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == val1)
            {
                c1++;
            }
            else if (nums[i] == val2)
            {
                c2++;
            }
            else if (c1 == 0)
            {
                val1 = nums[i];
                c1 = 1;
            }
            else if (c2 == 0)
            {
                val2 = nums[i];
                c2 = 1;
            }
            else
            {
                c1--;
                c2--;
            }
        }

        // Step 2: Verify the potential candidates
        int cnt1 = 0, cnt2 = 0;
        for (int num : nums)
        {
            if (num == val1)
                cnt1++;
            else if (num == val2)
                cnt2++;
        }

        // Step 3: Collect the results
        vector<int> ans;
        if (cnt1 > n / 3)
            ans.push_back(val1);
        if (cnt2 > n / 3)
            ans.push_back(val2);

        return ans;
    }
};

/*

229. Majority Element II
Solved
Medium
Topics
Companies
Hint
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.



Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]


Constraints:

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109


Follow up: Could you solve the problem in linear time and in O(1) space?*/