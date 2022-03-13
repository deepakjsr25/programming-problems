class Solution {
public:
    int maximumTop(vector<int>& nums, int K ){
        if(nums.size() == 1 and K&1) return -1 ;
        if(!K) return nums[0] ;
        if(K > nums.size()) return *max_element(begin(nums),end(nums));
        //cant keep the (k-1)th element at the top 
        int a = K!=1 ? *max_element(begin(nums),begin(nums) + K - 1) : nums[K] ; 
        int b = (K < nums.size() ? nums[K] : INT_MIN) ;
        return max(a,b) ;
    }
};