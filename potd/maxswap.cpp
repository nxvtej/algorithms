#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    /*
    key thing if(current > running) not >= cause i need index of right side occured element right
    because of this
    Wrong Answer
    87 / 112 testcases passed

    Editorial
    Input
    num = 1993

    Use Testcase
    Output
    9193
    Expected
    9913
     */
    int maximumSwap(int num)
    {
        string str = to_string(num);
        int n = str.length();
        vector<int> maxright(n);

        int max = 0;
        maxright[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--)
        {
            int rightMaxIdx = maxright[i + 1];
            int runningmax = str[rightMaxIdx];

            int current = str[i];
            if (current > runningmax)
            {
                maxright[i] = i;
            }
            else
            {
                maxright[i] = rightMaxIdx;
            }
        }

        for (int i = 0; i < n; i++)
        {
            int maxrightidx = maxright[i];
            int maxrightelement = str[maxrightidx];

            if (str[i] < maxrightelement)
            {
                swap(str[i], str[maxrightidx]);
                return stoi(str);
            }
        }

        return num;
    }
};
/*
670. Maximum Swap
Solved
Medium
Topics
Companies
You are given an integer num. You can swap two digits at most once to get the maximum valued number.

Return the maximum valued number you can get.



Example 1:

Input: num = 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:

Input: num = 9973
Output: 9973
Explanation: No swap.
*/