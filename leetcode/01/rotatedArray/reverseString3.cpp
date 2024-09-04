
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
    string reverseWords(string s)
    {
        int start = 0;
        int i = 0;
        int n = s.size();

        while (i < n)
        {
            if (s[i] != ' ')
            {
                i++;
            }
            else
            {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
                i++;
            }
        }
        if (start < n)
        {
            reverse(s.begin() + start, s.end());
        }
        return s;
    }
};
/*
557. Reverse Words in a String III
Easy
Topics
Companies
Given a string s, reverse the order of characters in each word within a sentence
while still preserving whitespace and initial word order.

Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Example 2:

Input: s = "Mr Ding"
Output: "rM gniD"

*/