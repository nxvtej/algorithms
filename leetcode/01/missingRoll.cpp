

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
    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
    {

        if (n == 0)
            return rolls;
        int size = rolls.size();
        int totalSum = 0;
        for (auto it : rolls)
            totalSum += it;

        int req = mean * (size + n) - totalSum;
        if (req > 6 * n or req < n)
            return {};

        vector<int> result(n, req / n);

        int rem = req % n;
        for (int i = 0; i < rem; i++)
        {
            result[i]++;
        }
        return result;
        /*-
        if(req % n ==0){
            while(n-- > 0){
                result.push_back(req/n);
            }
        }
        if(n == 0) return result;

        int firstelement = floor(req/n) + req%n;
        result.push_back(firstelement);
        n--;
        while(n--){
            result.push_back(req/n);
        }

        return result;

        */
    }
};

/*
2028. Find Missing Observations
Solved
Medium
Topics
Companies
Hint
You have observations of n + m 6-sided dice rolls with each face numbered from 1 to 6. n of the observations went missing, and you only have the observations of m rolls. Fortunately, you have also calculated the average value of the n + m rolls.

You are given an integer array rolls of length m where rolls[i] is the value of the ith observation. You are also given the two integers mean and n.

Return an array of length n containing the missing observations such that the average value of the n + m rolls is exactly mean. If there are multiple valid answers, return any of them. If no such array exists, return an empty array.

The average value of a set of k numbers is the sum of the numbers divided by k.

Note that mean is an integer, so the sum of the n + m rolls should be divisible by n + m.



Example 1:

Input: rolls = [3,2,4,3], mean = 4, n = 2
Output: [6,6]
Explanation: The mean of all n + m rolls is (3 + 2 + 4 + 3 + 6 + 6) / 6 = 4.
Example 2:

Input: rolls = [1,5,6], mean = 3, n = 4
Output: [2,3,2,2]
Explanation: The mean of all n + m rolls is (1 + 5 + 6 + 2 + 3 + 2 + 2) / 7 = 3.
Example 3:

Input: rolls = [1,2,3,4], mean = 6, n = 4
Output: []
Explanation: It is impossible for the mean to be 6 no matter what the 4 missing rolls are.


Constraints:

m == rolls.length
1 <= n, m <= 105
1 <= rolls[i], mean <= 6
*/