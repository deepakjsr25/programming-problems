class Solution {
public:
int subarraySum(vector<int>& nums, int k) {
int n = nums.size();
int currentsum = 0;
int cnt =0;
unordered_map<int,int> m;
for(int i =0;i<n;i++)
{
currentsum+=nums[i];
if(currentsum==k)
cnt+=1;
if(m[currentsum-k]!=0)
cnt+=m[currentsum-k];
++m[currentsum];
}
return cnt;
}
};