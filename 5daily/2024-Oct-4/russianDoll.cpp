#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int optimalRussianDoll(vector<pair<int, int>> doll)
    {
        int n = doll.size();
        auto cmp = [&](pair<int, int> a, pair<int, int> b)
        {
            if (a.first == b.first)
            {
                return a.second > b.second;
            }

            return a.first > b.first;
        };
        sort(doll.begin(), doll.end(), cmp);

        vector<int> height(n, 0);
        int i = 0;
        for (auto it : doll)
        {
            height[i++] = it.second;
        }
        vector<int> ans;
        for (i = 0; i < n; i++)
        {
            auto it = lower_bound(ans.begin(), ans.end(), height[i]);
            if (it == ans.end())
            {
                ans.push_back(height[i]);
            }
            else
            {
                *it = height[i];
            }
        }
        return ans.size();
    }

public:
    int russianDoll(vector<pair<int, int>> dolls)
    {
        int n = dolls.size();
        sort(dolls.begin(), dolls.end());
        vector<int> dp(n, 1);
        int ans = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (dolls[i].first > dolls[j].first && dolls[i].second > dolls[j].second)
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};