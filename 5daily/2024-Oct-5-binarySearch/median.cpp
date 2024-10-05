#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {

        if (nums1.size() > nums2.size())
        {
            vector<int> temp = nums2;
            nums2 = nums1;
            nums1 = temp;
            // findMedianSortedArrays(nums2, nums1);
            // swap(nums1, nums2);
        }

        int n = nums1.size();
        int m = nums2.size();

        int left = 0;
        int right = n;

        while (left <= right)
        {
            int Px = left + (right - left) / 2;
            int Py = (n + m + 1) / 2 - Px;

            int x1 = (Px == 0) ? INT_MIN : nums1[Px - 1];
            int y1 = (Py == 0) ? INT_MIN : nums2[Py - 1];

            int x2 = (Px == n) ? INT_MAX : nums1[Px];
            int y2 = (Py == m) ? INT_MAX : nums2[Py];

            if (x1 <= y2 && y1 <= x2)
            {
                if ((m + n) % 2 == 0)
                {
                    return (max(x1, y1) + min(x2, y2)) / 2.0;
                }
                else
                {
                    return (max(x1, y1));
                }
            }
            else if (x1 > y2)
            {
                right = Px - 1;
            }
            else
            {
                left = Px + 1;
            }
        }
        return -1;
    }
};