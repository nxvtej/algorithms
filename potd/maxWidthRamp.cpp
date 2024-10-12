#include <bits/stdc++.h>
using namespace std;

/*

962. Maximum Width Ramp
Attempted
Medium
Topics
Companies
A ramp in an integer array nums is a pair (i, j) for which i < j and nums[i] <= nums[j]. The width of such a ramp is j - i.

Given an integer array nums, return the maximum width of a ramp in nums. If there is no ramp in nums, return 0.



Example 1:

Input: nums = [6,0,8,2,1,5]
Output: 4
Explanation: The maximum width ramp is achieved at (i, j) = (1, 5): nums[1] = 0 and nums[5] = 5.
Example 2:

Input: nums = [9,8,1,0,1,9,4,0,4,1]
Output: 7
Explanation: The maximum width ramp is achieved at (i, j) = (2, 9): nums[2] = 1 and nums[9] = 1.

 */
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
       
    // ideal 
    class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        
        // Step 1: Build a decreasing stack of indices
        for (int i = 0; i < n; ++i) {
            if (s.empty() || nums[s.top()] > nums[i]) {
                s.push(i);
            }
        }
        
        int maxWidth = 0;
        
        // Step 2: Traverse from the end and find maximum width ramp
        for (int j = n - 1; j >= 0; --j) {
            while (!s.empty() && nums[s.top()] <= nums[j]) {
                maxWidth = max(maxWidth, j - s.top());
                s.pop();
            }
        }
        
        return maxWidth;
    }
};
    // optimal
        /*
        int n=nums.size();
        vector<int>maxArr(n, 0);

        maxArr[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            maxArr[i]=max(maxArr[i+1], nums[i]);
        }

        for(auto it: maxArr) cout<<it<<" ";
        int ramp=0;
        int i=0, j=0;
        while(j < n){
            while(i<j && nums[i] > maxArr[j]){
                i++;
            }
            ramp = max(ramp, j-i);
            j++;
        }

        return ramp;

        */
    //    
        /*
        Brute force
        int ramp = 0;
        int i=0, j=nums.size()-1;

        while(i < j){
            if(nums[i] <= nums[j]){
                ramp = max(ramp, j-i);
                j = nums.size()-1;
                i++;
            }
            else if(nums[i] > nums[j]){
                j--;
            }
            if(i == j && i != nums.size()-1){
                i++;
                j=nums.size()-1;
            }
        }
        return ramp;
        */
    }
};