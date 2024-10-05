#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int findPivot(vector<int> &arr, int n)
    {
        int left = 0;
        int right = n - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (mid < right && arr[mid] > arr[mid + 1])
                return mid;
            if (mid > left && arr[mid] < arr[mid - 1])
                return mid - 1;

            if (arr[left] < arr[mid])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return -1;
    }

public:
    int findMin(vector<int> &nums)
    {
        int pivot = findPivot(nums, nums.size());

        if (pivot == -1)
            return nums[0];
        return nums[pivot + 1];
    }
};