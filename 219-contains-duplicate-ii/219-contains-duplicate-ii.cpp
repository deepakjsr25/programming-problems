class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k==0){
            return false;
        }
        
        int n=nums.size();
        int i=0;
        unordered_map<int,int> m;
        
        while(i<n){
            if(m[nums[i]]){
                if(i+1-m[nums[i]]<=k){
                    cout<<i;
                    return true;
                }
            }
            m[nums[i]]=i+1;
            i++;
        }
        
        return false;
    }
};