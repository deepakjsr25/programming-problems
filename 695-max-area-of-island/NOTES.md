class Solution {
public:
// int maxarea(int, int,vector<vector<int>>& );
int maxAreaOfIsland(vector<vector<int>>& grid) {
int n = grid.size();
int m = grid[0].size();
int maxi=0;
for(int i =0;i<n;i++)
{
for(int j =0;j<m;j++)
{
if(grid[i][j]==1)
maxi=max(maxarea(i,j,grid),maxi);
}
}
return maxi;
}
int maxarea(int i , int j ,vector<vector<int>>& grid)
{
if(i<0 || i>grid.size()-1 || j<0 || j>grid[0].size()-1)
return 0;
if(grid[i][j] == 0)
return 0;
grid[i][j]=0;
return 1+(maxarea(i-1,j,grid) + maxarea(i,j-1,grid) + maxarea(i,j+1,grid) + maxarea(i+1,j,grid));