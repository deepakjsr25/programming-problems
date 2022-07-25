class Solution {
public:
vector<int> searchRange(vector<int>& nums, int target) {
int n=nums.size();
int st=0,lt=n-1,mid;
int prev=(st+lt)/2;
while(st<=lt){
mid=(st+lt)/2;
if(target<=nums[mid]){
prev=mid;
lt=mid-1;
}
else{
st=mid+1;
}
}
// cout<<prev<<endl;
vector<int> ans;
if(n==0 || nums[prev]!=target){
ans.push_back(-1);
ans.push_back(-1);
return ans;
}
ans.push_back(prev);
st=0,lt=n-1;
while(st<=lt){
mid=(st+lt)/2;
if(target>=nums[mid]){
prev=mid;
st=mid+1;
}
else{
lt=mid-1;
}
}
ans.push_back(prev);
return ans;
}
};