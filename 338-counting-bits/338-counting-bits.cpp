class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1,0);
        // dp[0] = 0;
        for(int i=1;i<=n;i++)
        {
            int temp = i;
            int cnt = 0;
            
                if(temp&1 == 1)
                    cnt++;
                temp=temp>>1;
                cnt+=dp[temp];
            
            dp[i] = cnt;
        }
        return dp;
    }
};