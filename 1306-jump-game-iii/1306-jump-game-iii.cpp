class Solution {
public:
    int n;
    bool canReach(vector<int>& arr, int start) {
        n=arr.size();
        vector<int> dp(n,-1);
        
        return canorcannot(arr,start, dp);
    }
    
    bool canorcannot(vector<int>& arr, int start, vector<int>& dp){
        if(start<0 || start>n-1 || arr[start]==-1){
            return 0;
        }
        
        if(arr[start]==0){
            return 1;
        }
        
        if(dp[start]!=-1){
            return dp[start];
        }
        
        int temp=arr[start];
        arr[start]=-1;
        return dp[start]=canorcannot(arr,start+temp, dp) || canorcannot(arr,start-temp, dp);
    }
};