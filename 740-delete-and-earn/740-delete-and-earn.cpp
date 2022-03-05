class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
      int maxi = *max_element(nums.begin(),nums.end());    
        // cout<<maxi;
      vector<int> dp(maxi+2);
      vector<int> freq(maxi+2);
        
      for(auto it:nums)
          freq[it]++;
        
       dp[1] = freq[1];
       dp[2] = max(freq[2]*2,dp[1]);
        
       for(int j =3;j<=maxi;j++)
          dp[j] = max(dp[j-2]+j*freq[j],dp[j-1]);  
        
        return dp[maxi];
    }
};