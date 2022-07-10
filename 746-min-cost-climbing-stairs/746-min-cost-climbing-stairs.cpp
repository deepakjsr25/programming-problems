class Solution {
public:
    int n;
    int minCostClimbingStairs(vector<int>& cost) {
        n=cost.size();
        vector<int> dp(n,-1);
        
        return min(cal(cost,0,dp),cal(cost,1,dp));
    }
    
    int cal(vector<int>& cost,int i,vector<int>& dp){
        if(i>=n){
            return 0;
        }
        
        if(dp[i]!=-1){
            return dp[i];
        }
        
        return dp[i]=cost[i]+min(cal(cost,i+1,dp),cal(cost,i+2,dp));
    }
};