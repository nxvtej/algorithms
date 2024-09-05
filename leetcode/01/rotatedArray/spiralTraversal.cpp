#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <string>
#include <queue>
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

class Solution
{
public:
    void solve(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        int top = 0, bottom = n - 1;
        int left = 0, right = m - 1;

        while (left <= right && top <= bottom)
        {

            for (int i = top; i <= right; i++) // t = 0, r = 2
            {
                cout << mat[top][i] << " ";
            }

            top++;

            for (int i = top; i <= bottom; i++) // r = 2, b 2
            {
                cout << mat[i][right] << " ";
            }

            right--;

            for (int i = right; i >= left; i--) // r=1
            {
                cout << mat[bottom][i] << " ";
            }

            bottom--;

            for (int i = bottom; i >= top; i--)
            {
                cout << mat[i][left] << " ";
            }
            left++;
        }
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    sol.solve(mat);
    return 0;
}