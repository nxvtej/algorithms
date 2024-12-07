#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        int n = box.size();
        int m = box[0].size();
        vector<vector<char>> result(m, vector<char>(n));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                result[j][i] = box[i][j];
            }
        }

        for (vector<char> &vec : result)
        {
            reverse(vec.begin(), vec.end());
        }

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (result[i][j] == '.')
                {
                    int nextBox = -1;
                    int row = i - 1;
                    // go up until box or wall is found

                    for (row = i - 1; row >= 0; row--)
                    {
                        if (result[row][j] == '#')
                        {
                            nextBox = row;
                            break;
                        }
                        else if (result[row][j] == '*')
                        {
                            break;
                        }
                    }
                    if (nextBox != -1)
                    {
                        swap(result[i][j], result[row][j]);
                    }
                    else
                    {
                        continue;
                    }
                }
            }
        }
        return result;
    }
};
/*
1861. Rotating the Box
Solved
Medium
Topics
Companies
Hint
You are given an m x n matrix of characters box representing a side-view of a box. Each cell of the box is one of the following:

A stone '#'
A stationary obstacle '*'
Empty '.'
The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions.

It is guaranteed that each stone in box rests on an obstacle, another stone, or the bottom of the box.

Return an n x m matrix representing the box after the rotation described above.



Example 1:



Input: box = [["#",".","#"]]
Output: [["."],
         ["#"],
         ["#"]]
Example 2:



Input: box = [["#",".","*","."],
              ["#","#","*","."]]
Output: [["#","."],
         ["#","#"],
         ["*","*"],
         [".","."]]
Example 3:



Input: box = [["#","#","*",".","*","."],
              ["#","#","#","*",".","."],
              ["#","#","#",".","#","."]]
Output: [[".","#","#"],
         [".","#","#"],
         ["#","#","*"],
         ["#","*","."],
         ["#",".","*"],
         ["#",".","."]]


Constraints:

m == box.length
n == box[i].length
1 <= m, n <= 500
box[i][j] is either '#', '*', or '.'.
*/