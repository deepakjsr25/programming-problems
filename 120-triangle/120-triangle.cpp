class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int sum=0;
        int n=t.size();
        
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<t[i].size();j++){
                t[i][j]+=min(t[i+1][j],t[i+1][j+1]);
            }
        }
        
        return t[0][0];
    }
    
//     int minimum(vector<vector<int>>& t,int i,int j,int row,int col,vector<vector<int>>& dp){
//         if(i>=row){
//             return 0; 
//         }
        
//         if(dp[i][j]!=20000000){
//             return dp[i][j];
//         }
        
//         return dp[i][j]=t[i][j]+min(minimum(t,i+1,j,row,col,dp),minimum(t,i+1,j+1,row,col,dp));
//     }
};