#include <bits/stdc++.h>
using namespace std;
/*
1942. The Number of the Smallest Unoccupied Chair
Solved
Medium
Topics
Companies
Hint
There is a party where n friends numbered from 0 to n - 1 are attending. There is an infinite number of chairs in this party that are numbered from 0 to infinity. When a friend arrives at the party, they sit on the unoccupied chair with the smallest number.

For example, if chairs 0, 1, and 5 are occupied when a friend comes, they will sit on chair number 2.
When a friend leaves the party, their chair becomes unoccupied at the moment they leave. If another friend arrives at that same moment, they can sit in that chair.

You are given a 0-indexed 2D integer array times where times[i] = [arrivali, leavingi], indicating the arrival and leaving times of the ith friend respectively, and an integer targetFriend. All arrival times are distinct.

Return the chair number that the friend numbered targetFriend will sit on.



Example 1:

Input: times = [[1,4],[2,3],[4,6]], targetFriend = 1
Output: 1
Explanation:
- Friend 0 arrives at time 1 and sits on chair 0.
- Friend 1 arrives at time 2 and sits on chair 1.
- Friend 1 leaves at time 3 and chair 1 becomes empty.
- Friend 0 leaves at time 4 and chair 0 becomes empty.
- Friend 2 arrives at time 4 and sits on chair 0.
Since friend 1 sat on chair 1, we return 1.
Example 2:

Input: times = [[3,10],[1,5],[2,6]], targetFriend = 0
Output: 2
Explanation:
- Friend 1 arrives at time 1 and sits on chair 0.
- Friend 2 arrives at time 2 and sits on chair 1.
- Friend 0 arrives at time 3 and sits on chair 2.
- Friend 1 leaves at time 5 and chair 0 becomes empty.
- Friend 2 leaves at time 6 and chair 1 becomes empty.
- Friend 0 leaves at time 10 and chair 2 becomes empty.
Since friend 0 sat on chair 2, we return 2.
*/
// optimal

class Solution
{
public:
    typedef pair<int, int> P;
    int smallestChair(vector<vector<int>> &times, int targetFriend)
    {

        int targetFriendarrivalTime = times[targetFriend][0];
        sort(
            times.begin(), times.end(), [&](auto first, auto second)
            { return first[0] < second[0]; });

        int n = times.size();

        priority_queue<P, vector<P>, greater<P>> occupied;
        int currentChair = 0;
        priority_queue<int, vector<int>, greater<int>> availableChair;

        for (auto time : times)
        {
            int arrivalTime = time[0];
            int departTime = time[1];

            while (!occupied.empty() && occupied.top().first <= arrivalTime)
            {
                availableChair.push(occupied.top().second);
                occupied.pop();
            }

            if (!availableChair.empty())
            {
                int chair = availableChair.top();
                availableChair.pop();
                if (arrivalTime == targetFriendarrivalTime)
                    return chair;
                occupied.push(make_pair(departTime, chair));
            }
            else
            {
                occupied.push(make_pair(departTime, currentChair));
                if (arrivalTime == targetFriendarrivalTime)
                    return currentChair;
                currentChair++;
            }
        }
        return 0;
    }
};

// brute force

class Solution
{
public:
    int smallestChair(vector<vector<int>> &times, int targetFriend)
    {

        int targetFriendarrivalTime = times[targetFriend][0];
        sort(
            times.begin(), times.end(), [&](auto first, auto second)
            { return first[0] < second[0]; });

        int n = times.size();
        vector<int> arrival(n, -1);
        for (auto time : times)
        {
            int arrivalTime = time[0];
            int depart = time[1];

            for (int i = 0; i < n; i++)
            {
                if (arrival[i] <= arrivalTime)
                {
                    arrival[i] = depart;

                    if (arrivalTime == targetFriendarrivalTime)
                        return i;

                    break;
                }
            }
        }
        return 0;
    }
};