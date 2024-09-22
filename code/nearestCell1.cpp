#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
// #define via vector<int> []
#define qi queue<int>
#define qp queue<pair<int, int>>
#define qpf queue<pair<pair<int, int>, int>>

#define pb push_back
#define ff front().first
#define fff front().first.first
#define ffs front().first.second
#define fs front().second

class Solution{
 public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size();
	    int m = grid[0].size();
	    
	   // frst step to create visited and dist 
	   vector<vector<int>> visited(n,vector<int>(m,0));
	   vector<vector<int>> dist(n,vector<int>(m,0));
	   
	   queue<pair<pair<int,int>,int>> q;
	   
	   //now assign all the ones to distance 0 and mark them viisted
	   for(int i=0;i<n;i++){
	       for(int j=0;j<m;j++){
	           if(grid[i][j]==1){
	               visited[i][j]=1;
	               dist[i][j]=0;
	               q.push({{i,j},0});
	           }
	       }
	   }

	   int delrow[]={-1,0,1,0};
	   int delcol[]={0,1,0,-1};
	   
	   //now use bfs for get queu
	   //int distance = 0;
	   while(!q.empty()){
	       int row=q.front().first.first;
	       int col= q.front().first.second;
	       int d =q.front().second;
	       
	       q.pop();
	       
	       //so far i have it takes to reach that certain row and col so store it
	       dist[row][col]=d;
	       
	       //ṇow traverse all neighbours 
	       for(int i=0;i<4;i++){
	           int nrow = row+delrow[i];
	           int ncol = col+delcol[i];
	           
	           if(nrow<n && nrow>=0 && ncol<m && ncol>=0 
	           && !visited[nrow][ncol]){
	               visited[nrow][ncol]=1;
	               q.push({{nrow, ncol},d+1});
	           }
	       }
	       
	   }
	   return dist;
	}


	};


int main(){
        Solution solution;
        vector<vector<int>> grid= {{1,0,1},{1,1,0},{1,0,0}};
        int V=4,E=2;
        vector<vector<int>> ans = solution.nearest(grid);
        for(auto it: ans){
        	for(auto neighbour: it){
        		cout<<neighbour<<" ";
        	}
        	cout<<"\n";
        }
        return 0;
}