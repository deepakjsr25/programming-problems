class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>n){
            k=k%n;
        }
        
        reverse(nums.begin(),nums.end());
        std::rotate(nums.begin(), nums.begin() + k , nums.end());
        reverse(nums.begin(),nums.end());
        // while(k--){
        //     std::rotate(nums.begin(), nums.begin() + n-1 , nums.end());
        // }
    }
};