class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<vector<int>> dp(row,vector<int> (col,-1));
        int maxi=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                maxi=max(maxi,lip(matrix,row,col,i,j,INT_MIN,dp));
            }
        }
        return maxi;
    }
    
    int lip(vector<vector<int>>& matrix,int row,int col,int i,int j,int prev,vector<vector<int>>& dp){
        if(i<0 || j<0 || i>=row || j>=col || matrix[i][j]<=prev){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int dir[4][2]={{-1,0},{0,1},{0,-1},{1,0}};
        int maxi=0;
        for(auto d:dir){
            maxi=max(maxi,1+lip(matrix,row,col,i+d[0],j+d[1],matrix[i][j],dp));
        }
        
        return dp[i][j]=maxi;
    }
};