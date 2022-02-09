class Solution {
public:
    bool isMatch(string s, string p) {
        int len1 = s.length(); //7
        int len2 = p.length();//2
        vector<vector<int>> dp(len2+1,vector<int> (len1+1,0));
        
        dp[len2][len1]=1;
        
        for(int j=len1-1;j>=0;j--){
            dp[len2][j]=0;                     // last row
        }
        
        for(int i=len2-1;i>=0;i--){            // last column
            if(p[i] == '*'){
                dp[i][len1] = dp[i+1][len1];                
            } 
            else dp[i][len1] = 0;
        }    
        
        
        for(int i=len2-1;i>=0;i--){
            for(int j=len1-1;j>=0;j--){
                if((p[i]==s[j] || p[i]=='?')&& dp[i+1][j+1]){
                    dp[i][j]=1;
                }
                if(p[i]=='*' && (dp[i][j+1] || dp[i+1][j])){
                    dp[i][j]=1;
                }
            }
        }
        
        return dp[0][0];
    }
};