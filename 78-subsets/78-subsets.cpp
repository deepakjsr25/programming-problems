class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        vector<vector<int>> ans;
        ans.push_back(v);
        subsetfunc(nums,0,ans,v);
        return ans;
    }
    
    void subsetfunc(vector<int>& nums,int i,vector<vector<int>>& ans,vector<int> v){
        if(i==nums.size()){
            return;
        }
        
        for(int j=i;j<nums.size();j++){
            v.push_back(nums[j]);
            ans.push_back(v);
            subsetfunc(nums,j+1,ans,v);
            v.pop_back();
        }
        
        return;
    }
};