class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size()==0 ||nums.size()==1)
            return false;
        
        unordered_map<int, int>mp;
        // mp.insert({nums[0], 0});
        
        for(int i=0; i<nums.size(); i++){
            if(mp.find(nums[i])!=mp.end() && abs(i+1-mp[nums[i]])<=k){
                return true;
            }
            
            mp[nums[i]]=i+1;
            
        }
        
        return false;

    }
};

 
