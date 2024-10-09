/*

1963. Minimum Number of Swaps to Make the String Balanced
Solved
Medium
Topics
Companies
Hint
You are given a 0-indexed string s of even length n. The string consists of exactly n / 2 opening brackets '[' and n / 2 closing brackets ']'.

A string is called balanced if and only if:

It is the empty string, or
It can be written as AB, where both A and B are balanced strings, or
It can be written as [C], where C is a balanced string.
You may swap the brackets at any two indices any number of times.

Return the minimum number of swaps to make s balanced.



Example 1:

Input: s = "][]["
Output: 1
Explanation: You can make the string balanced by swapping index 0 with index 3.
The resulting string is "[[]]".
Example 2:

Input: s = "]]][[["
Output: 2
Explanation: You can do the following to make the string balanced:
- Swap index 0 with index 4. s = "[]][][".
- Swap index 1 with index 5. s =
*/
/*
1. one way is to have stack and store only de arranged brackets like befor pushing into stack check
2. in stack we will have only ]]][[[  always equal
so now formula could be like n+1/2 , as one swap from one side fized another so divide by 2, +1 cause if odd no
of brackets are present on another size, then boom,

got answer
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minSwaps(string s)
    {
        int size = 0;
        int n = 0;

        while (n < s.size())
        {
            if (s[n] == '[')
            {
                size++;
            }
            else if (size > 0)
                size--;

            n++;
        }

        return (size + 1) / 2;
    }
};