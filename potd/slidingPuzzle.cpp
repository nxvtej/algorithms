/*
773. Sliding Puzzle
Solved
Hard
Topics
Companies
Hint
On an 2 x 3 board, there are five tiles labeled from 1 to 5, and an empty square represented by 0. A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.

The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].

Given the puzzle board board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.



Example 1:


Input: board = [[1,2,3],[4,0,5]]
Output: 1
Explanation: Swap the 0 and the 5 in one move.
Example 2:


Input: board = [[1,2,3],[5,4,0]]
Output: -1
Explanation: No number of moves will make the board solved.
Example 3:


Input: board = [[4,1,2],[5,0,3]]
Output: 5
Explanation: 5 is the smallest number of moves that solves the board.
An example path:
After move 0: [[4,1,2],[5,0,3]]
After move 1: [[4,1,2],[0,5,3]]
After move 2: [[0,1,2],[4,5,3]]
After move 3: [[1,0,2],[4,5,3]]
After move 4: [[1,2,0],[4,5,3]]
After move 5: [[1,2,3],[4,5,0]]


Constraints:

board.length == 2
board[i].length == 3
0 <= board[i][j] <= 5
Each value board[i][j] is unique.

Seen this question in a real interview before?
1/5
Yes
No
Accepted
117.1K
Submissions
172.4K
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int slidingPuzzle(vector<vector<int>> &board)
    {

        string target = "123450";
        string starting = "";

        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                starting += to_string(board[i][j]);
            }
        }

        if (starting == target)
            return 0;
        queue<string> que;
        unordered_map<int, vector<int>> mpp;
        mpp[0] = {1, 3};
        mpp[1] = {0, 2, 4};
        mpp[2] = {1, 5};
        mpp[3] = {0, 4};
        mpp[4] = {3, 1, 5};
        mpp[5] = {4, 2};
        unordered_set<string> vis;
        vis.insert(starting);

        que.push(starting);
        int count = 0;

        while (!que.empty())
        {
            int n = que.size();

            while (n--)
            {
                string curr = que.front();
                que.pop();

                if (curr == target)
                    return count;

                int zeroIndex = curr.find('0');

                for (int it : mpp[zeroIndex])
                {
                    string newString = curr;

                    // char firstCh = curr[zeroIndex];
                    // newString[zeroIndex] = curr[it];
                    // newString[it] = firstCh;

                    swap(newString[zeroIndex], newString[it]);

                    if (vis.find(newString) == vis.end())
                    {
                        que.push(newString);
                        vis.insert(newString);
                    }
                }
            }
            count++;
        }

        cout << starting;
        return -1;
    }
};