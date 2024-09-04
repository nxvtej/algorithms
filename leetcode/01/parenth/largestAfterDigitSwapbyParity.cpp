#include <iostream>
#include <vector>
#include <queue>

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
    int largestInteger(int num)
    {
        string s = to_string(num);

        priority_queue<int> evenDigits;
        priority_queue<int> oddDigits;
        // Separate digits into even and odd heaps

        for (auto &c : s)
        {
            int digit = c - '0';
            if (digit % 2 == 0)
            {
                evenDigits.push(digit);
            }
            else
            {
                oddDigits.push(digit);
            }
        }

        string result;

        for (auto it : s)
        {
            int digit = it - '0';
            if (digit % 2 == 0)
            {
                result += '0' + evenDigits.top();
                evenDigits.pop();
            }
            else
            {
                result += '0' + oddDigits.top();
                oddDigits.pop();
            }
        }

        return stoi(result);
    }
};

/*

2231. Largest Number After Digit Swaps by Parity
Easy
Topics
Companies

Hint
You are given a positive integer num. You may swap any two digits of num that have the same parity (i.e. both odd digits or both even digits).
Return the largest possible value of num after any number of swaps.

Example 1:

Input: num = 1234
Output: 3412
Explanation: Swap the digit 3 with the digit 1, this results in the number 3214.
Swap the digit 2 with the digit 4, this results in the number 3412.
Note that there may be other sequences of swaps but it can be shown that 3412 is the largest possible number.
Also note that we may not swap the digit 4 with the digit 1 since they are of different parities.
*/