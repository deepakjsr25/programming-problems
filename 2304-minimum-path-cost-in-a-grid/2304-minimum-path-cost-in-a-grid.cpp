class Solution {
public:
    int row;
    int col;
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& mc) {
        row=grid.size();
        col=grid[0].size();
        vector<vector<int>> dp(row,vector<int> (col,-1));
        
        int mini=INT_MAX;
        for(int k=0;k<col;k++){
            mini=min(mini,cal(grid,mc,dp,0,k));
        }
        
        return mini;
    }
    
    int cal(vector<vector<int>>& grid,vector<vector<int>>& mc, vector<vector<int>>& dp,int i,int j){
        if(j>col-1){
            return INT_MAX;
        }
        
        if(i==row-1){
            return grid[i][j];
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        // int mini=INT_MAX;
        // for(int k=0;k<col;k++){
        //     mini=min(mini,cal(grid,mc,dp,0,0));
        // } 
        
        dp[i][j]=grid[i][j];
        int mini=INT_MAX;
        for(int k=0;k<col;k++){
            mini=min(mini,mc[grid[i][j]][k]+cal(grid,mc,dp,i+1,k));
        } 
        dp[i][j]+=mini;
        return dp[i][j];
    }
};