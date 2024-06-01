#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
// #define via vector<int> []
#define qi queue<int>
#define qp queue<pair<int, int>>
#define qpf queue<pair<pair<int, int>, int>>

#define pb push_back
#define ff front().first
#define fff front().first.first
#define ffs front().first.second
#define fs front().second

class Solution
{
public:
	static int numberofEnclaves(vvi &grid){
		int n = grid.size();
		int m = grid[0].size();

		vvi visited(n,vi(m,0));
		qp q;
		for(int i=0;i<n;i++){
			for(int j =0;j<m;j++){
                // either first/last row or col
                if(i==0 || j ==0 || i == n-1 || j == m-1){
                    if(grid[i][j]==1){
                        visited[i][j]=1;
                        q.push({i,j});
                    }
                }
            }
		}

		 int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            
            q.pop();
            
            // get neighbours
            for(int i=0;i<4;i++){
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];
                
                if(nrow <n && nrow >=0 && ncol <m && ncol>=0 
                && !visited[nrow][ncol] && grid[nrow][ncol]==1) {
                    q.push({nrow, ncol});
                    visited[nrow][ncol]=1;
                    
                }
            }
        }

        // now final get the count
        int cnt=0;
        
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                
                if(!visited[i][j] && grid[i][j]==1){
                    cnt++;
                }
            }
        }
        
        return cnt;
	}
};


int main()
{
    int n = 5, m = 4;
    vvi grid = {{0, 0, 0, 0},
            {1, 0, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}};

    int (*pregionProblem)(vvi &);
    pregionProblem = Solution::numberofEnclaves;
    int output = (*pregionProblem)(grid);
    // for (auto it : output)
    // {
    //     for (auto neighbour : it)
    //     {
    //         cout << "'" << neighbour << "' ";
    //     }
    //     cout << "\n";
    // }
    cout<<output<<" ";
    return 0;
}