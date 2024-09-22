// CPP program for the above approach

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void printSubstrings(string str, string test)
{
  set<string> ans;

  // First loop for starting index
  for (int i = 0; i < str.length(); i++)
  {
    string subStr;
    // Second loop is generating sub-string
    for (int j = i; j < str.length(); j++)
    {
      subStr += str[j];
      cout << subStr << " ";
      ans.insert(subStr);
    }
  }
  cout << endl;
  cout << endl;
  cout << endl;
  // sort(ans.begin(), ans.end());
  for (auto &it : ans)
  {
    cout << it << endl;
    if (it == test)
      return;
  }
}

// Driver Code
int main()
{
  string str, test;
  cin >> str >> test;
  printSubstrings(str, test);
  return 0;
  // this code is contributed by defcdr
}
