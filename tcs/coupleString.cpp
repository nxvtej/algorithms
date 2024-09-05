#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>

#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>

#define pb push_back

#define qi queue<int>
#define qp queue<pair<int, int>>
#define ff front().first
#define fs front().second

using namespace std;

int main()
{

    // ssssssss
    // s7
    /*
    string s;
    cin >> s;

    int n = s.length();

    map<char, int> m;
    int count = 0;
    for (auto it : s)
    {
        m[it]++;
    }
    string result;
    for (auto &it : m)
    {
        result += it.first;
        result += to_string(it.second);
    }

    cout << result;
    */

    string s; // ssssdddeeeee
    cin >> s;

    int n = s.length();

    int start = 0, end = 0, cnt = 0;
    string result;
    while (end < n) // 0 //start = 7 end = 7
    {
        while (end <= n - 2 && s[end] == s[end + 1]) //
        {
            end++;
        }
        cnt = end - start + 1;
        result += s[start] + to_string(cnt);
        end++;
        start = end;
    }
    cout << result;
    return 0;
}
