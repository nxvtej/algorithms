#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSquareStreak(vector<int> &nums)
    {

        // better approach using set and checking each num square

        unordered_set<int> st(nums.begin(), nums.end());
        int maxStreak = 0;

        for (int &num : nums)
        {

            long long currentNum = num;
            int currentStreak = 0;
            while (st.find(currentNum) != st.end())
            {
                currentStreak++;
                // given constraint observation
                if (currentNum * currentNum > 10e5)
                    break;
                currentNum *= currentNum;
            }

            maxStreak = max(maxStreak, currentStreak);
        }
        return maxStreak < 2 ? -1 : maxStreak;

        /*
        // good approach

        sort(nums.begin(), nums.end());
        unordered_map<int, int> mpp;
        int maxStreak=0;

        for(int num: nums){
            int root = (int)sqrt(num);
            if(num == root*root && mpp.find(root) != mpp.end()){
                mpp[num]=mpp[root]+1;

                maxStreak = max(maxStreak, mpp[num]);
            } else {
                mpp[num]=1;
            }
        }

        return maxStreak < 2 ? -1 : maxStreak;
        */
    }
};

/*
2501. Longest Square Streak in an Array
Solved
Medium
Topics
Companies
Hint
You are given an integer array nums. A subsequence of nums is called a square streak if:

The length of the subsequence is at least 2, and
after sorting the subsequence, each element (except the first element) is the square of the previous number.
Return the length of the longest square streak in nums, or return -1 if there is no square streak.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.



Example 1:

Input: nums = [4,3,6,16,8,2]
Output: 3
Explanation: Choose the subsequence [4,16,2]. After sorting it, it becomes [2,4,16].
- 4 = 2 * 2.
- 16 = 4 * 4.
Therefore, [4,16,2] is a square streak.
It can be shown that every subsequence of length 4 is not a square streak.
Example 2:

Input: nums = [2,3,5,6,7]
Output: -1
Explanation: There is no square streak in nums so return -1.


Constraints:

2 <= nums.length <= 105
2 <= nums[i] <= 105

*/