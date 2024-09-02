// good question
#include <iostream>
#include <vector>
#define vi vector<int>
#define vvi vector<vector<int>>
using namespace std;

void solveO1(vi &nums, int n)
{
    int single = 0;
    for (auto it : nums)
    {
        single ^= it;
    }
    cout << single << "\n";
}

void optimalSolve(vi &nums, int n)
{
    int start = 0;
    int end = n - 1;
    while (start < end)
    {
        int mid = (end - start) / 2 + start;

        if (mid % 2 == 0)
        {
            if (nums[mid] == nums[mid + 1])
                start = mid + 2;
            else
                end = mid;
        }
        else
        {
            if (nums[mid] == nums[mid - 1])
            {
                start = mid + 1;
            }
            else
            {
                end = mid;
            }
        }
    }

    // cout << nums[start] << "\n";
    cout << nums[end] << "\n";
}
int main()
{
    int n = 5;
    vi nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    optimalSolve(nums, n);
    return 0;
}
/*
Q1) Given an array of integers where every element appears even number of times except one element which appears odd number of times,
write a program to find that odd occurring element in O(log n) time. The equal elements must appear in pairs in the array
but there cannot be more than two consecutive occurrences of an element.

For example :
3
2 3 2
It doesn't have equal elements appear in pairs

7
1 1 2 2 2 3 3
It contains three consecutive instances of an element.

5
2 2 3 1 1
It is valid and the odd occurring element present in it is 3.

Enter only valid inputs.
Sample Input :
5
2 2 3 1 1

Sample Output :
3

*/