class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int swap=1;
        
        for(int i=0;i<n;i++){
            if(nums[i]<=0){
                continue;
            }
            
            if(nums[i]<=n && nums[i]!=i+1){
                int temp=nums[nums[i]-1];
                if(nums[nums[i]-1]!=nums[i]){
                    nums[nums[i]-1]=nums[i];
                    nums[i]=temp;
                    i--;
                }
                
                // if(nums[nums[i]-1]!=nums[i]){
                    // i--;
                // }
            }
        }
        
        
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        
        return n+1;
    }
};