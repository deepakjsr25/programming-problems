if(k==0){
return false;
}
int n=nums.size();
int i=0;
unordered_map<int,int> m;
while(i<n){
if(m[nums[i]]){
if(i+1-m[nums[i]]<=k){
return true;
}
}
m[nums[i]]=i+1;
i++;
}
return false;
}