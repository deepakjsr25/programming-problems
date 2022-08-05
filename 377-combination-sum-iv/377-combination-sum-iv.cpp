class Solution {
public:
    int n;
    int combinationSum4(vector<int>& nums, int target) {
        n=nums.size();
        vector<int> dp(target+1,-1);
        
        // sort(nums.begin(),nums.end());
        return tt(nums,target,dp);
    }
    
    int tt(vector<int> nums,int target,vector<int>& dp){
        if(target==0){
            return 1;
        }
        
        if(target<0){
            return 0;
        }
        
        if(dp[target]!=-1){
            return dp[target];
        }
        
        int cnt=0;
        for(int j=0;j<n;j++){
            cnt+=tt(nums,target-nums[j],dp);
        }
        
        return dp[target]=cnt;
    }
};