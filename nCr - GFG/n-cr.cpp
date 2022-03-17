// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int nCr(int n, int r){
        // code here
        vector<vector<long long>> dp(n+1,vector<long long> (n+1,-1));
        return func(n,r,dp);
    }
    
    long long func(int n, int r, vector<vector<long long>> &dp){
    if(n<r){
            return dp[n][r]=0;
        }
        
        if(r==0){
            return dp[n][r]=1;
        }
        
        if(dp[n][r]!=-1){
            return dp[n][r];
        }
        
        return dp[n][r]=(func(n-1,r-1,dp)+func(n-1,r,dp))%(1000000000+7);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends