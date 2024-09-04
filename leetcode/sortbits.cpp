#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <numeric>
#include <bitset>
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

/*
class Solution {
private:
    int countbits(int& a) {
        int temp = a;

        int bits = 0;
        while (temp > 0) {
            bits += temp & 1;
            temp >>=1;
        }
        return bits;
    }

public:
    vector<int> sortByBits(vector<int>& arr) {

        auto lambda = [&](int& a, int& b) {
            int abits = countbits(a);
            int bbits = countbits(b);

            if (abits == bbits)
                return a < b;
            return abits < bbits;
        };

        auto defaultlambda = [](int &a, int &b){
            int abits = __builtin_popcount(a);
            int bbits = __builtin_popcount(b);

            if(abits == bbits) return a < b;
            return abits < bbits;
        };

        sort(arr.begin(), arr.end(), defaultlambda);

        return arr;
    }
};

*/

class Solution
{
public:
    static bool customCompare(const int &a, const int &b)
    {
        int x = bitset<32>(a).count();
        int y = bitset<32>(b).count();
        if (x != y)
            return x < y;
        return a < b;
    }

    vector<int> sortByBits(vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), customCompare);
        return arr;
    }
};