class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        // vector<int> v(2*3*(10000)+1,0);
        int temp=nums[0];
        
        for(int i=1;i<n;i++){
            temp=temp^nums[i];
        }
        
        return temp;
    }
};