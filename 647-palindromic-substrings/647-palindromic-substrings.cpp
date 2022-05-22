class Solution {
public:
    int countSubstrings(string s) {
        int len=s.length();
        vector<vector<int>> dp(len+1,vector<int> (len+1,0));
        int count=0;
        
        for(int i=0;i<len;i++){
            dp[i][i]=1;
            count++;
            if(s[i]==s[i+1]){
                dp[i][i+1]=1;
                count++;
            }
        }
        
        for(int i=len-3;i>=0;i--){
            for(int j=len-1;j>=0 && j>i+1;j--){
                if(s[i]==s[j]){
                    dp[i][j]=dp[i+1][j-1];
                }
                
                if(dp[i][j]){
                    count++;
                }
            }
        }
        
        return count;
    }
};