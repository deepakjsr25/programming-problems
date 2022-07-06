class Solution {
public:
    int row;
    int col;
    int minPathSum(vector<vector<int>>& grid) {
        row=grid.size();
        col=grid[0].size();
        vector<vector<int>> dp(row,vector<int> (col,-1));
        return cal(grid,dp,0,0);
    }
    
    int cal(vector<vector<int>>& grid,vector<vector<int>>& dp,int i,int j){
        if(i<0 || j<0 || i>=row || j>=col){
            return INT_MAX;
        }
        
        if(i==row-1 && j==col-1){
            return grid[i][j];
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        return dp[i][j]=grid[i][j]+max(0,min(cal(grid,dp,i+1,j),cal(grid,dp,i,j+1)));
    }
};