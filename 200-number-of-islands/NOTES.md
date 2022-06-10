class Solution {
public:
int numIslands(vector<vector<char>>& grid) {
int rows=grid.size();
int cols=grid[0].size();
vector<vector<int>> vis(rows,vector<int> (cols,0));
int cnt=0;
for(int i=0;i<rows;i++){
for(int j=0;j<cols;j++){
if(vis[i][j]==0 && grid[i][j]=='1'){
cnt++;
dfs(grid,vis,i,j,rows,cols);
}
}
}
return cnt;
}
void dfs(vector<vector<char>>& grid,vector<vector<int>>& vis,int i,int j,int rows,int cols){
if(i<0 || j<0 || i>rows-1 || j>cols-1){
return;
}
if(grid[i][j]=='0'){
return;
}
if(vis[i][j]==1){
return;
}
vis[i][j]=1;
dfs(grid,vis,i-1,j,rows,cols);
dfs(grid,vis,i,j-1,rows,cols);
dfs(grid,vis,i+1,j,rows,cols);
dfs(grid,vis,i,j+1,rows,cols);
return;
}
};