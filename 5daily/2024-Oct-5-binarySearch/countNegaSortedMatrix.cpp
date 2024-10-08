#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;

        for (int i = 0; i < row; i++)
        {

            int left = 0;
            int right = col - 1;
            int rowCount = 0;
            while (left <= right)
            {

                int mid = (left + right) / 2;

                if (grid[i][mid] < 0)
                {
                    rowCount = col - mid;
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }

            count += rowCount;
        }

        return count;
    }
};