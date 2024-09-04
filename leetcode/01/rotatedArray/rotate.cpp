#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <string>
#include <queue>
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
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;
        if (k == 0)
            return;
        auto reverse = [](vi &nums, int left, int right)
        {
            while (left <= right)
            {
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
        };

        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);

        return;
    }
};