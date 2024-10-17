#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t = 0;
    cin >> t;

    while (t--)
    {
        int n = 0;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }

        int wealth = arr[n - 1];
        int count = 0;

        for (int i = arr.size() - 2; i >= 0; i--)
        {
            if (arr[i] <= wealth / 2)
            {
                count++;
            }
            else
                break;
        }

        cout << n - count << "\n";
    }

    return 0;
}
