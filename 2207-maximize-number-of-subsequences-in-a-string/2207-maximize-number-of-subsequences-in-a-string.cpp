class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long long n=text.size();
        vector<vector<long long>> dp(3,vector<long long> (n+1,0));
        
        for(long long i=0;i<n+1;i++){
            dp[0][i]=1;
        }
        
        long long ct1=0,ct2=0;
        for(long long i=0;i<n;i++){
            if(text[i]==pattern[0]){
                ct1++;
            }
            if(text[i]==pattern[1]){
                ct2++;
            }
        }
        
        for(long long i=1;i<=2;i++){
            for(long long j=1;j<=n;j++){
                if(text[j-1]==pattern[i-1]){
                    dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
                }
                else{
                    dp[i][j]=dp[i][j-1];
                }
                // cout<<i<<" "<<j<<endl;
            }
        }
        
        long long maxi=0;
        // cout<<ct1<<" "<<ct2<<endl;
        if(pattern[0]!=pattern[1]){
            maxi=max(ct2,ct1);
        }
        else{
            long long zer0=0;
            maxi=max(zer0,ct1);
        }
        // cout<<dp[2][n];
        
        maxi+=dp[2][n];
        return maxi;
    }
};