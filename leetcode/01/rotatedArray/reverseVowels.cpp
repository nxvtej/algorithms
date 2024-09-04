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

// one approach would be usign two poiutners then using while loop insdie and evey time momving the left and right  till the viowel\

// good approach would be using check to check if its vowel and then swap

// one could be one traverse and store  all the vowel into vector and replace4 them with the 1's and then re travetrse and
// replace 1's with vector pop_back

// good approach here

class Solution
{
private:
    bool check(char ch)
    {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            return true;

        return false;
    }

public:
    string reverseVowels(string s)
    {

        int left = 0;
        int right = s.size() - 1;

        while (left <= right)
        {
            if (check(s[left] && check(s[right])))
            {
                swap(s[left++], s[right--]);
            }
            else if (check(s[left]) && !check(s[right]))
            {
                right--;
            }
            else if (check(s[right]) && !check(s[left]))
            {
                left++;
            }
            else
            {
                left++;
                right--;
            }
        }

        return s;
    }
};

/*
345. Reverse Vowels of a String
Solved
Easy
Topics
Companies
Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.



Example 1:

Input: s = "hello"
Output: "holle"
Example 2:

Input: s = "leetcode"
Output: "leotcede"
*/