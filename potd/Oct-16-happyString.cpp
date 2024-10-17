#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    typedef pair<int, char> P;
    string longestDiverseString(int a, int b, int c)
    {

        priority_queue<P, vector<P>> maxHeap;
        string answer = "";

        if (a > 0)
        {
            P it = make_pair(a, 'a');
            maxHeap.push(it);
        }
        if (b > 0)
        {
            P it = make_pair(b, 'b');
            maxHeap.push(it);
        }
        if (c > 0)
        {
            P it = make_pair(c, 'c');
            maxHeap.push(it);
        }

        while (!maxHeap.empty())
        {
            int charCount = maxHeap.top().first;
            char character = maxHeap.top().second;
            maxHeap.pop();

            int runningLength = answer.size();
            if (answer.length() > 1 && answer[runningLength - 1] == character && answer[runningLength - 2] == character)
            {
                if (maxHeap.empty())
                {
                    break;
                }

                int nextcharCount = maxHeap.top().first;
                char nextcharacter = maxHeap.top().second;
                maxHeap.pop();

                answer.push_back(nextcharacter);
                nextcharCount--;

                if (nextcharCount > 0)
                {
                    maxHeap.push({nextcharCount, nextcharacter});
                }
            }
            else
            {
                answer.push_back(character);
                charCount--;
            }
            if (charCount > 0)
                maxHeap.push({charCount, character});
        }

        return answer;
    }
};
/*
1405. Longest Happy String
Solved
Medium
Topics
Companies
Hint
A string s is called happy if it satisfies the following conditions:

s only contains the letters 'a', 'b', and 'c'.
s does not contain any of "aaa", "bbb", or "ccc" as a substring.
s contains at most a occurrences of the letter 'a'.
s contains at most b occurrences of the letter 'b'.
s contains at most c occurrences of the letter 'c'.
Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".

A substring is a contiguous sequence of characters within a string.



Example 1:

Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.
Example 2:

Input: a = 7, b = 1, c = 0
Output: "aabaa"
Explanation: It is the only correct answer in this case.


Constraints:

0 <= a, b, c <= 100
a + b + c > 0
*/
