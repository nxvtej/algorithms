#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int n, m;
    int solve(int row, int col, vector<vector<int>> &t, vector<vector<int>> &arr)
    {
        if (row >= n || col >= m)
            return 0;
        if (arr[row][col] == 0)
            return 0;

        if (t[row][col] != -1)
            return t[row][col];

        int hor = solve(row, col + 1, t, arr);
        int ver = solve(row + 1, col, t, arr);
        int diag = solve(row + 1, col + 1, t, arr);

        return t[row][col] = min(hor, min(ver, diag)) + 1;
    }

public:
    int countSquares(vector<vector<int>> &arr)
    {
        n = arr.size();
        m = arr[0].size();

        vector<vector<int>> t(n + 1, vector<int>(m + 1, -1));

        int result = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == 1)
                {
                    result += solve(i, j, t, arr);
                }
            }
        }

        return result;
    }
};

// bottom up 2 ways either from 0 to n, or from n to 0
class Solution
{
public:
    int countSquares(vector<vector<int>> &arr)
    {
        int n = arr.size();
        int m = arr[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));
        int sum = 0;

        // 0 to n;
        /*
                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){

                        if(i == 0 || j ==0){
                            dp[i][j] = arr[i][j];
                        }

                        else if(arr[i][j] == 1) {
                            dp[i][j] = min(dp[i-1][j],  min(dp[i-1][j-1],
           dp[i][j-1])) + 1;
                        }
                        // sum += dp[i][j];
                            sum+=dp[i][j];
                    }
                }
                */

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (arr[i][j] == 1)
                {
                    if (i == n - 1 || j == m - 1)
                        dp[i][j] = arr[i][j];
                    else
                    {

                        dp[i][j] = std::min(dp[i + 1][j], std::min(dp[i][j + 1], dp[i + 1][j + 1])) + 1;
                    }
                    sum += dp[i][j];
                }
            }
        }

        return sum;
    }
};
/*
1277. Count Square Submatrices with All Ones
Solved
Medium
Topics
Companies
Hint
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.



Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation:
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix =
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation:
There are 6 squares of side 1.
There is 1 square of side 2.
Total number of squares = 6 + 1 = 7.


Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1

*/