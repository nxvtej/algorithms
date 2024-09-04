#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <string>
#include <queue>
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
    int longestValidParentheses(string s)
    {
        int left = 0;
        int right = 0;
        int maxLength = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                left++;
            else
                right++;

            if (right == left)
            {
                maxLength = max(maxLength, left * 2);
            }
            else if (right > left)
            {
                right = 0;
                left = 0;
            }
        }

        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == '(')
                left++;
            else
                right++;

            if (right == left)
            {
                maxLength = max(maxLength, left * 2);
            }
            else if (right < left)
            {
                right = 0;
                left = 0;
            }
        }

        return maxLength;
    }
};
/*
32. Longest Valid Parentheses
Solved
Hard
Topics
Companies
Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses
substring
.



Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0


Constraints:

0 <= s.length <= 3 * 104
s[i] is '(', or ')'.
*/