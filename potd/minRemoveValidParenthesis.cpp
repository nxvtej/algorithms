#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        // another approach using two string

        // first iterator left to right elimiante closing by keeping count of opne
        // second iteration right to left eliminate opening brackets

        string temp = "";
        int open = 0;
        for (auto it : s)
        {
            if (it >= 'a' && it <= 'z')
            {
                temp += it;
            }
            else if (it == '(')
            {
                open++;
                temp += it;
            }
            else if (open > 0)
            {
                open--;
                temp += it;
            }
        }

        string result = "";
        int close = 0;
        for (int i = temp.size() - 1; i >= 0; i--)
        {
            char it = temp[i];
            if (it >= 'a' && it <= 'z')
            {
                result += it;
            }
            else if (it == ')')
            {
                close++;
                result += it;
            }
            else if (close > 0)
            {
                close--;
                result += it;
            }
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        stack<pair<char, int>> st;
        string answer = "";
        int size_ = s.length();
        for (int i = 0; i < size_; i++)
        {
            char ch = s[i];
            if (ch >= 'a' && ch <= 'z')
            {
                answer += ch;
            }
            else if (ch == '(')
            {
                st.push(make_pair(ch, answer.length()));
                answer += ch;
            }
            else
            {
                if (st.empty())
                {
                    continue;
                }
                else
                {
                    st.pop();
                    answer += ch;
                }
            }
        }

        while (!st.empty())
        {
            auto top = st.top();
            st.pop();

            int idx = top.second;
            answer.erase(idx, 1);
        }

        return answer;
    }
};

/*
1249. Minimum Remove to Make Valid Parentheses
Solved
Medium
Topics
Companies
Hint
Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.


Example 1:

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
Example 2:

Input: s = "a)b(c)d"
Output: "ab(c)d"
Example 3:

Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.


Constraints:

1 <= s.length <= 105
s[i] is either '(' , ')', or lowercase En
*/