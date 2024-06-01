#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;

ll T = 1;

int solve()
{
    ll a, b, c;
    ll num;
    cin >> a >> b >> c;

    ll x = __gcd(b, c);
    if (x == c)
    {
        cout << -1 << endl;
        return 0;
    }
    else
    {
        num = (a / b) + 1;

        if ((num * b) % c == 0)
        {
            num++;
        
        }
    }
    cout << num * b << endl;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}
