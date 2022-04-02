class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int> (m,-1));
        return func(nums,  0, 0, m, n, dp);
    }
    
    int func(vector<int>& nums, int i, int curr, int m, int n, vector<vector<int>> &dp){
        if(curr==m && i==n){
            return 0;
        }
        
        if(i==n){
            return 100000000;
        }
        
        if(curr>=m){
            return 100000000;
        }
        
        if(dp[i][curr]!=-1){
            return dp[i][curr];
        }
        
        int ans=max(nums[i],func(nums, i+1, curr+1, m, n, dp));
        int sum=nums[i];
        
        for(int j=i+1;j<n;j++){
            sum+=nums[j];
            ans=min(ans,max(sum,func(nums, j+1, curr+1, m, n, dp)));
        }
        
        return dp[i][curr]=ans;
    }
};