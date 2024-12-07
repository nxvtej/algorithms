#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <cmath>

using namespace std;

#define intL long long
#define MOD 1000000007
#define pb push_back
#define popb pop_back
#define mp make_pair
#define ff first
#define ss second

typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<intL> vi;
typedef vector<pii> vpi;

intL findSum(intL n)
{
    intL sum = 0;

    for (intL i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            sum += i;

            if (i != n / i)
            {
                sum += n / i;
            }
        }
    }

    return sum;
}

void solve()
{
    int n;
    cin >> n;
    vi a(n, 0);

    for (auto &it : a)
    {
        cin >> it;
    }

    vi result;
    for (auto it : a)
    {
        result.pb(findSum(it));
    }

    for (auto it : result)
    {
        cout << it << " ";
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 1;
    while (n--)
    {
        solve();
    }
    return 0;
}