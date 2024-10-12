#include <bits/stdc++.h>
using namespace std;
/*
2406. Divide Intervals Into Minimum Number of Groups
Solved
Medium
Topics
Companies
Hint
You are given a 2D integer array intervals where intervals[i] = [lefti, righti] represents the inclusive interval [lefti, righti].

You have to divide the intervals into one or more groups such that each interval is in exactly one group, and no two intervals that are in the same group intersect each other.

Return the minimum number of groups you need to make.

Two intervals intersect if there is at least one common number between them. For example, the intervals [1, 5] and [5, 8] intersect.



Example 1:

Input: intervals = [[5,10],[6,8],[1,5],[2,3],[1,10]]
Output: 3
Explanation: We can divide the intervals into the following groups:
- Group 1: [1, 5], [6, 8].
- Group 2: [2, 3], [5, 10].
- Group 3: [1, 10].
It can be proven that it is not possible to divide the intervals into fewer than 3 groups.
Example 2:

Input: intervals = [[1,3],[5,6],[8,10],[11,13]]
Output: 1
Explanation: None of the intervals overlap, so we can put all of them in one group.


Constraints:

1 <= intervals.length <= 105
intervals[i].length == 2
1 <= lefti <= righti <= 106

*/

class Solution
{
public:
    int minGroups(vector<vector<int>> &intervals)
    {

        sort(intervals.begin(), intervals.end(),
             [](auto a, auto b)
             { return a[0] < b[0]; });

        priority_queue<int, vector<int>, greater<int>> minheap;

        for (auto it : intervals)
        {
            int startingPoint = it[0];
            int endingPoint = it[1];

            if (!minheap.empty() && minheap.top() < startingPoint)
            {
                minheap.pop();
                // minheap.push(endingPoint);
            }
            minheap.push(endingPoint);
        }

        return minheap.size();
        /*
                vector<int> ending;

                sort(intervals.begin(), intervals.end());

                ending.push_back(intervals[0][1]);
                int n = intervals.size();
                int group = 0, pushValue = 0;
                bool solved = false;
                for (int i = 1; i < n; i++) {
                    auto it = intervals[i];

                    int startingPoint = it[0];
                    int endingPoint = it[1];
                    solved = false;
                    int size = ending.size();
                    for (int i=0;i<size;i++) {
                        if(ending[i] <= startingPoint){
                            ending[i]=endingPoint;
                            solved=true;
                            break;
                        }
                    }
                    if( !solved && size == ending.size())
           ending.push_back(endingPoint);
                }

                return ending.size();
                */
    }
};