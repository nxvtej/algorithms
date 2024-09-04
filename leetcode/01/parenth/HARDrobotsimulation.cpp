#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <numeric>
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
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        // given orgin at 0,  0;
        int x = 0, y = 0;
        int maxDistance = 0;
        // given pointing to north
        pair<int, int> dir = {0, 1};

        // given obstracles try fitting in set to get in O(1)
        set<string> obs;
        for (auto it : obstacles)
        {
            int dx = it[0];
            int dy = it[1];

            obs.insert(to_string(dx) + "_" + to_string(dy));
            // marked
        }

        for (int i = 0; i < commands.size(); i++)
        {

            if (commands[i] == -2)
            {
                dir = {-dir.second, dir.first};
            }
            else if (commands[i] == -1)
            {
                dir = {dir.second,
                       -dir.first};
            }
            else
            {
                for (int command = 0; command < commands[i]; command++)
                {
                    int dx = x + dir.first;
                    int dy = y + dir.second;

                    string checkObs = to_string(dx) + "_" + to_string(dy);
                    if (obs.find(checkObs) != obs.end())
                    {
                        break;
                    }
                    x = dx;
                    y = dy;
                }
            }

            maxDistance = max(maxDistance, x * x + y * y);
        }

        return maxDistance;
    }
};
/*
874. Walking Robot Simulation
Solved
Medium

A robot on an infinite XY-plane starts at point (0, 0) facing north.
The robot can receive a sequence of these three possible types of commands:

-2: Turn left 90 degrees.
-1: Turn right 90 degrees.
1 <= k <= 9: Move forward k units, one unit at a time.
Some of the grid squares are obstacles. The ith obstacle is at grid point obstacles[i] = (xi, yi).
If the robot runs into an obstacle, then it will instead stay in its current location and move on to the next command.

Return the maximum Euclidean distance that the robot ever gets from the origin squared (i.e. if the distance is 5, return 25).

Note:

North means +Y direction.
East means +X direction.
South means -Y direction.
West means -X direction.
There can be obstacle in [0,0].


Example 1:

Input: commands = [4,-1,3], obstacles = []
Output: 25
Explanation: The robot starts at (0, 0):
1. Move north 4 units to (0, 4).
2. Turn right.
3. Move east 3 units to (3, 4).
The furthest point the robot ever gets from the origin is (3, 4), which squared is 32 + 42 = 25 units away.
*/