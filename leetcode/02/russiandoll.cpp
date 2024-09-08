#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b)
{
    if (a[0] == b[0])
        return a[1] > b[1];
    else
        return a[0] < b[0];
}
class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &env)
    {
        sort(env.begin(), env.end(), cmp);
        vector<int> ans;
        ans.push_back(env[0][1]);
        for (int i = 1; i < env.size(); i++)
        {
            int ind = -1;

            if (ans.back() < env[i][1])
                ans.push_back(env[i][1]);
            else
            {
                ind = lower_bound(ans.begin(), ans.end(), env[i][1]) - ans.begin();
                if (ind < ans.size())
                {
                    ans[ind] = env[i][1];
                }
            }
        }
        return ans.size();
    }
};
// my coed
class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        auto cmp = [&](auto a, auto b)
        {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        };
        sort(begin(envelopes), end(envelopes), cmp);

        int n = envelopes.size();
        vector<int> height(n, 0);

        for (int i = 0; i < n; i++)
        {
            height[i] = envelopes[i][1];
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            auto it = lower_bound(begin(ans), end(ans), height[i]);
            if (it == end(ans))
                ans.push_back(height[i]);
            else
                *it = height[i];
        }
        return ans.size();
    }
};

/*
354. Russian Doll Envelopes
Solved
Hard
Topics
Companies
You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.



Example 1:

Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
Example 2:

Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1


Constraints:

1 <= envelopes.length <= 105
envelopes[i].length == 2
1 <= wi, hi <= 105
*/