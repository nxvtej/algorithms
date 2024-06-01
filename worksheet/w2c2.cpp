
#include <bits/stdc++.h>

#define ll long long int
using namespace std;

ll powr(ll x, ll n)
{
    ll res = 1;
    while (n)
    {
        if (n & 1)
            res = res * x % 10;
        n = n / 2;
        x = x * x % 10;
    }
    return res;
}
int main()
{   
    int T;
    cin >> T;
    while (T--)
    {
        ll x, m;
        cin >> x >> m;
        ll ld, sum = 0;
        ll z;

        while (x > 0)
        {
            ld = x % 10;
            z = powr(ld, m);
            sum = 10 * sum + z;
            x /= 10;
        }

        if (sum % 7 == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}