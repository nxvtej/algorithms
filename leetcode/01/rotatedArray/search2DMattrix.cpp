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
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size();
        int col = matrix[0].size();

        int start = 0;
        // because we are thinking it as linear array (sorted already)
        int end = (row * col) - 1;
        int mid = start + (end - start) / 2;
        while (start <= end)
        {
            int element = matrix[mid / col][mid % col];
            if (element == target)
            {
                return true;
            }
            if (element < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
            mid = start + (end - start) / 2;
        }
        return false;
    }
};