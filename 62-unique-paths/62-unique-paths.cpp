class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,0));
        dp[m-1][n-1] = 1;
        
        if(m-2>=0)
            dp[m-2][n-1] = 1;
        if(n-2>=0)
            dp[m-1][n-2] = 1;
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int cnt=0;
                if(dp[i][j]==1)
                    continue;
                if(j+1<=n-1)
                    cnt+=dp[i][j+1];
                if(i+1<=m-1)
                    cnt+=dp[i+1][j];
                
                dp[i][j] = cnt;
            }
        }
        
        return dp[0][0];
    }
};