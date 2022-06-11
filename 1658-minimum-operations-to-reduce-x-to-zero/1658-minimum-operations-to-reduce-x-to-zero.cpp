class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int prefixsum=0,suffixsum=0;
        int ans=INT_MAX;
        unordered_map<int,int> m;
        
        for(int i=0;i<n;i++){
            prefixsum+=nums[i];
            m[prefixsum]=i+1;
            if(prefixsum==x){
                ans=min(ans,i+1);
            }
        }
        
        for(int i=n-1;i>=0;i--){
            suffixsum+=nums[i];
            if(suffixsum==x){
                ans=min(ans,n-i);
            }
            if(m[x-suffixsum]>0 && i+1>m[x-suffixsum]){
                ans=min(ans,n-i+m[x-suffixsum]);
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};