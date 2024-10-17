#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long maxKelements(vector<int> &nums, int k)
    {
        priority_queue<int> maxHeap;
        for (auto it : nums)
        {
            maxHeap.push(it);
        }
        long long answer = 0;
        int topElement = 0;
        while (k--)
        {
            topElement = maxHeap.top();
            maxHeap.pop();
            answer += topElement;
            maxHeap.push((topElement + 2) / 3);
        }
        return answer;
    }
};

// similar problem
// given

// sliding window size, means only look into this portion
// get max out of this and insert max into left most index of window
// how to get max, of window.
// how to update left and move forward

// Step:-1
// can build max heap for k size
// Step:-2 get max, store it on left index
// move left++, move right, push right into heap,
// and repeat
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        priority_queue<int> maxHeap;
        unordered_map<int, int> prevEl;

        for (int i = 0; i < k; i++)
        {
            prevEl[nums[i]]++;
            maxHeap.push(nums[i]);
        }

        vector<int> answer;
        int left = 0, right = k - 1;

        while (right < nums.size())
        {
            while (!maxHeap.empty() && prevEl[maxHeap.top()] <= 0)
            {
                maxHeap.pop();
            }

            int maxEle = maxHeap.top();
            answer.push_back(maxEle);

            prevEl[nums[left]]--;
            left++;
            right++;

            // Add the new element to the window
            if (right < nums.size())
            {
                maxHeap.push(nums[right]);
                prevEl[nums[right]]++;
            }
        }

        return answer;
    }
};

/*
2530. Maximal Score After Applying K Operations
Solved
Medium
Topics
Companies
Hint
You are given a 0-indexed integer array nums and an integer k. You have a starting score of 0.

In one operation:

choose an index i such that 0 <= i < nums.length,
increase your score by nums[i], and
replace nums[i] with ceil(nums[i] / 3).
Return the maximum possible score you can attain after applying exactly k operations.

The ceiling function ceil(val) is the least integer greater than or equal to val.



Example 1:

Input: nums = [10,10,10,10,10], k = 5
Output: 50
Explanation: Apply the operation to each array element exactly once. The final score is 10 + 10 + 10 + 10 + 10 = 50.
Example 2:

Input: nums = [1,10,3,3,3], k = 3
Output: 17
Explanation: You can do the following operations:
Operation 1: Select i = 1, so nums becomes [1,4,3,3,3]. Your score increases by 10.
Operation 2: Select i = 1, so nums becomes [1,2,3,3,3]. Your score increases by 4.
Operation 3: Select i = 2, so nums becomes [1,1,1,3,3]. Your score increases by 3.
The final score is 10 + 4 + 3 = 17.


Constraints:

1 <= nums.length, k <= 105
1 <= nums[i] <= 109

*/

// 76. Minimum Window Substring
class Solution
{
public:
    bool check(unordered_map<char, int> &freq)
    {
        for (auto it : freq)
        {
            if (it.second > 0)
                return false;
        }
        return true;
    }
    string minWindow(string s, string t)
    {
        unordered_map<char, int> freq;
        for (char ch : t)
        {
            freq[ch]++;
        }

        int start = 0, end = 0, n = s.size(), m = t.size();
        int head = 0, d = INT_MAX;
        while (end < n)
        {
            freq[s[end]]--;
            end++;
            while (check(freq))
            {
                int length = end - start;
                cout << length;
                if (length < d)
                {
                    head = start;
                    d = length;

                    if (length == m)
                        return s.substr(head, length);
                }
                freq[s[start++]]++;
            }
        }

        return d == INT_MAX ? "" : s.substr(head, d);
    }
};