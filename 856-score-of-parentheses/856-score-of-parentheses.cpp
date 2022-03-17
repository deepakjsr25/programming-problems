class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.size();
        int cnt=1,curr=0;
        vector<int> dp(n,1);
        
        if(n==2){
            return 1;
        }
        
        for(int i=1;i<n;i++){            
            if(s[i-1]=='(' && s[i-1]==s[i]){
                dp[i]=dp[i-1]*2;
            }
            else if(s[i-1]==')' && s[i-1]!=s[i]){
                if(!cnt){
                    dp[i]=1;
                }
                else{
                    dp[i]=pow(2,cnt);
                }
            }
            else{
                dp[i]=dp[i-1];
            }
            
            if(s[i]=='('){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        
        int sum=0;
        for(int i=0;i<n-1;i++){
            if(s[i]=='(' && s[i+1]==')'){
                sum+=dp[i];
            }
        }
        
        return sum;
    }
};