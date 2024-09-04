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
    string reverseStr(string s, int k)
    {

        if (k > s.length())
        {

            reverse(s.begin(), s.end());
            return s;
        }
        if (s.length() < 2 * k)
        {
            reverse(s.begin(), s.begin() + k);
            return s;
        }

        for (int i = 0; i < s.length(); i += 2 * k)
        {
            if (i + k < s.length())
                reverse(s.begin() + i, s.begin() + i + k);
            else
                reverse(s.begin() + i, s.end());
        }

        return s;
    }
};

/*

Code
Testcase
Testcase
Test Result
541. Reverse String II
Solved
Easy
Topics
Companies
Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.

If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.



Example 1:

Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Example 2:

Input: s = "abcd", k = 2
Output: "bacd"

*/