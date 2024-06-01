#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s) {
  // Write your code here.
  vector<vector<int>> ans;
 
unordered_map<int, int> helper;
    for (int i = 0; i < arr.size(); i++) {
        while(helper[s-arr[i]] > 0) {
          ans.push_back({min(arr[i], s-arr[i]), max(arr[i], s-arr[i])});
          helper[s-arr[i]]--;
        }
        helper[arr[i]]++;
    }
  sort(ans.begin(),ans.end());
  return ans;
}

int main() {
  vector<int> arr = {2, -3, 3, 3, -2};
  int s = 0;
  vector<vector<int>> expected = {{-3, 3}, {-3, 3}, {-2, 2}};
  vector<vector<int>> actual = pairSum(arr, s);
  assert(expected == actual);
  cout << "All test cases passed!" << endl;
  return 0;
}