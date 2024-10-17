// failed on some test case
class Solution
{
public:
    bool check(int low, int high, vector<vector<int>> &nums)
    {
        int mached = false;
        int count = 0;
        for (auto num : nums)
        {
            for (auto temp : num)
            { // first vecvtor
                if (temp <= high && temp >= low)
                {
                    count++;
                    break;
                }
            }
        }
        return count == nums.size();
    }
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        int low, high;
        vector<int> temp;
        for (auto it : nums)
        {
            for (auto num : it)
            {
                temp.push_back(num);
            }
        }
        sort(temp.begin(), temp.end());
        int size = temp.size();
        pair<int, int> answer = make_pair(temp[0], temp[size - 1]);

        int prevDiff = INT_MAX;
        for (int i = 0; i < size - 2; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                int low = temp[i];
                int high = temp[j];
                int diff = high - low;
                if (check(low, high, nums))
                {
                    if (prevDiff > diff)
                    {
                        prevDiff = diff;
                        answer.first = low;
                        answer.second = high;
                    }

                    if (prevDiff == diff)
                    {
                        if (answer.first < low)
                        {
                            continue;
                        }
                    }
                }
            }
        }
        return {answer.first, answer.second};
    }
};

/*
632. Smallest Range Covering Elements from K Lists
Attempted
Hard
Topics
Companies
You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.



Example 1:

Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation:
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
Example 2:

Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]


Constraints:

nums.length == k
1 <= k <= 3500
1 <= nums[i].length <= 50
-105 <= nums[i][j] <= 105
nums[i] is sorted in non-decreasing order.
 */
//