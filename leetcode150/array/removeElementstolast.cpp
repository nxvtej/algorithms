
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (val == nums[i])
            {
                nums.erase(nums.begin() + i);
                i--;
            }
        }

        return nums.size();
    }
};

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int i = 0, j = nums.size() - 1;
        int cnt = 0;
        while (i <= j)
        {
            if (nums[i] == val && nums[j] != val)
            {
                swap(nums[i++], nums[j--]);
                cnt++;
            }
            else if (nums[i] != val && nums[j] == val)
            {
                j--;
            }
            else if (nums[i] != val && nums[j] != val)
            {
                i++;
                cnt++;
            }
            else
            {
                j--;
            }
        }
        return cnt;
    }
};
/*

27. Remove Element
Solved
Easy
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
Return k.
Custom Judge:
*/