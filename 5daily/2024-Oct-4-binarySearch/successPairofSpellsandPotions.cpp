#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions,
                                long long success)
    {
        vector<int> ans;
        sort(potions.begin(), potions.end());
        int n = potions.size();
        for (auto it : spells)
        {
            long long requirement = (success + it - 1) / it;
            auto inc = lower_bound(potions.begin(), potions.end(), requirement);
            int index = inc - potions.begin();

            ans.push_back(n - index);
        }

        return ans;
    }

    // almost brute force
    /*
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions,
                                long long success)
    {
        vector<int> ans;
        int pairs = 0;
        sort(potions.begin(), potions.end());
        for (auto it : spells)
        {
            pairs = 0;
            for (int i = 0; i < potions.size(); i++)
            {
                long long strength = it * (static_cast<long long>(potions[i]));
                if (strength >= success)
                {
                    pairs += potions.size() - i;
                    break;
                }
            }
            ans.push_back(pairs);
        }
        return ans;
    }
    */
};