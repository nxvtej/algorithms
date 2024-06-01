#include<iostream>
#include<vector>

#define vi vector<int>

using namespace std;

int search(vi &nums, int target, int start, int end){
if(start <= end){
int mid = start + (end-start)/2;
  if(nums[mid] < target) return search(nums, target, mid+1, end);
  else if(nums[mid] > target) return search(nums, target, start,  mid-1);
  else return mid;
}
  return -1;
}
int find(vi &nums, int target){
  int start =0;
  int end =1;
  while(target > nums[end]){
  int newstart = end+1;
  end = end + (end - start + 1)*2;  
    start = newstart;
  }
  
  return search(nums, target, start, end);
}
int main(){
cout<<"starting here with vector<int>";
  vector<int> nums = {9, 37, 38, 39, 61, 65, 83, 121, 154, 165, 167, 180, 189, 191, 244, 260, 267, 267, 284, 296, 307, 308, 310, 311, 320, 323, 323, 329, 344, 354, 364, 370, 393, 415, 422, 440, 441, 443, 444, 452, 477, 478, 480, 487, 492, 492, 496, 499, 504, 519, 533, 546, 555, 586, 590, 591, 594, 606, 613, 620, 622, 626, 631, 633, 639, 642, 657, 684, 707, 720, 728, 734, 735, 735, 747, 752, 786, 804, 833, 844, 873, 901, 901, 913, 934, 935, 935, 936, 945, 947, 950, 957, 963, 969, 969, 971, 975, 977, 988, 991};

  int target = 620;
  cout<<find(nums, target);
}