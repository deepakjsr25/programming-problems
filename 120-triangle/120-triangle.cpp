class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int sum=0;
        int row=t.size(),col=t[row-1].size();
        vector<vector<int>> dp(row,vector<int> (col,20000000));
        return minimum(t,0,0,row,col,dp);
    }
    
    int minimum(vector<vector<int>>& t,int i,int j,int row,int col,vector<vector<int>>& dp){
        if(i>=row){
            return 0; 
        }
        
        if(dp[i][j]!=20000000){
            return dp[i][j];
        }
        
        return dp[i][j]=t[i][j]+min(minimum(t,i+1,j,row,col,dp),minimum(t,i+1,j+1,row,col,dp));
    }
};