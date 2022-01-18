class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        map<int,int> m;
        sort(nums.begin(),nums.end());
        ans.push_back(v);
        subset(nums,ans,v,0,nums.size());
        
        return ans;
    }
    
    void subset(vector<int>& nums,vector<vector<int>>& ans,vector<int> v,int i,int n){
        if(i==n){
            return;
        }
       
        int begin=i;
        while(begin<n){
            if(begin==i || (nums[begin]!=nums[begin-1])){
                v.push_back(nums[begin]);
                ans.push_back(v);
                subset(nums,ans,v,begin+1,n);
                v.pop_back();
            }
            begin++;
        }
        
        return;
    }
};