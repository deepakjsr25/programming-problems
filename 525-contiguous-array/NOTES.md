int n = nums.size();
vector<int> v(n+1,0);
unordered_map<int,int> m;
v[1]=nums[0]?1:0;
m[v[1]]=1;
for(int i=1;i<n;i++){
if(nums[i]==0){
v[i+1]=v[i]-1;
}
else{
v[i+1]=v[i]+1;
}
if(m[v[i+1]]==0){
m[v[i+1]]=i+1;
}
else{
}
}
​
return 0;