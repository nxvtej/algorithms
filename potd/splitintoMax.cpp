#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(string s, int currentIdx, unordered_set<string> &st,
               int currentSize, int &maxSize)
    {

        if (maxSize >= currentSize + (s.length() - currentIdx))
            return;

        if (currentIdx >= s.length())
        {
            maxSize = max(maxSize, currentSize);
            return;
        }

        for (int j = currentIdx; j < s.length(); j++)
        {
            string temp = s.substr(currentIdx, (j - currentIdx + 1));
            if (st.find(temp) == st.end())
            {
                st.insert(temp);
                solve(s, j + 1, st, currentSize + 1, maxSize);
                st.erase(temp);
            }
        }
    }
    int maxUniqueSplit(string s)
    {
        int currentIdx = 0;
        unordered_set<string> st;
        int currentSize = 0;
        int maxSize = 0;

        solve(s, currentIdx, st, currentSize, maxSize);

        return maxSize;
    }

    int failed(string s)
    {
        stack<string> stk;
        set<string> uniqueSubstrings;
        string currentSubstr = "";

        for (char c : s)
        {
            currentSubstr += c;

            if (uniqueSubstrings.find(currentSubstr) ==
                uniqueSubstrings.end())
            {
                stk.push(currentSubstr);
                uniqueSubstrings.insert(currentSubstr);
                currentSubstr =
                    ""; // Reset the current substring for next formation
            }
            else
            {
                while (!stk.empty() && uniqueSubstrings.find(currentSubstr) !=
                                           uniqueSubstrings.end())
                {
                    string prev = stk.top();
                    stk.pop();
                    uniqueSubstrings.erase(prev);
                    currentSubstr = prev + currentSubstr;
                }

                stk.push(currentSubstr);
                uniqueSubstrings.insert(currentSubstr);
                currentSubstr = ""; // Reset again
            }
        }
        if (!currentSubstr.empty() &&
            uniqueSubstrings.find(currentSubstr) == uniqueSubstrings.end())
        {
            stk.push(currentSubstr);
            uniqueSubstrings.insert(currentSubstr);
        }
        return stk.size();
    }
};
/*

Code
Solutions
Solutions


Testcase
Testcase
Test Result
1593. Split a String Into the Max Number of Unique Substrings
Solved
Medium
Topics
Companies
Hint
Given a string s, return the maximum number of unique substrings that the given string can be split into.

You can split string s into any list of non-empty substrings, where the concatenation of the substrings forms the original string. However, you must split the substrings such that all of them are unique.

A substring is a contiguous sequence of characters within a string.



Example 1:

Input: s = "ababccc"
Output: 5
Explanation: One way to split maximally is ['a', 'b', 'ab', 'c', 'cc']. Splitting like ['a', 'b', 'a', 'b', 'c', 'cc'] is not valid as you have 'a' and 'b' multiple times.
Example 2:

Input: s = "aba"
Output: 2
Explanation: One way to split maximally is ['a', 'ba'].
Example 3:

Input: s = "aa"
Output: 1
Explanation: It is impossible to split the string any further.


Constraints:

1 <= s.length <= 16

s contains only lower case English letters.
*/