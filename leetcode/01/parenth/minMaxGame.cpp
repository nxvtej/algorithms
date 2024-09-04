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

class Solution
{
public:
    bool flag = true;
    int minMaxGame(vector<int> &nums)
    {
        while (nums.size() != 1)
        {
            // int m = nums.size() / 2;
            // why half
            vi temp;

            // for (int i = 0; i < m; i++)
            for (int i = 0; i < nums.size(); i++)
            {
                if (flag)
                {
                    temp.pb(min(nums[i], nums[i + 1]));
                    flag = !flag;
                }
                else
                {
                    temp.pb(max(nums[i], nums[i + 1]));
                    flag = !flag;
                }
            }

            nums = temp;
        }

        return nums[0];
    }
};
/*
2293. Min Max Game

Easy
Topics
Companies
Hint
You are given a 0-indexed integer array nums whose length is a power of 2.

Apply the following algorithm on nums:

Let n be the length of nums. If n == 1, end the process. Otherwise, create a new 0-indexed integer array newNums of length n / 2.
For every even index i where 0 <= i < n / 2, assign the value of newNums[i] as min(nums[2 * i], nums[2 * i + 1]).
For every odd index i where 0 <= i < n / 2, assign the value of newNums[i] as max(nums[2 * i], nums[2 * i + 1]).
Replace the array nums with newNums.
Repeat the entire process starting from step 1.
Return the last number that remains in nums after applying the algorithm.

 */