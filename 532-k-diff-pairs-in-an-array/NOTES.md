class Solution {
public:
int findPairs(vector<int>& nums, int k) {
unordered_map<int,int> m;
int n = nums.size();
int cnt = 0;
// vector<vector<int>> ans;
for(int i =0;i<n;i++)
++m[nums[i]];
if(k!=0)
{
for(int i =0;i<n;i++)
if(m[k+nums[i]] != 0)
{
m[k+nums[i]] = 0;
cnt++;
}
}
else if(k==0)
{
for(int i =0;i<n;i++)
if(m[k+nums[i]] > 1)
{
m[k+nums[i]] = 0;
cnt++;
}
}
// ans.push_back(make_pair(nums[i],k+nums[i]));
return cnt;
}
};