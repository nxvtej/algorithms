#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
int solve(vector<P> &arr)
{
    vector<P> mergedInterval;
    mergedInterval.push_back(arr[0]);
    int flag = true;
    for (int i = 1; i < arr.size(); i++)
    {
        if (flag && arr[i].first <= mergedInterval.back().second)
        {
            mergedInterval.back().second = max(mergedInterval.back().second, arr[i].second);
            flag = false;
        }
        else
        {
            flag = true;
            mergedInterval.push_back(arr[i]);
        }
    }
    // for(auto it: mergedInterval){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }

    return mergedInterval.size();
}
int main()
{
    // your code goes here
    int one = 1;
    int testcase = 0;
    cin >> testcase;

    while (testcase--)
    {
        int size = 0;
        cin >> size;

        std::vector<P> interval;
        int first = 0, second = 0;
        for (int i = 0; i < size; i++)
        {
            cin >> first >> second;
            interval.push_back(make_pair(first, second));
            first = 0;
            second = 0;
        }

        // for(auto it: interval){

        //         cout<<it.first<<it.second;

        //     cout<<" ";
        // }
        // cout<<"\n";

        if (interval.size() == 1)
        {
            cout << 1 << "\n";
            continue;
        }
        sort(interval.begin(), interval.end());

        cout << solve(interval) << "\n";
    }
    return 0;
}
