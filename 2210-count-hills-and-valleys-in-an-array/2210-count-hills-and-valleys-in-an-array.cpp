class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size(),cnt=0;
        // vector<int> ans(n,-1);
        for(int i=1;i<n-1;i++){
            if(nums[i]<nums[i-1]){
                while(i<(n-1) && nums[i]==nums[i+1]){
                    i++;
                }
                if((i+1)<n && nums[i]<nums[i+1]){
                    cnt++;
                }
            }
            else if(nums[i]>nums[i-1]){
                while(i<(n-1) && nums[i]==nums[i+1]){
                    i++;
                }
                if((i+1)<n && nums[i]>nums[i+1]){
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};