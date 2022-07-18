class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> winsum;
        int p = 0, q = k, sum = accumulate(nums.begin(),nums.begin()+k,0);
        winsum.push_back(sum);
        int n = nums.size();
        while(q < n) {
            sum -= nums[p++];
            sum += nums[q++];
            winsum.push_back(sum);
        }
        int m = winsum.size();

        int dp[(int)(2e4+1)][4][2];
		// dp[i][j][0] represents maximum sum of j non-overlapping subarrays in nums[i...n-1] given first subarray begins at nums[i]
		// dp[i][j][1] represents maximum sum of j non-overlapping subarrays in nums[i...n-1] given first subarray does not begin at nums[i]
        
        for(int i = m; i >= 0; i--) {
            for(int j = 0; j <= 3; j++) {
                if(j == 0 or i == m) dp[i][j][0] = dp[i][j][1] = 0;
                else {
                    dp[i][j][0] = i+k < m?winsum[i]+max(dp[i+k][j-1][0],dp[i+k][j-1][1]):j-1 == 0?winsum[i]:0;
                    dp[i][j][1] = max(dp[i+1][j][0],dp[i+1][j][1]);
                }
            }
        }
        
        // cout << max(dp[0][3][0],dp[0][3][1]) << endl;
        
        vector<int> res;
        int cnt = 3;
        for(int i = 0; i < winsum.size() and cnt > 0; i++) {
            if(dp[i][cnt][0] >= dp[i][cnt][1]) {
                res.push_back(i);
                cnt--; i += k-1;
            }
        }
        
        return res;
    }
};