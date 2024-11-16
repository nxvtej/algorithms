/*
Ques 1 -> Ordered Substrings

You are given a string X. You have to generate the set
(all unique) of all the substrings of X and then sort
that set lexicographically. Now to have to tell the rank
of the string X in the new set formed.
Note: String X contains only lowercase English letters.
eg : “eren”
Lexicograhically Sorted set of unique
substrings of X =
{“e”, “en”, “er”, “ere”, “eren”, “n”, “r”, “re”, “ren”}
Rank of “eren” = 5
Note: Time complexity matters, optimize your algorithm
*/

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

  for (auto &it : ans)
  {
    if (it == test)
      cout << "**" << it << "**";
    continue;
    cout << it << endl;
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
