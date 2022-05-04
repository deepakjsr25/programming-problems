class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int cnt=0;
        for(auto it:nums){
            if(m[k-it]){
                cnt++;
                m[k-it]--;
            }
            else{
                m[it]++;
            }
            
        }
        
        return cnt;
    }
};