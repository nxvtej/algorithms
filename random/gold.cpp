#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int minGoldLost(int N, const vector<int> &locations)
{
    vector<int> dp(N, 0); // dp[i] will store the minimum gold lost up to the ith location
    sort(locations.begin(), locations.end());

    dp[0] = abs(locations[0]); // First location, gold lost is the distance from 0

    for (int i = 1; i < N; ++i)
    {
        dp[i] = abs(locations[i] - 0); // Initial case for the first element

        // Calculate the minimum gold lost for all previous positions
        for (int j = 0; j < i; ++j)
        {
            dp[i] = min(dp[i], dp[j] + abs(locations[i] - locations[j]));
        }
    }

    int total_gold = 0;
    for (int i = 0; i < N; ++i)
    {
        total_gold += dp[i];
    }

    return total_gold;
}

int main()
{
    int N;
    cin >> N;
    vector<int> locations(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> locations[i];
    }

    cout << minGoldLost(N, locations) << endl;

    return 0;
}
