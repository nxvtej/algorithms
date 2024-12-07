#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>

using namespace std;

#define intL long long
#define MOD 1000000007

typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vpi;

void solve()
{
    string s;
    cin >> s;

    bool replaced = true;
    int seconds = 0;

    const int size_ = s.size();
    while (replaced)
    {
        replaced = false;

        string modified = s;
        for (int i = 0; i < size_ - 1; i++)
        {
            if (s[i] == '0' && s[i + 1] == '1')
            {
                modified[i] = '1';
                modified[i + 1] = '0';
                replaced = true;
            }
        }
        if (replaced)
            seconds++;
        s = modified;
    }
    cout << s << endl;
    cout << seconds << endl;
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 1;
    // cin >> n;

    while (n--)
    {
        solve();
    }

    return 0;
}