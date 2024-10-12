#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    vector<int> nextSmaller(vector<int> &arr, int n)
    {
        stack<int> s;
        vector<int> ans(n, n);

        for (int i = 0; i < n; i++)
        {

            while (!s.empty() && arr[i] < arr[s.top()])
            {
                ans[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }

        return ans;
    }

    vector<int> prevSmaller(vector<int> &arr, int n)
    {
        stack<int> s;
        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && arr[i] <= arr[s.top()])
            {
                s.pop();
            }
            if (!s.empty())
                ans[i] = s.top();

            s.push(i);
        }

        return ans;
    }

public:
    int largestRectangleArea(vector<int> &heights)
    {

        int n = heights.size();

        vector<int> next = nextSmaller(heights, n);

        vector<int> prev = prevSmaller(heights, n);

        int area = 0;
        for (int i = 0; i < n; i++)
        {
            int l = heights[i];
            int b = next[i] - prev[i] - 1;

            int newArea = l * b;

            area = max(area, newArea);
        }

        return area;
    }

    int aa(vector<int> &heightHistogram)
    {
        int n = heightHistogram.size();
        int _maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            int minHeight = INT_MAX;

            for (int j = i; j < n; j++)
            {
                minHeight = min(minHeight, heightHistogram[j]);
                _maxArea = max(_maxArea, minHeight * (j - i + 1));
            }
        }
        return _maxArea;
    }
};
