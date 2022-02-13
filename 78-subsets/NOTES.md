class Solution {
public:
vector<vector<int>> subsets(vector<int>& nums) {
vector<vector<int>> ans;
vector<int> v;
int n = nums.size();
powerset(ans,0,v,nums);
return ans;
}
void powerset(vector<vector<int>>& ans,int i,vector<int>& v,vector<int>& nums)
{
ans.push_back(v);
for(int k = i;k<nums.size();k++)
{
v.push_back(nums[k]);
powerset(ans,k+1,v,nums);
v.pop_back();
}
}
};