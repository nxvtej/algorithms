/*class Solution {
private:
    int findPivot(vector<int>& arr, int n) {
        int left = 0;
        int right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

    if(arr[left] == arr[mid] && arr[right] == arr[mid]) {
        left++;
        right--;
        continue;
    }
            if (mid < right && arr[mid] > arr[mid + 1])
                return mid;
            if (mid > left && arr[mid] < arr[mid - 1])
                return mid - 1;

            if(arr[left] <= arr[mid]){
                right = mid-1;
            } else {
                left = mid+1;
            }
        }

        return -1;
    }

public:
    int findMin(vector<int>& nums) {
        int pivot = findPivot(nums, nums.size());

        if (pivot == -1)
            return nums[0];

        // int i=pivot+1;
        int i = pivot + 1;
        while (i < nums.size() && nums[i] == nums[pivot + 1]) i++;
        return nums[i];
    }
};*/

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int low = 0;
        int high = nums.size() - 1;

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high])
            {
                low = mid + 1;
            }
            else if (nums[mid] < nums[high])
            {
                high = mid;
            }
            else
            {
                high--;
            }
        }

        return nums[low];
    }
};
