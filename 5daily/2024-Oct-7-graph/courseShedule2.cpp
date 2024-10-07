#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> topologicalSortCheck(unordered_map<int, vector<int>> &graph, int n, vector<int> &indegree)
    {
        queue<int> que;
        vector<int> result;
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                que.push(i);
                count++;
                result.push_back(i);
            }
        }

        while (!que.empty())
        {
            int frontNode = que.front();
            que.pop();

            for (int &neighbour : graph[frontNode])
            {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0)
                {
                    que.push(neighbour);
                    count++;
                    result.push_back(neighbour);
                }
            }
        }

        if (count == n)
            return result;

        return {};
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &input)
    {
        unordered_map<int, vector<int>> graph;
        vector<int> indegree(numCourses, 0);
        for (auto node : input)
        {
            int independentNode = node[1];
            int dependentNode = node[0];

            // link bnega inde,depen
            graph[independentNode].push_back(dependentNode);

            indegree[dependentNode]++;
        }

        return topologicalSortCheck(graph, numCourses, indegree);
    }
};
/*class Solution {
public:
    bool dfs(int node, unordered_map<int, vector<int>>& graph, vector<int>& visited, vector<int>& result) {
        // If the node is in the current recursion stack, cycle detected
        if (visited[node] == 1) return false;
        // If already visited (fully processed), return true
        if (visited[node] == 2) return true;

        // Mark the node as part of the current recursion stack
        visited[node] = 1;

        // Explore all neighbors
        for (int neighbor : graph[node]) {
            if (!dfs(neighbor, graph, visited, result)) {
                return false;  // Cycle detected
            }
        }

        // Mark as fully processed
        visited[node] = 2;
        result.push_back(node);  // Add node to the result as all its dependencies are resolved

        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<int> visited(numCourses, 0);  // 0 = unvisited, 1 = visiting, 2 = fully processed
        vector<int> result;

        // Build the adjacency list for the graph
        for (auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
        }

        // Perform DFS from each unvisited node
        for (int i = 0; i < numCourses; ++i) {
            if (visited[i] == 0) {
                if (!dfs(i, graph, visited, result)) {
                    return {};  // Cycle detected, no valid order
                }
            }
        }

        reverse(result.begin(), result.end());  // Topologically sorted order
        return result;
    }
};

*/

class Solution
{
private:
    void dfs(unordered_map<int, vector<int>> &graph, int node,
             vector<bool> &visited, stack<int> &st, vector<bool> &inRecursion)
    {
        visited[node] = true;
        inRecursion[node] = true;

        for (auto &child : graph[node])
        {
            if (inRecursion[child])
            {
                hasCycle = true;
                return;
            }

            if (!visited[child])
            {
                dfs(graph, child, visited, st, inRecursion);
            }
        }

        st.push(node);
        inRecursion[node] = false;
    }

public:
    bool hasCycle;
    vector<int> findOrder(int numCourses, vector<vector<int>> &input)
    {
        unordered_map<int, vector<int>> graph;
        vector<bool> visited(numCourses, false);
        vector<bool> inRecursion(numCourses, false);

        for (auto &vec : input)
        {
            int a = vec[0];
            int b = vec[1];

            graph[b].push_back(a);
        }

        // get the stack to store
        hasCycle = false;
        stack<int> st;
        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i])
                dfs(graph, i, visited, st, inRecursion);

            if (hasCycle)
                return {};
        }

        vector<int> result;
        while (!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};
/*
class Solution {
private:
    vector<int> topologicalSortCheck(unordered_map<int, vector<int>> &graph,
int n, vector<int> &indegree){ queue<int> que; vector<int> result; int count
= 0;

        for(int i=0;i<n;i++){
            if(indegree[i]==0) {
                que.push(i);
                count++;
                result.push_back(i);
            }
        }


        while(!que.empty()){
            int frontNode = que.front();
            que.pop();

            for(int &neighbour: graph[frontNode]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    que.push(neighbour);
                    count++;
                    result.push_back(neighbour);
                }
            }
        }

        if(count == n) return result;

        return {};
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& input) {
        unordered_map<int, vector<int>> graph;
        vector<int> indegree(numCourses, 0);
        for (auto node : input) {
            int independentNode = node[1];
            int dependentNode = node[0];

            // link bnega inde,depen
            graph[independentNode].push_back(dependentNode);

            indegree[dependentNode]++;
        }

        return topologicalSortCheck(graph, numCourses, indegree);
    }
};

*/