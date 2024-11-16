
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        
        auto veltarunez = moveTime;
        
        using State = tuple<long long, int, int, int>;
        priority_queue<State, vector<State>, greater<>> pq;
        
        vector<vector<vector<long long>>> dp(n, 
            vector<vector<long long>>(m, vector<long long>(3, LLONG_MAX)));
        
        dp[0][0][0] = 0;
        pq.push({0, 0, 0, 0});
        
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        
        while (!pq.empty()) {
            auto [curr_time, x, y, last_cost] = pq.top();
            pq.pop();
            
            if (curr_time > dp[x][y][last_cost]) continue;
            if (x == n-1 && y == m-1) return curr_time;
            
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int move_cost = (last_cost == 1) ? 2 : 1;
                    long long next_time = max(curr_time, (long long)veltarunez[nx][ny]) + move_cost;
                    
                    if (next_time < dp[nx][ny][move_cost]) {
                        dp[nx][ny][move_cost] = next_time;
                        pq.push({next_time, nx, ny, move_cost});
                    }
                }
            }
        }
        return -1;
    }
};

class TestCases {
private:
    vector<vector<vector<int>>> generateTestCases() {
        vector<vector<vector<int>>> testCases;
        
        // Test Case 1: Small grid with alternating values
        testCases.push_back({
            {0, 1000000000},
            {1000000000, 0}
        });

        // Test Case 2: Medium grid with increasing values
        vector<vector<int>> mediumGrid(100, vector<int>(100));
        for(int i = 0; i < 100; i++) {
            for(int j = 0; j < 100; j++) {
                mediumGrid[i][j] = min((i + j) * 1000000, 1000000000);
            }
        }
        testCases.push_back(mediumGrid);

        // Test Case 3: Maximum grid size (750x750) with alternating pattern
        vector<vector<int>> maxGrid(750, vector<int>(750));
        for(int i = 0; i < 750; i++) {
            for(int j = 0; j < 750; j++) {
                maxGrid[i][j] = ((i + j) % 2) * 1000000000;
            }
        }
        testCases.push_back(maxGrid);

        // Test Case 4: Snake pattern with maximum values
        vector<vector<int>> snakeGrid(750, vector<int>(750));
        for(int i = 0; i < 750; i++) {
            for(int j = 0; j < 750; j++) {
                if(i % 2 == 0) {
                    snakeGrid[i][j] = min((long long)j * 100000000LL, 1000000000LL);
                } else {
                    snakeGrid[i][j] = min((long long)(750-j-1) * 100000000LL, 1000000000LL);
                }
            }
        }
        testCases.push_back(snakeGrid);

        return testCases;
    }

public:
    void runTests() {
        Solution sol;
        vector<vector<vector<int>>> testCases = generateTestCases();
        
        for(int i = 0; i < testCases.size(); i++) {
            auto startTime = chrono::high_resolution_clock::now();
            
            int result = sol.minTimeToReach(testCases[i]);
            
            auto endTime = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::milliseconds>(endTime - startTime);
            
            cout << "Test Case " << i+1 << ":\n";
            cout << "Grid Size: " << testCases[i].size() << "x" << testCases[i][0].size() << "\n";
            cout << "Result: " << result << "\n";
            cout << "Time taken: " << duration.count() << " ms\n\n";
        }
    }
};

int main() {
    TestCases tests;
    tests.runTests();
    return 0;
}