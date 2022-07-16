class Solution {
public:
    long long mod=1e9 + 7;
    int findPaths(int m, int n, int mm, int sr, int sc) {
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector <int>(mm+1,-1)));
        return cal(m,n,mm,sr,sc,dp)%mod;
    }
    
    int cal(int m, int n, int mm, int sr, int sc, vector<vector<vector<int>>>& dp){
        if(sr<0 || sc<0 || sr>m-1 || sc>n-1){
            return 1;
        }
        
        if(dp[sr][sc][mm]!=-1){
            return dp[sr][sc][mm];
        }
        
        if(mm==0){
            return 0;
        }
        
        // v[sr][sc]=1;
        int cnt=(cal(m,n,mm-1,sr+1,sc,dp)%mod+cal(m,n,mm-1,sr,sc+1,dp)%mod+cal(m,n,mm-1,sr,sc-1,dp)%mod+cal(m,n,mm-1,sr-1,sc,dp)%mod)%mod;
        
        return dp[sr][sc][mm]=cnt;
    }
};