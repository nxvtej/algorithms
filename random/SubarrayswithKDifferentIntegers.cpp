#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int slidingWindow(vector<int> &nums, int k)
{
    unordered_map<int, int> map;
    int left = 0, right = 0, ans = 0;
    while (right < nums.size())
    {
        map[nums[right]]++;
        while (map.size() > k)
        {
            map[nums[left]]--;
            if (map[nums[left]] == 0)
                map.erase(nums[left]);
            left++;
        }
        ans += right - left + 1; // basically the size of subarray;
        right++;
    }
    return ans;
}
int findSubarraysWithKdifferentIntegers(vector<int> &arr, int n, int k)
{
    int forKdifferentIntegers = slidingWindow(arr, k);
    int forLessThanKdifferentIntegers = slidingWindow(arr, k - 1);

    return forKdifferentIntegers - forLessThanKdifferentIntegers;
}
int main()
{
    vector<int> arr = {50, 52, 65, 9, 55, 55, 6, 1, 1, 2, 2, 0};
    int n = arr.size();

    int k = 2;
    static int temp;
    cout << "\n :: \n"
         << temp;
    int count = findSubarraysWithKdifferentIntegers(arr, n, k);
    cout << "\n count " << count;
    return 0;
}