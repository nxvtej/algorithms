#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int triangleNumber(vector<int> &nums)
    {
        if (nums.size() < 3)
            return 0;
        int count = 0;
        sort(nums.begin(), nums.end());
        int k = 2;
        for (; k < nums.size(); k++)
        {
            int left = 0, right = k - 1;

            while (left < right)
            {
                if (nums[left] + nums[right] > nums[k])
                {
                    count += right - left;
                    right -= 1;
                }
                else
                {
                    left += 1;
                }
            }
        }

        return count;
    }

public:
    int triangleNumber(vector<int> &nums)
    {
        if (nums.size() < 3)
            return 0;
        int count = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= nums.size() - 3; i++)
        {
            int first = nums[i]; // 2
            cout << first;
            for (int j = i + 1; j <= nums.size() - 2; j++)
            {
                int second = nums[j]; // 3
                cout << second;
                for (int k = j + 1; k <= nums.size() - 1; k++)
                {
                    int third = nums[k]; // 4
                    cout << third;
                    if ((first + second > third) && (first + third > second) &&
                        (second + third > first))
                    {

                        count++; // 1
                    }
                    else
                    {
                        cout << "\n";
                        break;
                    }
                }
            }
        }

        return count;
    }
};