class Solution {
public:
    bool isMatch(string s, string p) {
        int len1 = s.length();
        int len2 = p.length();
        vector<vector<int>> dp(len1+1,vector<int> (len2,-1));
              
        return (matchexp(0,0,s,p,dp));
    }
    
    bool matchexp(int start,int from,string s,string p,vector<vector<int>>& dp)//0,0
    {
        int len1 = s.length();
        int len2 = p.length();
        if(start>=len1 and from>=len2)//00
            return 1;
        
        if(from>=len2)//0
            return 0;
        
        // if(start>=len1)
        //     return 0;
        
        if(dp[start][from] != -1)
            return dp[start][from];
        
        bool match = (start<len1 && ((s[start]==p[from]) || (p[from] == '.')));//1 
        if(from+1<len2 && p[from+1]=='*') //1<2 && 1
        {
            dp[start][from] = matchexp(start,from+2,s,p,dp) || (match && matchexp(start+1,from,s,p,dp));
            return dp[start][from];
        }
        
        if(match)
        {
             dp[start][from] = matchexp(start+1,from+1,s,p,dp);
             return dp[start][from]; 
        }
        
        dp[start][from] = 0;
        return 0;
    }
};