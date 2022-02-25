class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int max_prod=(nums[0]-1)*(nums[1]-1);
        if(n==2){
            return max_prod;
        }
        
        int maxi;
        if(nums[0]>nums[1]){
            maxi=0;
        }
        else{
            maxi=1;
        }
        
        for(int i=2;i<n;i++){
            max_prod=max(max_prod,((nums[i]-1)*(nums[maxi]-1)));
            if(nums[i]>nums[maxi]){
                maxi=i;
            }
        }
        
        return max_prod;
    }
};