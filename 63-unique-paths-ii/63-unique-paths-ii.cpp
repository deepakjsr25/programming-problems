class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]){
            return 0;
        }
        
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        return uniquepaths(0,0,obstacleGrid,m,n,dp);
    }
    
    int uniquepaths(int i,int j,vector<vector<int>> obstacleGrid,int m,int n,vector<vector<int>>& dp){
        if(i==m-1 && j==n-1){
            return dp[i][j]=1;
        }
        
        if(i==m || j==n){
            return 0;
        }
        
        if(dp[i][j]!=-1){
           return dp[i][j];
        }
        
        if(!obstacleGrid[i][j]){
            obstacleGrid[i][j]=1;
            return dp[i][j] = uniquepaths(i+1,j,obstacleGrid,m,n,dp) + uniquepaths(i,j+1,obstacleGrid,m,n,dp);
        }
        
        return dp[i][j] = 0;
    }
};