class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int mini=n+1;
        int i=0,j=0;
        while(i<n){
            sum+=nums[i];
            while(sum>=target && j<=i){
                mini=min(i-j+1,mini);
                sum-=nums[j];
                j++;
            }
            i++;
        }
        
        if(mini==(n+1)){
            return 0; 
        }
        
        return mini;
    }
};