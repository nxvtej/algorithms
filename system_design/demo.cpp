#include <bits/stdc++.h>
using namespace std;

// customised comparator function
static bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first != b.first)
        return a.first < b.first;
    return a.second > b.second;
    // index values in increasing order
}

void solve()
{
    function<void>
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vec.push_back({x, i});
    }
    sort(vec.begin(), vec.end(), cmp);

    int prev = n + 1;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (vec[i].second < prev)
        {
            ans++;
            prev = vec[i].second;
            cout << prev << " ";
        }
    }
    cout << ans << endl;

    return 0;
}