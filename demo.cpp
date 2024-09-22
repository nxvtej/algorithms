#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int main()
{

    long long result = 0;

    vector<int> arr = {2021};
    for (int i = 0; i < arr.size(); i++)
    {
        int num = arr[i];
        int lastdigit = num % 10;
        num = num / 10;

        int power = num % (10 * lastdigit);
        int base = num / (10 * lastdigit);

        long long value = pow(base, power);
        result += value;
    }

    cout << result;
}
