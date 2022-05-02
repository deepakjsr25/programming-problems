class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans;
        for(auto it:nums){
            if(it%2==0){
                ans.insert(ans.begin(),it);
            }
            else{
                ans.push_back(it);
            }
        }
        
        return ans;
    }
};