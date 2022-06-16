class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        vector<vector<int>> dp(n,vector<int> (n,0));
        
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        
        string st="";
        int maxi=0;
        for(int i=0;i<n-1;i++){
            // cout<<s[i+1]<<endl;
            if(s[i]==s[i+1]){
                // cout<<i<<" "<<endl;
                dp[i][i+1]=2;
                st=s.substr(i,2);
                maxi=2;
            }
        }
        
        for(int i=n-3;i>=0;i--){
            for(int j=n-1;j>i+1;j--){
                // cout<<i<<" "<<endl;
                if(s[i]==s[j] && dp[i+1][j-1]>0){
                    dp[i][j]=dp[i+1][j-1]+2;
                }
                
                if(dp[i][j]>maxi){
                    maxi=dp[i][j];
                    st=s.substr(i,dp[i][j]);
                }
                // cout<<"erroe"<<endl;
            }
        }
        
        if(maxi==0){
            st=s[0];
        }
        
        // cout<<st<<endl;
        return st;
    }
};